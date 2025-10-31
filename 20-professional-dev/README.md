# Module 20: Professional Development 🎓

Master professional C development practices and build systems!

## 📚 What You'll Learn

1. **Build Systems** - Make and CMake in depth
2. Unit testing in C
3. Code style and standards
4. Version control best practices
5. Profiling and optimization
6. Writing maintainable code

## 🔨 Mastering Makefiles

### Makefile Basics

A Makefile automates the build process. It consists of rules, targets, prerequisites, and commands.

**Basic Structure:**
```makefile
target: prerequisites
command
```

### Simple Makefile

```makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = program

# Source files
SRCS = main.c utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c
$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
rm -f $(OBJS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean
```

### Advanced Makefile Features

**See [Makefile.advanced](./Makefile.advanced) for complete example with:**
- Multiple directories
- Library building
- Debug/Release configurations
- Automatic dependency generation
- Installation rules
- Platform detection

### Makefile Variables

```makefile
# Compiler settings
CC = gcc
CXX = g++
AR = ar
CFLAGS = -Wall -Wextra -pedantic
CPPFLAGS = -I./include
LDFLAGS = -L./lib
LDLIBS = -lm -lpthread

# Directories
SRC_DIR = src
BUILD_DIR = build
INC_DIR = include
LIB_DIR = lib

# Find all source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
```

### Pattern Rules and Functions

```makefile
# Pattern rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
@mkdir -p $(BUILD_DIR)
$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Function example: generate dependency files
$(BUILD_DIR)/%.d: $(SRC_DIR)/%.c
@mkdir -p $(BUILD_DIR)
$(CC) $(CPPFLAGS) -MM -MT $(@:.d=.o) $< > $@

# Include dependencies
-include $(OBJS:.o=.d)
```

### Conditional Compilation

```makefile
# Debug vs Release
DEBUG ?= 0
ifeq ($(DEBUG), 1)
CFLAGS += -g -O0 -DDEBUG
else
CFLAGS += -O2 -DNDEBUG
endif

# Platform detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
LDLIBS += -lrt
endif
ifeq ($(UNAME_S),Darwin)
CFLAGS += -D__APPLE__
endif
```

### Complete Project Makefile

See [Makefile.project](./Makefile.project) for a full-featured example with:
- Source organization
- Library creation
- Test building
- Documentation generation
- Installation targets

## 📋 Mastering CMake

### CMake Basics

CMake is a cross-platform build system generator. It generates Makefiles, Visual Studio projects, or other build files.

### Simple CMakeLists.txt

```cmake
# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(MyProject C)

# C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Executable
add_executable(myprogram main.c utils.c)

# Compiler warnings
target_compile_options(myprogram PRIVATE
    -Wall -Wextra -pedantic
)
```

### Building with CMake

```bash
# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build project
cmake --build .

# Or use make directly
make

# Install (if install rules defined)
sudo make install
```

### CMake Project Structure

```
project/
├── CMakeLists.txt          # Root CMake file
├── src/
│   ├── CMakeLists.txt      # Source directory CMake
│   ├── main.c
│   └── utils.c
├── include/
│   └── utils.h
├── lib/
│   ├── CMakeLists.txt      # Library CMake
│   └── mylib.c
└── tests/
    ├── CMakeLists.txt      # Tests CMake
    └── test_main.c
```

### Advanced CMake Features

**See [CMakeLists.advanced.txt](./CMakeLists.advanced.txt) for:**
- Multiple targets
- Static/shared libraries
- External dependencies
- Installation rules
- Testing with CTest
- Packaging with CPack

### CMake Variables and Options

```cmake
# Define options
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(ENABLE_TESTS "Build tests" ON)
option(ENABLE_DOCS "Generate documentation" OFF)

# Set variables
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Use variables
message(STATUS "Building ${PROJECT_NAME} version ${PROJECT_VERSION}")
```

### Building Libraries with CMake

```cmake
# Static library
add_library(mylib_static STATIC
    src/lib1.c
    src/lib2.c
)

# Shared library
add_library(mylib_shared SHARED
    src/lib1.c
    src/lib2.c
)

# Header-only library (interface library)
add_library(mylib_headers INTERFACE)
target_include_directories(mylib_headers INTERFACE include/)

# Link library to executable
target_link_libraries(myprogram PRIVATE mylib_static)
```

### Finding and Using External Libraries

```cmake
# Find packages
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

# Manually find libraries
find_library(MATH_LIB m)

# Link to target
target_link_libraries(myprogram PRIVATE
    Threads::Threads
    OpenSSL::SSL
    ${MATH_LIB}
)
```

### CMake Installation Rules

```cmake
# Install executable
install(TARGETS myprogram
    RUNTIME DESTINATION bin
)

# Install libraries
install(TARGETS mylib_static mylib_shared
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install headers
install(DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

# Install documentation
install(FILES README.md LICENSE
    DESTINATION share/doc/${PROJECT_NAME}
)
```

### CMake Testing with CTest

```cmake
# Enable testing
enable_testing()

# Add test executable
add_executable(test_main tests/test_main.c)
target_link_libraries(test_main PRIVATE mylib_static)

# Add tests
add_test(NAME test_basic COMMAND test_main)
add_test(NAME test_advanced COMMAND test_main --advanced)

# Set test properties
set_tests_properties(test_basic PROPERTIES
    TIMEOUT 30
    PASS_REGULAR_EXPRESSION "All tests passed"
)
```

### CMake Configuration Types

```cmake
# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Debug configuration
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")

# Release configuration
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

# Add custom configuration
set(CMAKE_C_FLAGS_PROFILE "-pg -O2")
```

## 📖 Code Examples

1. [Makefile.simple](./Makefile.simple) - Basic Makefile
2. [Makefile.advanced](./Makefile.advanced) - Advanced features
3. [Makefile.project](./Makefile.project) - Complete project
4. [CMakeLists.simple.txt](./CMakeLists.simple.txt) - Basic CMake
5. [CMakeLists.advanced.txt](./CMakeLists.advanced.txt) - Advanced CMake
6. [CMakeLists.library.txt](./CMakeLists.library.txt) - Library project
7. [example_project/](./example_project/) - Complete example with both

## 🧪 Unit Testing

```c
// Simple test framework
#include <assert.h>
#include <stdio.h>

void test_addition() {
    assert(add(2, 3) == 5);
}

void test_multiplication() {
    assert(multiply(2, 3) == 6);
}

int main() {
    test_addition();
    test_multiplication();
    printf("All tests passed!\n");
    return 0;
}
```

## 📊 Profiling with gprof

```bash
gcc -pg -o program program.c
./program
gprof program gmon.out > analysis.txt
```

## 🎯 Code Style Guidelines

1. **Naming**: Use descriptive names
2. **Indentation**: 4 spaces or tabs
3. **Comments**: Explain why, not what
4. **Functions**: Keep them small and focused
5. **Error handling**: Always check return values
6. **Memory**: Free what you allocate

## 🔜 Congratulations!

You've completed the course! Keep practicing and building projects.

---

**Final Tip**: The journey of learning never ends. Keep coding, keep learning!
