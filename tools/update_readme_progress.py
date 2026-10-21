#!/usr/bin/env python3
"""Refresh README progress locally; optional scheduled mode makes README-only commits."""

from __future__ import annotations

import argparse
import json
import os
import stat
import subprocess
import sys
import tempfile
from pathlib import Path
from urllib.request import urlopen

ROOT = Path(__file__).resolve().parents[1]
README = ROOT / "README.md"
DEFAULT_API = "http://127.0.0.1:6464/api/projects"
PROJECT = "excite-truck"
START = "<!-- BEGIN AUTO-GENERATED PROGRESS -->"
END = "<!-- END AUTO-GENERATED PROGRESS -->"
TIMEOUT_SECONDS = 8
GIT_CONTAINER = "decompdecomp"
CONTAINER_PROJECT = Path("/data/excite-truck")


def live_project() -> dict:
    """Read only aggregate counts from the local decompdecomp instance."""
    try:
        with urlopen(DEFAULT_API, timeout=TIMEOUT_SECONDS) as response:
            projects = json.load(response)
    except (OSError, ValueError) as error:
        raise ValueError("could not read valid JSON from the local API") from error
    if not isinstance(projects, list):
        raise ValueError("the local API did not return a project list")
    project = next((item for item in projects if isinstance(item, dict) and item.get("slug") == PROJECT), None)
    if not project or project.get("kind") != "fork" or not project.get("ready"):
        raise ValueError("the local Excite Truck project is missing or not ready")
    return project


def _integer_metric(project: dict, key: str) -> int:
    try:
        value = project[key]
        if isinstance(value, bool):
            raise ValueError
        return int(value)
    except (KeyError, TypeError, ValueError) as error:
        raise ValueError(f"invalid {key} count in local API response") from error


def progress_block(project: dict) -> str:
    """Render only complete matches and byte counts; attempts and near-matches are not progress."""
    matched, functions = _integer_metric(project, "matched"), _integer_metric(project, "functions")
    matched_bytes = _integer_metric(project, "matched_bytes")
    total_bytes = _integer_metric(project, "bytes")
    if (functions <= 0 or total_bytes <= 0 or matched < 0 or matched > functions
            or matched_bytes < 0 or matched_bytes > total_bytes):
        raise ValueError("the local API returned invalid progress counts")
    return "\n".join((
        START,
        "",
        "| Metric | Current progress |",
        "| :--- | :--- |",
        f"| **Exactly matched functions** | {matched:,} / {functions:,} ({matched / functions:.1%}) |",
        f"| **Exactly matched code** | {matched_bytes:,} / {total_bytes:,} bytes ({matched_bytes / total_bytes:.1%}) |",
        "",
        END,
    ))


def replace_progress(readme: str, block: str) -> str:
    """Replace one marked section and leave every other README byte alone."""
    if readme.count(START) != 1 or readme.count(END) != 1:
        raise ValueError("README must contain exactly one pair of progress markers")
    start, end = readme.index(START), readme.index(END)
    if end < start:
        raise ValueError("README progress markers are out of order")
    end += len(END)
    return readme[:start] + block + readme[end:]


def update(readme_path: Path, project: dict) -> bool:
    """Atomically update only the marked README block."""
    old = readme_path.read_text(encoding="utf-8")
    new = replace_progress(old, progress_block(project))
    if new == old:
        return False
    mode = stat.S_IMODE(readme_path.stat().st_mode)
    temp_name = None
    try:
        with tempfile.NamedTemporaryFile("w", encoding="utf-8", newline="\n", dir=readme_path.parent,
                                         prefix=f".{readme_path.name}.", delete=False) as temp:
            temp_name = temp.name
            temp.write(new)
            temp.flush()
            os.fsync(temp.fileno())
        if readme_path.read_text(encoding="utf-8") != old:
            raise RuntimeError("README changed while progress was being refreshed; try again")
        os.chmod(temp_name, mode)
        os.replace(temp_name, readme_path)
        return True
    finally:
        if temp_name and os.path.exists(temp_name):
            os.unlink(temp_name)


def _git(repo_root: Path, *args: str) -> subprocess.CompletedProcess:
    return subprocess.run(["git", "-C", str(repo_root), *args], capture_output=True, text=True, check=False)


def _commit_command(repo_root: Path, relative: str) -> list[str]:
    args = ["commit", "--only", "-m", "Update Excite Truck README progress", "--", relative]
    if repo_root.resolve() == ROOT.resolve():
        return ["docker", "exec", "-w", str(CONTAINER_PROJECT), GIT_CONTAINER, "git", *args]
    return ["git", "-C", str(repo_root), *args]


def commit_progress(readme_path: Path = README, repo_root: Path = ROOT) -> bool:
    """Commit only a generated progress-block change, and only on main."""
    try:
        relative = readme_path.resolve().relative_to(repo_root.resolve()).as_posix()
    except ValueError as error:
        raise RuntimeError("README must be inside the Excite Truck checkout") from error
    if relative != "README.md":
        raise RuntimeError("automatic commits are restricted to the project README.md")

    branch = _git(repo_root, "branch", "--show-current")
    if branch.returncode or branch.stdout.strip() != "main":
        raise RuntimeError("automatic README commits are allowed only on main")
    staged = _git(repo_root, "diff", "--cached", "--quiet", "--", relative)
    if staged.returncode != 0:
        raise RuntimeError("README has staged changes; refusing to include them in an automatic commit")

    head = _git(repo_root, "show", f"HEAD:{relative}")
    if head.returncode:
        raise RuntimeError("could not read the committed README baseline")
    current = readme_path.read_text(encoding="utf-8")
    committed = head.stdout
    if current == committed:
        return False
    placeholder = f"{START}\\n{END}"
    try:
        if replace_progress(current, placeholder) != replace_progress(committed, placeholder):
            raise RuntimeError("README has non-generated edits; refusing an automatic commit")
    except ValueError as error:
        raise RuntimeError("README progress markers are missing or ambiguous") from error

    command = _commit_command(repo_root, relative)
    result = subprocess.run(command, capture_output=True, text=True, check=False)
    if result.returncode:
        raise RuntimeError("README-only commit failed; progress remains in the working tree")
    return True


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--readme", type=Path, default=README, help=argparse.SUPPRESS)
    parser.add_argument("--commit-readme", action="store_true",
                        help="commit only a generated progress change on main")
    args = parser.parse_args()
    try:
        changed = update(args.readme, live_project())
        committed = commit_progress(args.readme) if args.commit_readme else False
    except (OSError, ValueError, KeyError, RuntimeError) as error:
        print(f"README progress updater stopped safely: {error}", file=sys.stderr)
        return 1
    if changed:
        print("README progress refreshed.")
    if committed:
        print("Committed README.md only; no push was performed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
