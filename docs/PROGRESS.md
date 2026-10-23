# Development progress

## 2026-10-23 — Repository foundation

- Initialized the previously empty GitHub repository.
- Added upstream source as Git submodule pinned to 2b84b82dbe7efe41707d236fdbac9ec5e98c8d3d.
- Recorded licensing and provenance; documented game-file restrictions.
- Added a standalone C++ diagnostics module and game-free host smoke test.
- Added minimal Android Java / JNI ARM64 bootstrap, with a Vulkan **loader-presence** probe (not GPU compatibility testing).
- Added roadmap, initial audit, developer instructions and no-CI local build guidance.

**Host validation (2026-10-23):** Recreated the committed platform probe sources in a local host-test workspace, configured with CMake + Ninja, compiled the C++20 probe/library, and ran CTest: **1/1 passed** (64-bit little-endian Linux host). GitHub's published native source and submodule pointer were separately read back and verified. No Android SDK, Gradle, or NDK was available; therefore **Android APK compile, JNI loading on device, and Vulkan functionality remain untested**.

**Next task:** reproduce CMake host tests and assemble the ARM64 debug APK locally, then instrument guest virtual address reservation tests.

**Playable status:** no title screen, no game runtime integration, no Android gameplay.

## 2026-10-24 — First distributable Android ARM64 diagnostic test package

- Produced a separate experimental diagnostic APK without Nintendo game files in the constrained execution environment (no Android SDK/NDK/Gradle or network downloads).
- Cross-compiled an ARM64-only JNI native shared library using LLVM/LLD; generated minimal Android manifest and DEX as an interim fallback, not the canonical Gradle build.
- Signed with a self-signed development test certificate (v1+v2 schemes). Local ZIP/DEX/manifest/ELF structural checks and cryptographic self-verification passed.
- Shared the test APK as a conversation artifact. See docs/DEVICE_TESTING.md for installation instructions and exact SHA-256.
- **Not yet verified on a real Android phone.** It is a native bootstrap diagnostic, not playable BOTW. The normal Gradle/NDK project still requires its own successful build.

Next: user/device installation result; resolve any PackageManager/Dalvik/JNI errors; obtain standard SDK/NDK build for reproducible Gradle APKs; only then integrate upstream runtime components.
