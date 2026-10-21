"""The README updater changes only aggregate metrics inside its generated section."""

import json
import subprocess
import sys
import tempfile
import unittest
from io import BytesIO
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import tools.update_readme_progress as updater


class ReadmeProgressTests(unittest.TestCase):
    def setUp(self):
        self.project = {"slug": "excite-truck", "kind": "fork", "ready": True,
                       "matched": 6573, "functions": 13780,
                       "matched_bytes": 380964, "bytes": 3050412}

    def test_renders_exact_match_counts_and_percentages(self):
        block = updater.progress_block(self.project)
        self.assertIn("6,573 / 13,780 (47.7%)", block)
        self.assertIn("380,964 / 3,050,412 bytes (12.5%)", block)

    def test_replaces_only_the_marked_section(self):
        before = f"intro\n{updater.START}\nstale\n{updater.END}\nfooter\n"
        after = updater.replace_progress(before, updater.progress_block(self.project))
        self.assertTrue(after.startswith("intro\n"))
        self.assertTrue(after.endswith("\nfooter\n"))
        self.assertNotIn("stale", after)

    def test_refuses_missing_or_repeated_markers(self):
        with self.assertRaises(ValueError):
            updater.replace_progress("no generated block", updater.progress_block(self.project))
        repeated = f"{updater.START}\nx\n{updater.END}\n{updater.START}\ny\n{updater.END}"
        with self.assertRaises(ValueError):
            updater.replace_progress(repeated, updater.progress_block(self.project))

    def test_rejects_impossible_counts(self):
        bad = self.project | {"matched": 20_000}
        with self.assertRaises(ValueError):
            updater.progress_block(bad)

    def test_file_update_is_idempotent_and_preserves_surrounding_text(self):
        with tempfile.TemporaryDirectory() as directory:
            readme = Path(directory) / "README.md"
            readme.write_text(f"intro\n{updater.START}\nstale\n{updater.END}\nfooter\n", encoding="utf-8")
            self.assertTrue(updater.update(readme, self.project))
            first = readme.read_text(encoding="utf-8")
            self.assertFalse(updater.update(readme, self.project))
            self.assertEqual(readme.read_text(encoding="utf-8"), first)
            self.assertTrue(first.startswith("intro\n"))
            self.assertTrue(first.endswith("\nfooter\n"))

    def test_reads_the_named_local_project_from_api(self):
        payload = json.dumps([{"slug": "other"}, self.project]).encode()
        with patch.object(updater, "urlopen", return_value=BytesIO(payload)) as mocked:
            self.assertEqual(updater.live_project(), self.project)
            mocked.assert_called_once()

    def test_live_checkout_commit_uses_container_owned_git_database(self):
        command = updater._commit_command(updater.ROOT, "README.md")
        self.assertEqual(command[:7], ["docker", "exec", "-w", "/data/excite-truck", "decompdecomp", "git", "commit"])
        self.assertIn("--only", command)
        self.assertEqual(command[-1], "README.md")

    def test_auto_commit_contains_only_readme_and_preserves_other_staged_work(self):
        with tempfile.TemporaryDirectory() as directory:
            repo = Path(directory)
            readme = repo / "README.md"
            readme.write_text(f"intro\n{updater.START}\nstale\n{updater.END}\nfooter\n", encoding="utf-8")
            (repo / "tracked.c").write_text("baseline\n", encoding="utf-8")
            self._git(repo, "init", "-q", "-b", "main")
            self._git(repo, "config", "user.name", "Progress Test")
            self._git(repo, "config", "user.email", "progress-test@example.invalid")
            self._git(repo, "add", "README.md", "tracked.c")
            self._git(repo, "commit", "-q", "-m", "baseline")

            readme.write_text(updater.replace_progress(readme.read_text(encoding="utf-8"),
                                                       updater.progress_block(self.project)), encoding="utf-8")
            (repo / "tracked.c").write_text("unfinished change\n", encoding="utf-8")
            self._git(repo, "add", "tracked.c")
            (repo / "untracked.txt").write_text("untracked work\n", encoding="utf-8")

            self.assertTrue(updater.commit_progress(readme, repo))
            committed = self._git(repo, "diff-tree", "--no-commit-id", "--name-only", "-r", "HEAD")
            self.assertEqual(committed.splitlines(), ["README.md"])
            staged = self._git(repo, "diff", "--cached", "--name-only")
            self.assertEqual(staged.splitlines(), ["tracked.c"])
            self.assertTrue((repo / "untracked.txt").exists())

    def test_auto_commit_refuses_non_generated_readme_edits(self):
        with tempfile.TemporaryDirectory() as directory:
            repo = Path(directory)
            readme = repo / "README.md"
            original = f"intro\n{updater.START}\nstale\n{updater.END}\nfooter\n"
            readme.write_text(original, encoding="utf-8")
            self._git(repo, "init", "-q", "-b", "main")
            self._git(repo, "config", "user.name", "Progress Test")
            self._git(repo, "config", "user.email", "progress-test@example.invalid")
            self._git(repo, "add", "README.md")
            self._git(repo, "commit", "-q", "-m", "baseline")
            updated = updater.replace_progress(original, updater.progress_block(self.project))
            readme.write_text(updated.replace("intro", "manual README edit"), encoding="utf-8")

            with self.assertRaisesRegex(RuntimeError, "non-generated edits"):
                updater.commit_progress(readme, repo)

    @staticmethod
    def _git(repo: Path, *args: str) -> str:
        return subprocess.run(["git", "-C", str(repo), *args], check=True, capture_output=True,
                              text=True).stdout


if __name__ == "__main__":
    unittest.main()
