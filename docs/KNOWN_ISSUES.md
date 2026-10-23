# Known limitations and blockers

1. **No Android build/device verification** at initial foundation stage. No SDK/NDK/Gradle toolchain was available in the authoring environment.
2. **No gameplay**. Java/JNI bootstrap is diagnostics-only and deliberately contains no game loader.
3. **GPU unavailable**. Pinned BotWRecomp depends on Metal; Cemu Vulkan must be investigated and ported.
4. **Guest address space untested on Android**. A 4 GiB+ virtual reservation is likely to require careful device tests.
5. **Upstream iPhone issue**. Its README/ios/PORTING.md documents an unexplained gameplay stall after approximately four minutes on one device.
6. **Driver support unknown**. Being able to load libvulkan.so does NOT establish usable GPU features, memory capabilities or real-game compatibility.
7. **Full-game APK publication unresolved**. Copyrighted Nintendo game code and assets must not be bundled into public releases.
8. **Upstream update risk**. Commit pin intentionally remains fixed; changes need manual review.

File actionable bug reports with exact devices, Android versions, NDK/Gradle versions, compile commands, logs and reproducible steps.
