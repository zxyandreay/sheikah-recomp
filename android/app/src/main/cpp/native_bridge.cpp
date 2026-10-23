#include "sheikah/platform_probe.h"
#include <jni.h>
#include <dlfcn.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_dev_zxyandreay_sheikahrecomp_MainActivity_nativeDiagnostics(JNIEnv* env, jclass) {
    std::string result = sheikah::platform_report();
    void* vulkan_loader = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
    if (vulkan_loader) {
        result += "Vulkan loader library: present (GPU not validated)\n";
        dlclose(vulkan_loader);
    } else {
        result += "Vulkan loader library: unavailable\n";
    }
    return env->NewStringUTF(result.c_str());
}
