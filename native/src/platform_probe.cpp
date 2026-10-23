#include "sheikah/platform_probe.h"
#include <cstdint>
#include <sstream>
namespace sheikah {
PlatformInfo detect_platform() noexcept {
    const std::uint32_t sentinel = 0x01020304u;
    const auto* bytes = reinterpret_cast<const unsigned char*>(&sentinel);
#if defined(__aarch64__) || defined(_M_ARM64)
    constexpr bool is_arm64 = true;
#else
    constexpr bool is_arm64 = false;
#endif
    return {static_cast<std::uint32_t>(sizeof(void*) * 8), bytes[0] == 0x04u, is_arm64};
}
std::string platform_report() {
    const auto info = detect_platform();
    std::ostringstream out;
    out << "SheikahRecomp native bootstrap (no game runtime)\n"
        << "Pointer width: " << info.pointer_bits << " bits\n"
        << "Host endianness: " << (info.little_endian ? "little" : "big") << "\n"
        << "ARM64 build: " << (info.arm64 ? "yes" : "no") << "\n";
    return out.str();
}
}
