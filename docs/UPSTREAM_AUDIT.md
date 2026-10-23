# Initial upstream audit (source inspection only)

Pinned primary source: BotWRecomp commit 2b84b82dbe7efe41707d236fdbac9ec5e98c8d3d.

This audit is based on source structure and upstream documentation. NO code from the original game has been compiled or run on Android.

| Upstream location | Purpose | Initial Android decision |
| --- | --- | --- |
| cafe/ and tools/recompile.py | RPX PowerPC analysis, function discovery, C++ generation | Reuse on developer host; don't rewrite |
| runtime/include/, runtime/src/compat/ | Portable runtime interfaces and data representation | Selectively compile/test next |
| runtime/src/mem.cpp | 4 GiB+ guest memory region | Needs Android mmap/mprotect and footprint testing |
| runtime/src/coreinit/, thread.cpp | Cafe OS services, sync and threads | Subsystem-specific platform adaptation |
| runtime/src/gx2/, runtime/src/latte/ | GX2 HLE, GPU command submissions | Keep interface, adapt GPU backend |
| runtime/cemu/ | Vendored Cemu Latte processing and Metal renderer | Metal unavailable on Android; investigate Cemu Vulkan |
| runtime/cemu_shims/ | Bridge between runtime and Cemu | Bridge needs Vulkan-specific port |
| runtime/src/host/, ios/ | SDL host, platform window, touch, Apple app | Reuse input concepts; create Android equivalents |
| runtime/src/audio/ | Audio host | Check SDL3/Android compatibility |
| runtime/src/gpu_native/ | Experimental custom Metal GPU | NOT a ready Vulkan renderer |
| generated/ | Game-derived C++ output | Local-only, never commit |

Source evidence: upstream README.md, ios/PORTING.md, CMakeLists.txt and docs/native-renderer.md.

## Findings

1. The pinned upstream builds the **same C++ generated guest code and shared runtime** for Mac and iPhone, using platform-specific build/entry code.
2. Both established Latte path and experimental native GPU path rely on **Apple Metal**, which Android cannot run.
3. Upstream Cemu contains a separate Vulkan implementation, but it is not included in the pinned BotWRecomp vendored renderer; a code-level integration spike is required.
4. The game code is NOT included in the upstream repository, by design.
5. iPhone tests were limited; a reproducible reported stall after approximately four minutes remains unexplained.
6. The present SheikahRecomp bootstrap intentionally contains **no game runtime connection**.

Next audit: compile platform-neutral upstream components for Android, identify OS imports transitively, and document Vulkan/LATTE interface mismatch.
