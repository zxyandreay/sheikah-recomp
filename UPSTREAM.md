# Pinned upstream source

Primary upstream: https://github.com/IshaanKalra2103/BotWRecomp

Pinned commit: **2b84b82dbe7efe41707d236fdbac9ec5e98c8d3d**
(2026-10-17; initial publicly available iOS/macOS recompilation).

Method: Git submodule at **upstream/BotWRecomp**. Its own Git history, original license, third-party file notices, and source remain intact. This repository does not vendor or distribute Nintendo's recompiled game code.

Checkout:

    git clone --recurse-submodules https://github.com/zxyandreay/sheikah-recomp.git
    git submodule update --init --recursive

Updates are **manual and audited**:

    cd upstream/BotWRecomp
    git fetch origin
    git log --oneline HEAD..origin/main

Review differences, platform regressions, dependency/license changes, and known issues BEFORE updating the submodule pointer; then test locally and commit the pointer change with the upstream SHA recorded here.

Additional research references (not directly imported):
- https://github.com/cemu-project/Cemu — upstream Wii U Vulkan renderer.
- https://github.com/GreenNaugahyde/ZeldaWWHDRecompAndroid — Android Wii U recompilation engineering.
- https://github.com/Nycolazs/LASRecomp-Android-Plus — Android recompilation techniques.

No code from these additional projects has been copied into the SheikahRecomp application at initialization.
