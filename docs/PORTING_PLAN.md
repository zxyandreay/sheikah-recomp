# Evidence-driven Android porting plan

## Phase A — Baseline and bootstrap
- [x] Initialize target repository and provenance.
- [x] Pin working reference source as an upstream submodule.
- [x] Add game-free Android NDK/JNI bootstrap and host-testable native diagnostic code.
- [ ] Verify Android build using installed JDK 17, SDK 35, NDK r27c and Gradle 8.9.
- [ ] Verify APK launches on a physical ARM64 Vulkan-capable Android device.

## Phase B — Memory and Cafe OS
- [ ] Prototype safe 4 GiB+ reservation/mprotect on supported Android devices.
- [ ] Compile selected genuine upstream portable runtime components.
- [ ] Port address mapping, guest stack handling, threading, signals and filesystem.
- [ ] Verify with deterministic synthetic tests before involving copyrighted game code.

## Phase C — Rendering
- [ ] Compare pinned vendored Metal Latte against upstream Cemu Vulkan revision.
- [ ] Implement or adapt Vulkan renderer behind existing GX2/Latte interface.
- [ ] Validate command translation, shaders, textures, tiling, coherency and synchronization.
- [ ] Render synthetic game-free draw commands, then title screen with local user files.

## Phase D — Game bootstrap and gameplay
- [ ] Support local v208 game validation and recompile-to-C++ pipeline.
- [ ] Compile generated C++ on a developer machine into a private ARM64 build.
- [ ] Reach BOTW title screen on a real phone; capture logs and build configuration.
- [ ] Implement controller, touch, audio, saving, long-run stability and game progression.

## Phase E — Optimization and distribution
- [ ] GPU performance, shaders/cache, frame pacing and thermals.
- [ ] Game-free launcher and user-owned game build/import workflow if legally/practically viable.
- [ ] Distinguish personal game-derived APKs from redistributable game-free artifacts.

No estimated playable date or percent-complete without verified hardware evidence.
