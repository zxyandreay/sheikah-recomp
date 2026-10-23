# Test the first Android ARM64 diagnostic APK

## Scope — read before installing

This is an **experimental native-code launch test**, NOT a playable The Legend of Zelda: Breath of the Wild port. It contains neither game data nor the Cafe OS game runtime.

A standalone development test APK has been assembled outside the standard Gradle toolchain because the authoring environment lacks Android SDK/NDK/Gradle and cannot download them. The test package is provided as a chat attachment, **not committed to this repository**.

Unlike the normal Android project in `android/`, this interim APK uses a compact hand-assembled DEX and binary Android manifest plus a minimal ARM64 JNI library built with LLVM. It is NOT a replacement for a standard Gradle/NDK build. The method is unconventional and has not yet been installed on a physical device.

## Device test

1. Download `sheikah-recomp-diagnostics-arm64.apk` from the chat attachment to an Android phone.
2. Confirm the device CPU is **ARM64** (most modern Android phones). Android 8.0+ is required by the manifest.
3. Open the APK with Android's package installer and approve installation from that source if prompted.
4. Launch **SheikahRecomp Diagnostics** from the app drawer.
5. A successful run should display a dark diagnostic screen containing `Native library: LOADED` and `JNI connection: OK`, with an explicit note that BOTW is not integrated.

**Known status:** DEX header/hash and map integrity, AXML structure, ARM64 ELF machine format, ZIP CRCs, and both v1 and v2 signing data were statically verified. The actual Android install, class verification, JNI launch and UI were NOT tested on a device. Treat this as an experimental candidate, not a confirmed functioning release.

## If Android refuses installation

- Record the exact message, Android version, phone CPU/ABI and whether another `dev.zxyandreay.sheikahrecomp` app is installed.
- The installer might refuse to update an existing copy signed by a different development key. In that case, uninstall **only the prior diagnostic app**, after checking whether it holds anything needed.
- Do not bypass platform protections or disable Play Protect globally merely to install a diagnostic APK.

## If it crashes on launch

Connect a PC with Android platform-tools installed (USB debugging enabled), then:

```powershell
adb shell am start -n dev.zxyandreay.sheikahrecomp/.MainActivity
adb logcat -d -s AndroidRuntime:E linker:E art:E
```

Share the crash lines and device/Android version. Check for `ClassNotFoundException`, `VerifyError`, `UnsatisfiedLinkError` or PackageManager parse errors.

## APK metadata

- Package: `dev.zxyandreay.sheikahrecomp`
- ABI: `arm64-v8a` only
- minSdkVersion: 26
- targetSdkVersion: 28 (interim diagnostic compatibility)
- Signing: self-signed **development test key**, APK Signature Scheme v1 + v2
- SHA-256 of current chat test attachment: `711225ac93a7020e1d33d38476bf1518cb4b4d63ecdb85ac55050e1895200577`
- No game assets, executable, generated game code, license keys, or network functionality

For further development, the official project remains the `android/` Gradle/NDK sources. Prioritize obtaining a real SDK/NDK build and verifying its APK on device before merging significant BOTW runtime code.

## Installation failure observed and alternate candidate (2026-10-24)

The first custom v1+v2 APK (SHA-256 `711225ac93a7020e1d33d38476bf1518cb4b4d63ecdb85ac55050e1895200577`) **was rejected by Android's package installer** with: **"App not installed as package appears to be invalid."** Do not call that APK valid or compatible.

The packaging/signing pipeline in the original experiment was hand-written, so its static checks did not establish Android compatibility. The precise PackageManager failure code has **not** been collected; the cause is not yet verified.

A second **diagnostic test candidate**, `sheikah-recomp-diagnostics-arm64-v1.apk`, was built from the same manifest/DEX/native code using standard Java `jarsigner` only (APK Signature Scheme v1), without the experimental v2 signing block. This is a **hypothesis test** isolating signing; it does not repair potential manifest or DEX errors. Android 8+ supports v1 signatures for an app targeting SDK 28. Its local ZIP, JAR signature, DEX checksums and ARM64 ELF headers pass static checks, **but installation is not verified**.

Second candidate SHA-256: `036b89ed5bda253e82bbd03ae153f0f3eb49614b2b6e97153e722520c5c8d663`.

If the second candidate still fails, avoid further hand-assembled releases. Next collect the actual installer error using:

```powershell
adb install -r sheikah-recomp-diagnostics-arm64-v1.apk
```

and prefer rebuilding the canonical `android/` source using Android Gradle Plugin + SDK + NDK + official apksigner/zipalign. Do not lower device security settings.

