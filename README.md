Excite Truck
============

A work-in-progress matching decompilation of **Excite Truck** (REXE01) for Nintendo Wii.

This repository does **not** contain any game assets or assembly whatsoever. An existing copy of the game is required.

Supported versions:

- `REXE01`: Rev 0 (USA) — Target DOL SHA-1: `e51685814152f377e5c76a50067d8132e25f672b`

## Progress

```
┌─────────────────────────────────────────────────────────────────────────────┐
│ Total Progress: [██████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░] 10.5% (97/922)   │
│ SDK Code Match: [█████████████████████████████░░] 99.3% (75,736 / 76,268 B) │
│ SDK Linked TUs: [████████████████████████████░░] 91.6% (58 / 62 files)      │
└─────────────────────────────────────────────────────────────────────────────┘
```

| Metric | Matched / Total | Percentage |
| :--- | :--- | :--- |
| **Fully Matched Units** | 97 / 922 units | **10.52%** |
| **SDK Code (.text)** | 75,736 / 76,268 bytes (457 / 459 functions) | **99.30%** |
| **SDK Data (.data)** | 55,564 / 90,404 bytes | **61.46%** |
| **Linked SDK Modules** | 58 / 62 files | **93.55%** |
| **Named SDK Symbols** | ~1,755 resolved (11,390 placeholders) | **~70% drained** |

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
