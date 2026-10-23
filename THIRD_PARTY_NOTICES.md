# Licenses and third-party notices

This repository's own native diagnostic code and Android host application: MIT, see LICENSE.

The exact primary source is included as a Git submodule, not copied source:
- Ishaan Kalra's BotWRecomp: MIT (upstream/BotWRecomp/LICENSE).
- Cemu GPU-derived and other Cemu-derived source in the submodule: MPL-2.0 as marked in the upstream source files and upstream/BotWRecomp/runtime/cemu/LICENSE.txt.
- Dear ImGui, metal-cpp and other upstream bundled dependencies: retain their individual notices and applicable licenses.

A source's inclusion in an MIT-licensed outer repository **does not relicense** its own MPL/other-licensed files. Before distributing modifications to MPL-covered code, comply with MPL-2.0 source availability and notices.

Future Cemu Vulkan integration must identify upstream source revision, retain per-file notices and satisfy MPL-2.0 requirements. Do not assume copying a complete Cemu renderer is a license-neutral operation.

Nintendo's game executables, data, graphics, music, keys and generated game-derived code are **not** licensed by this repository and must not be uploaded or embedded in public APKs.

The Legend of Zelda and Breath of the Wild are trademarks of Nintendo; this project is unofficial.
