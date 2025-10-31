# Makefile for Module 03: Control Flow
# Demonstrates compilation with gcc and clang with detailed flag explanations

# ============================================================================
# COMPILER CONFIGURATION
# ============================================================================

# CC: The C compiler to use (can be overridden: make CC=clang)
CC = gcc

# Alternative compiler (uncomment to use clang by default)
# CC = clang

# CFLAGS: Compiler flags used for all compilations
# Each flag is explained below:
CFLAGS = -std=c11        # Use C11 standard (modern C features)
CFLAGS += -Wall          # Enable all common warnings
CFLAGS += -Wextra        # Enable extra warnings beyond -Wall
CFLAGS += -Wpedantic     # Enforce strict ISO C compliance
CFLAGS += -O2            # Optimization level 2 (balanced performance)
CFLAGS += -g             # Include debugging symbols for gdb

# ============================================================================
# COMPILER FLAGS EXPLAINED IN DETAIL
# ============================================================================
#
# -std=c11:
#   Specifies the C standard version (C11 = ISO/IEC 9899:2011)
#   Other options: c89, c90, c99, c11, c17, c2x
#   Use c11 for modern C features while maintaining compatibility
#
# -Wall:
#   Enables common warnings including:
#   - Uninitialized variables
#   - Implicit function declarations
#   - Format string mismatches
#   - Return type issues
#   Does NOT enable ALL warnings (despite the name)
#
# -Wextra:
#   Enables additional warnings not included in -Wall:
#   - Unused parameters
#   - Comparison between signed and unsigned
#   - Missing field initializers
#   - Empty body in if/else statements
#
# -Wpedantic:
#   Issues warnings for code that doesn't strictly conform to ISO C
#   Warns about compiler extensions
#   Useful for portable code
#
# -O0: No optimization (default, fastest compilation)
# -O1: Basic optimization (moderate compilation time)
# -O2: Recommended optimization (good balance of speed and size)
# -O3: Aggressive optimization (may increase code size)
# -Os: Optimize for size
# -Ofast: Aggressive optimization, may break strict standards compliance
#
# -g:
#   Produces debugging information for gdb
#   Allows setting breakpoints, inspecting variables, etc.
#   Increases binary size but essential for debugging
#
# -march=native:
#   Optimize for the CPU architecture of the build machine
#   May not be portable to other machines
#
# -fno-omit-frame-pointer:
#   Keep frame pointers for better debugging and profiling
#
# -fstack-protector-strong:
#   Add buffer overflow protection
#   Helps detect stack smashing attacks
#
# ============================================================================

# Additional useful flags (commented out by default)
# Uncomment these for stricter compilation or specific needs:

# CFLAGS += -Werror              # Treat all warnings as errors
# CFLAGS += -Wconversion         # Warn on implicit type conversions
# CFLAGS += -Wshadow             # Warn when variable shadows another
# CFLAGS += -Wstrict-prototypes  # Warn if function declared without prototype
# CFLAGS += -Wmissing-prototypes # Warn if function defined without prototype
# CFLAGS += -fanalyzer           # Enable static analysis (gcc 10+)
# CFLAGS += -fsanitize=address   # Enable AddressSanitizer (memory errors)
# CFLAGS += -fsanitize=undefined # Enable UndefinedBehaviorSanitizer
# CFLAGS += -fno-omit-frame-pointer  # Better stack traces
# CFLAGS += -march=native        # CPU-specific optimizations

# ============================================================================
# BUILD TARGETS
# ============================================================================

# Default target: build all programs
all: conditionals conditionals_buggy switch_demo switch_buggy \
     loops loops_buggy nested_loops loop_control
	@echo ""
	@echo "=========================================="
	@echo "All programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Compiled with: $(CC) $(CFLAGS)"
	@echo ""
	@echo "To run a program: ./conditionals"
	@echo "To compile with clang: make clean && make CC=clang"
	@echo ""

# Compile individual programs
conditionals: conditionals.c
	$(CC) $(CFLAGS) -o conditionals conditionals.c
	@echo "Built: conditionals (correct examples)"

conditionals_buggy: conditionals_buggy.c
	$(CC) $(CFLAGS) -o conditionals_buggy conditionals_buggy.c
	@echo "Built: conditionals_buggy (buggy code for learning)"

switch_demo: switch_demo.c
	$(CC) $(CFLAGS) -o switch_demo switch_demo.c
	@echo "Built: switch_demo (correct examples)"

switch_buggy: switch_buggy.c
	$(CC) $(CFLAGS) -o switch_buggy switch_buggy.c
	@echo "Built: switch_buggy (buggy code for learning)"

loops: loops.c
	$(CC) $(CFLAGS) -o loops loops.c
	@echo "Built: loops (correct examples)"

loops_buggy: loops_buggy.c
	$(CC) $(CFLAGS) -o loops_buggy loops_buggy.c
	@echo "Built: loops_buggy (buggy code for learning)"

nested_loops: nested_loops.c
	$(CC) $(CFLAGS) -o nested_loops nested_loops.c
	@echo "Built: nested_loops (correct examples)"

loop_control: loop_control.c
	$(CC) $(CFLAGS) -o loop_control loop_control.c
	@echo "Built: loop_control (break and continue)"

# ============================================================================
# ALTERNATIVE COMPILATION EXAMPLES
# ============================================================================

# Compile with maximum warnings
strict: CFLAGS += -Werror -Wconversion -Wshadow
strict: all
	@echo "Compiled with strict warnings enabled"

# Compile with debug optimizations
debug: CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O0 -g3 -DDEBUG
debug: all
	@echo "Compiled with debug configuration"

# Compile with release optimizations (no debug symbols)
release: CFLAGS := -std=c11 -Wall -Wextra -O3 -DNDEBUG
release: all
	@echo "Compiled with release configuration (optimized)"

# Compile with AddressSanitizer (memory error detection)
asan: CFLAGS += -fsanitize=address -fno-omit-frame-pointer
asan: all
	@echo "Compiled with AddressSanitizer enabled"

# Compile with UndefinedBehaviorSanitizer
ubsan: CFLAGS += -fsanitize=undefined
ubsan: all
	@echo "Compiled with UndefinedBehaviorSanitizer enabled"

# Compile with clang static analyzer
analyze:
	@echo "Running static analysis with clang..."
	clang --analyze $(CFLAGS) conditionals.c switch_demo.c loops.c \
		nested_loops.c loop_control.c
	@echo "Analysis complete (check for .plist files)"

# ============================================================================
# UTILITY TARGETS
# ============================================================================

# Run all correct programs
run: all
	@echo "\n========== Running: conditionals =========="
	./conditionals
	@echo "\n========== Running: switch_demo =========="
	./switch_demo
	@echo "\n========== Running: loops =========="
	./loops
	@echo "\n========== Running: nested_loops =========="
	./nested_loops
	@echo "\n========== Running: loop_control =========="
	./loop_control

# Run all buggy programs (educational)
run-buggy: conditionals_buggy switch_buggy loops_buggy
	@echo "\n========== Running: conditionals_buggy =========="
	./conditionals_buggy
	@echo "\n========== Running: switch_buggy =========="
	./switch_buggy
	@echo "\n========== Running: loops_buggy =========="
	./loops_buggy

# Clean up compiled files
clean:
	rm -f conditionals conditionals_buggy switch_demo switch_buggy \
		loops loops_buggy nested_loops loop_control
	rm -f *.o *.plist
	@echo "Cleaned up all compiled files"

# Display help
help:
	@echo "Available targets:"
	@echo "  make          - Compile all programs"
	@echo "  make clean    - Remove compiled files"
	@echo "  make run      - Compile and run all correct programs"
	@echo "  make run-buggy - Compile and run buggy programs"
	@echo "  make strict   - Compile with strict warnings"
	@echo "  make debug    - Compile with debug configuration"
	@echo "  make release  - Compile with optimization (no debug)"
	@echo "  make asan     - Compile with AddressSanitizer"
	@echo "  make ubsan    - Compile with UndefinedBehaviorSanitizer"
	@echo "  make analyze  - Run clang static analyzer"
	@echo "  make CC=clang - Use clang instead of gcc"
	@echo ""
	@echo "Example usage:"
	@echo "  make clean && make CC=clang"
	@echo "  make debug"
	@echo "  make CFLAGS='-std=c11 -O3 -Wall'"

# Phony targets (not actual files)
.PHONY: all clean run run-buggy help strict debug release asan ubsan analyze
