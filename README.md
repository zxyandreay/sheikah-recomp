# SheikahRecomp

**Experimental native Android ARM64 porting project for The Legend of Zelda: Breath of the Wild (Wii U).**

**Status: foundation / Android bootstrap only. NOT playable.** There is currently no BOTW game loader, game renderer, or playable APK in this repository.

This independent, unofficial project investigates adapting the existing [BotWRecomp](https://github.com/IshaanKalra2103/BotWRecomp) PowerPC-to-C++ static recompiler and Cafe OS compatibility runtime for Android. The intended end state uses native ARM64 execution and Vulkan, not a general-purpose Wii U emulator or CPU JIT.

## Why this architecture?

BotWRecomp already demonstrates Wii U BOTW game code statically recompiled to C++ and compiled as native ARM64 on Apple devices. SheikahRecomp retains an **exactly pinned upstream source submodule**, rather than rewriting or duplicating that work. Android-specific code lives separately. The biggest unsolved step is adapting the existing Metal-dependent Latte/Cemu rendering pipeline to Vulkan.

## Current deliverables

- Pinned upstream BotWRecomp source, available as a Git submodule.
- Minimal Android Java Activity + native JNI bootstrap / diagnostics.
- Portable C++ platform probe with game-independent host-side tests.
- Local-first Android/host build instructions and milestone roadmap.
- Upstream license, dependency and game-content handling documentation.

**Not yet implemented:** Android Cafe OS runtime integration, PowerPC-generated code linking, working Vulkan renderer, BOTW title screen, gameplay, or on-device game import.

## Get started (Windows)

Install Git, JDK 17, Android SDK command-line tools, Android SDK Platform 35, NDK 27.2.12479018, CMake 3.22.1 and Gradle 8.9. Android Studio can manage the SDK components.

    git clone --recurse-submodules https://github.com/zxyandreay/sheikah-recomp.git
    cd sheikah-recomp

For an existing checkout:

    git submodule update --init --recursive

Run game-independent host tests with CMake + a C++20 compiler:

    cmake -S . -B build-host -G Ninja
    cmake --build build-host
    ctest --test-dir build-host --output-on-failure

Android APK bootstrap build (from the android directory, with a suitable Gradle 8.9 installation on PATH):

    cd android
    gradle :app:assembleDebug

Output: android/app/build/outputs/apk/debug/app-debug.apk. This is **only a diagnostic bootstrap**, not a game port.

See [docs/DEVELOPMENT.md](docs/DEVELOPMENT.md) for prerequisites and limitations.

## Supported game version (future game build only)

Upstream documents USA Wii U BOTW update **1.6.0 / v208**, executable SHA-256:

    ba58da5b95ce929e005d058ceb08b9b2788d1ab2bbc8a6c189bbadca0bb34d30

No game data is needed for the current bootstrap. Later, users must provide their own legitimately obtained compatible game files locally. **Do not upload game files, generated game C++ code, keys, or APKs containing game code to this repository.**

## Development docs

- [Architecture](docs/ARCHITECTURE.md)
- [Upstream audit](docs/UPSTREAM_AUDIT.md)
- [Porting plan](docs/PORTING_PLAN.md)
- [Milestones](docs/MILESTONES.md)
- [Progress](docs/PROGRESS.md)
- [Known issues](docs/KNOWN_ISSUES.md)
- [Upstream provenance](UPSTREAM.md)
- [Contributor instructions](AGENTS.md)

## Legal / attribution

SheikahRecomp's new source code is MIT licensed. [BotWRecomp](https://github.com/IshaanKalra2103/BotWRecomp) retains its MIT notices; its vendored Cemu-derived code contains MPL-2.0 files and other third-party licenses. See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) and the source files themselves.

Nintendo owns The Legend of Zelda: Breath of the Wild and related IP. Not affiliated with, sponsored by, or endorsed by Nintendo. No proprietary Nintendo files are included.
