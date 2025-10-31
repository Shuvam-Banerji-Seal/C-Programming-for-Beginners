# Example Project CMakeLists.txt
# Demonstrates complete CMake configuration

cmake_minimum_required(VERSION 3.10)

project(MathExample
    VERSION 1.0.0
    DESCRIPTION "Example project with Make and CMake"
    LANGUAGES C
)

# C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler flags
add_compile_options(-Wall -Wextra)

# Library
add_library(mathutils
    lib/math_utils.c
)

target_include_directories(mathutils
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Executable
add_executable(math_example
    src/main.c
)

target_link_libraries(math_example
    PRIVATE mathutils
)

# Tests
enable_testing()

add_executable(test_math
    tests/test_math.c
)

target_link_libraries(test_math
    PRIVATE mathutils
)

add_test(NAME MathTests COMMAND test_math)

# Installation
install(TARGETS math_example mathutils
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

# Print configuration
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
