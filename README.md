Excite Truck
============

A work-in-progress matching decompilation of **Excite Truck** (REXE01) for Nintendo Wii.

This repository does **not** contain any game assets or assembly whatsoever. An existing copy of the game is required.

Supported versions:

- `REXE01`: Rev 0 (USA) — Target DOL SHA-1: `e51685814152f377e5c76a50067d8132e25f672b`

## Progress

Progress below is refreshed hourly from this machine's local decompdecomp instance.
It counts exact matches only; failed attempts and near-matches do not count. When
values change, the scheduled updater commits `README.md` only; it never pushes.
Running the updater manually refreshes the section without committing.

<!-- BEGIN AUTO-GENERATED PROGRESS -->

| Metric | Current progress |
| :--- | :--- |
| **Exactly matched functions** | 8,559 / 13,779 (62.1%) |
| **Exactly matched code** | 681,260 / 3,050,236 bytes (22.3%) |

<!-- END AUTO-GENERATED PROGRESS -->

To refresh it manually, run `python3 tools/update_readme_progress.py`. The
scheduled updater is installed in this machine's user crontab; it needs the local
DD service at `http://127.0.0.1:6464` to be running.

See [`docs/roadmap.md`](docs/roadmap.md) for current direction,
[`docs/decomp_workflow.md`](docs/decomp_workflow.md) for the day-to-day loop,
and [`docs/next_targets.md`](docs/next_targets.md) for a concrete starter list.

## Dependencies

### Windows

On Windows, it's **highly recommended** to use native tooling. WSL or msys2 are **not** required.
When running under WSL, [objdiff](#diffing) is unable to get filesystem notifications for automatic rebuilds.

- Install [Python](https://www.python.org/downloads/) and add it to `%PATH%`.
  - Also available from the [Windows Store](https://apps.microsoft.com/store/detail/python-311/9NRWMJP3717K).
- Download [ninja](https://github.com/ninja-build/ninja/releases) and add it to `%PATH%`.
  - Quick install via pip: `pip install ninja`

### macOS

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages):

  ```sh
  brew install ninja
  ```

- Install [wine-crossover](https://github.com/Gcenx/homebrew-wine):

  ```sh
  brew install --cask --no-quarantine gcenx/wine/wine-crossover
  ```

After OS upgrades, if macOS complains about `Wine Crossover.app` being unverified, you can unquarantine it using:

```sh
sudo xattr -rd com.apple.quarantine '/Applications/Wine Crossover.app'
```

### Linux

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages).
- For non-x86(_64) platforms: Install wine from your package manager.
  - For x86(_64), [wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used.

## Building

- Clone the repository:

  ```sh
  git clone https://github.com/my/repo.git
  ```

- Copy your game's disc image to `orig/REXE01`.
  - Supported formats: ISO (GCM), RVZ, WIA, WBFS, CISO, NFS, GCZ, TGC
  - After the initial build, the disc image can be deleted to save space.

- Configure:

  ```sh
  python configure.py
  ```

- Build:

  ```sh
  ninja
  ```

## Diffing

Once the initial build succeeds, an `objdiff.json` should exist in the project root.

Download the latest release from [encounter/objdiff](https://github.com/encounter/objdiff). Under project settings, set `Project directory`. The configuration should be loaded automatically.

Select an object from the left sidebar to begin diffing. Changes to the project will rebuild automatically: changes to source files, headers, `configure.py`, `splits.txt` or `symbols.txt`.

## Decompdecomp Integration

This project includes helper scripts for the [decompdecomp](https://github.com/n-delic/decompdecomp) service:

- **`.decomp.wtf.json`** — Project manifest that tells decompdecomp how to set up and verify this project.
- **`tools/update_symbols.py`** — Updates `symbols.txt` from the linked ELF using `dtk dol apply`. Run after each build to pick up new symbol names.
- **`tools/function_signatures.py`** — Generates `function_signatures.json` with function addresses, sizes, and sections for the look-alike feature.
- **`tools/refresh_decompdecomp.sh`** — Convenience script that runs a build, updates symbols, and generates signatures in one step.

```sh
# Quick refresh after building
./tools/refresh_decompdecomp.sh

# Dry run (show what would change)
./tools/refresh_decompdecomp.sh --dry-run

# Force update of all anonymous symbols
./tools/refresh_decompdecomp.sh --full
```
