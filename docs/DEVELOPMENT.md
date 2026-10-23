# Development and local build guide

## Prerequisites (Windows)

- Git with submodule support.
- JDK 17.
- Android Studio or Android command-line SDK manager.
- Android SDK platform 35 and build tools.
- Android NDK **27.2.12479018** and CMake **3.22.1**.
- Gradle **8.9** (see note below).
- For host smoke tests: CMake 3.22+, Ninja and a working C++20 compiler.

An example SDK package installation with sdkmanager:

    sdkmanager "platforms;android-35" "build-tools;35.0.0" "ndk;27.2.12479018" "cmake;3.22.1"

Configure ANDROID_HOME and JAVA_HOME for your environment. Java 17 should be used with the pinned Android Gradle Plugin 8.7.3.

## Clone / source

    git clone --recurse-submodules https://github.com/zxyandreay/sheikah-recomp.git
    cd sheikah-recomp
    git submodule status
    git -C upstream/BotWRecomp rev-parse HEAD

Expected upstream SHA: 2b84b82dbe7efe41707d236fdbac9ec5e98c8d3d. The submodule is required for future game-port tasks but **not** the standalone M1 diagnostic build.

## Host-side tests (Windows PowerShell)

    cmake -S . -B build-host -G Ninja
    cmake --build build-host
    ctest --test-dir build-host --output-on-failure

The tests exercise *only* the synthetic native platform probe, not Cafe OS and not game code.

## Android bootstrap APK

From repo root (PowerShell):

    cd android
    gradle :app:assembleDebug

The project does not check in a Gradle wrapper JAR. Install and use Gradle 8.9 for now. To add a wrapper later, generate it using a trusted Gradle installation, then inspect/check in the generated wrapper scripts, properties and standard Gradle distribution JAR in a separate audited change.

Expected APK after successful build:

    android/app/build/outputs/apk/debug/app-debug.apk

For an attached Android device with USB debugging enabled:

    adb install -r app/build/outputs/apk/debug/app-debug.apk
    adb shell am start -n dev.zxyandreay.sheikahrecomp/.MainActivity
    adb logcat -d | findstr /i "sheikahrecomp"

The app only displays runtime diagnostics. Report failures with exact Gradle, NDK, device ABI and Android version; do NOT report it as a BOTW boot.

## Building without proprietary game files

All current host tests and the Android bootstrap must be runnable without any Wii U data. Future private game-derived compilation must use user-provided compatible files under ignored local folders.

Upstream currently requires USA BOTW v208 and validates U-King.rpx against the SHA-256 recorded in README.md.

## CI policy

There are **no GitHub Actions workflows** by design. Prefer local builds and tests. Every new dependency or platform requirement must be documented.
