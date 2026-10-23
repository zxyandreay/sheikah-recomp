cmake_minimum_required(VERSION 3.22)
project(SheikahRecompAndroid LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../../../.." ABSOLUTE)
add_library(sheikah_bootstrap SHARED
    native_bridge.cpp
    "${PROJECT_ROOT}/native/src/platform_probe.cpp")
target_include_directories(sheikah_bootstrap PRIVATE
    "${PROJECT_ROOT}/native/include")
target_compile_options(sheikah_bootstrap PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(sheikah_bootstrap PRIVATE dl)
