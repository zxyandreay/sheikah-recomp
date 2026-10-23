# Milestone ledger

| Milestone | Target | Current status |
| --- | --- | --- |
| M0 | Provenance, license, protected repository, pinned source | Implemented; verify checkout after clone |
| M1 | Game-free Android bootstrap + native C++ smoke tests | Implemented, Android build not yet verified |
| M2 | Cafe OS portable subset building on Android + memory tests | Not started |
| M3 | Vulkan GPU pipeline and synthetic graphics | Not started |
| M4 | Local BOTW code generation/loading and title screen | Not started |
| M5 | Stable real-device gameplay with controls/audio/saves | Not started |
| M6 | Mobile tuning, compatibility, user workflow | Not started |

## Definition of done

**M0:** initial git history, checked source revision, submodule, legal notices, game-safe .gitignore and documented architecture.

**M1:** local host-native tests pass; Gradle/NDK ARM64 debug build succeeds; APK loads JNI library on an Android device. Until the last two are verified, M1 is incomplete.

**M2:** selected actual upstream Cafe OS components compile in Android NDK and memory behavior is confirmed with instrumented tests.

**M3:** GPU commands render correct synthetic images on Vulkan and logging supports debugging.

**M4:** own local copy of exact upstream-supported Wii U BOTW version boots to a real, correctly rendered title screen.

**M5:** verified device gameplay through initial world area; saves/inputs/audio function and long sessions tested.

**M6:** reproducible user workflow plus profiling-based optimizations.

Never equate repository size or code line count with milestones completed.
