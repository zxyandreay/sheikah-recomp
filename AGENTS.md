# SheikahRecomp contributor and Codex instructions

Mission: move from a pinned Wii U BotWRecomp source baseline to a **real** native Android ARM64/Vulkan port. This is NOT a Switch port and NOT an emulation frontend.

## Before editing
1. Read README.md, UPSTREAM.md, docs/MILESTONES.md, docs/PROGRESS.md, docs/KNOWN_ISSUES.md.
2. Inspect git status and actual toolchain availability.
3. Review relevant upstream/BotWRecomp code, especially ios/PORTING.md and runtime GPU seams.
4. Avoid rewriting the existing PowerPC-to-C++ generator, Cafe OS runtime or gameplay fixes.

## Scope and verification
- Advance one narrowly scoped milestone at a time; make implementation and tests, not optimistic status claims.
- Distinguish **implemented** from **compiled**, **host-tested**, **Android-built**, **device-tested**, and **playable**.
- Update docs/PROGRESS.md and docs/KNOWN_ISSUES.md with concrete evidence and blockers.
- Prefer portable C++20, Android NDK, CMake, SDL3 where needed, Vulkan; isolate Android host code.
- Preserve the existing Apple targets in the upstream submodule. Prefer adapters over modifying upstream.
- Initial bootstrap deliberately does NOT link BOTW runtime or game code; keep status truthful.

## Local-first resource efficiency
- No automatic GitHub Actions or hosted CI.
- Prefer incremental CMake/Ninja and Gradle builds; avoid regenerating massive game code unnecessarily.
- Use tests with synthetic/non-Nintendo data whenever possible.
- Save compiler command/errors and re-run narrow test targets.
- Keep the upstream submodule pinned; do not update it without audit and documentation.
- Never commit ROMs, RPX/RPL, Wii U keys, generated guest-game code, game assets, saves or proprietary payloads.
- No force pushes; inspect Git status before committing. Commit and push cohesive verified work only.
- If SDK/NDK or a device is absent, document that blocker and do not claim successful Android builds.

## Immediate next engineering task
1. Reproduce the host probe test.
2. Verify that Android's debug APK builds with SDK/NDK.
3. Add synthetic Android address-space and memory-protection probes.
4. Plan the minimal subset of upstream Cafe OS runtime sources and platform shims needed to compile under Android ARM64, WITHOUT touching the GPU yet.
