# Example Project

This is a complete example demonstrating both Make and CMake build systems.

## Project Structure

```
example_project/
├── Makefile           # Makefile for building with make
├── CMakeLists.txt     # CMake configuration
├── src/               # Application source files
│   └── main.c
├── include/           # Public header files
│   └── math_utils.h
├── lib/               # Library source files
│   └── math_utils.c
└── tests/             # Test files
    └── test_math.c
```

## Building with Make

```bash
# Build the project
make

# Run tests
make test

# Clean
make clean

# Build in debug mode
make DEBUG=1

# Install
sudo make install PREFIX=/usr/local
```

## Building with CMake

```bash
# Create build directory
mkdir build && cd build

# Configure
cmake ..

# Build
cmake --build .
# or simply: make

# Run tests
ctest
# or: make test

# Install
sudo make install
```

## Build Targets

### Makefile targets:
- `all` - Build everything (default)
- `test` - Build and run tests
- `clean` - Remove build artifacts
- `install` - Install to PREFIX
- `help` - Show available targets

### CMake targets:
- `all` - Build everything (default)
- `test` - Run tests with CTest
- `install` - Install the project
- `package` - Create distributable package

## Features Demonstrated

- Compiling source files
- Creating static libraries
- Linking executables with libraries
- Running tests
- Installing to system directories
- Debug vs Release configurations
- Platform-specific settings
- Automatic dependency tracking
