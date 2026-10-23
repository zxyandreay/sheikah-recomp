#pragma once
#include <cstdint>
#include <string>
namespace sheikah {
struct PlatformInfo {
    std::uint32_t pointer_bits;
    bool little_endian;
    bool arm64;
};
PlatformInfo detect_platform() noexcept;
std::string platform_report();
}
