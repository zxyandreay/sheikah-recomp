# Architecture — proposed, not yet integrated

    User-owned Wii U BOTW (v208) RPX
       |
       v
    pinned upstream/BotWRecomp/cafe + tools/recompile.py
       |
       v
    locally generated C++ game functions (NEVER commit)
       |
       v
    Android NDK ARM64 C++ executable/library
       |
       +--> portable BotWRecomp Cafe OS runtime (future port)
       |       filesystem / time / memory / scheduling / audio / input
       |
       +--> GX2 / Latte command interface (future port)
                    |
                    v
              Vulkan renderer (NOT implemented)

Current committed components:
- upstream/BotWRecomp: a pinned, unmodified Git submodule containing the actual recompiler, Cafe OS and Apple GPU implementations.
- native/: synthetic, standalone C++ host diagnostics and tests only.
- android/: Android Java Activity, JNI bridge, platform/Vulkan-loader availability diagnostics.

There is no connection between the bootstrap and the BOTW game code yet.

Important areas for Android:
- Wii U 32-bit big-endian guest and 4 GiB virtual address reservation in upstream runtime.
- ARM64 architecture and mapping/protection of guest memory under Android ASLR, SELinux and address-space constraints.
- Guest thread stacks and synchronization; thread naming and priorities.
- System filesystem paths, content storage and save directories.
- GX2 display lists and Cemu Latte command processing.
- Replacing Metal/Objective-C++ device resources with Vulkan/Android.
- Shader translation (R600 to SPIR-V or compatible approach), buffer/texture tiling and GPU-visible guest memory.

Reject any implementation that claims a full BOTW port by providing a minimal JNI activity or Vulkan capability probe alone.
