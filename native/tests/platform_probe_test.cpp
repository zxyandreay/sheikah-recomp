#include "sheikah/platform_probe.h"
#include <cassert>
#include <iostream>
#include <string>
int main() {
    const auto p = sheikah::detect_platform();
    assert(p.pointer_bits == sizeof(void*) * 8);
    assert(p.pointer_bits == 32 || p.pointer_bits == 64);
    const std::string report = sheikah::platform_report();
    assert(report.find("native bootstrap") != std::string::npos);
    assert(report.find("Pointer width:") != std::string::npos);
    std::cout << report << "Host probe passed\n";
    return 0;
}
