cmake_minimum_required(VERSION 3.20)
project(LowFPSMode LANGUAGES CXX)

if(NOT WIN32)
    message(FATAL_ERROR "This ReShade add-on must be built for Windows.")
endif()

if(NOT DEFINED RESHADE_INCLUDE_DIR)
    message(FATAL_ERROR "Set RESHADE_INCLUDE_DIR to the ReShade repository's include directory.")
endif()

add_library(LowFPSMode SHARED src/main.cpp)
target_compile_features(LowFPSMode PRIVATE cxx_std_17)
target_include_directories(LowFPSMode PRIVATE "${RESHADE_INCLUDE_DIR}")
target_compile_definitions(LowFPSMode PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)

set_target_properties(LowFPSMode PROPERTIES
    PREFIX ""
    OUTPUT_NAME "LowFPSMode"
    SUFFIX ".addon64"
)

if(MSVC)
    target_compile_options(LowFPSMode PRIVATE /W4 /permissive- /EHsc)
endif()
