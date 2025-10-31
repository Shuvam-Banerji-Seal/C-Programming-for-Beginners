# Makefile for Module 06: Pointers
# Demonstrates compilation with gcc and clang with detailed flag explanations

# ============================================================================
# COMPILER CONFIGURATION
# ============================================================================

CC = gcc

# CFLAGS: Compiler flags
CFLAGS = -std=c11        # Use C11 standard
CFLAGS += -Wall          # Enable all common warnings
CFLAGS += -Wextra        # Enable extra warnings
CFLAGS += -Wpedantic     # Enforce strict ISO C compliance
CFLAGS += -O2            # Optimization level 2
CFLAGS += -g             # Include debugging symbols

# Additional useful flags for pointer safety
# CFLAGS += -Wpointer-arith        # Warn about pointer arithmetic
# CFLAGS += -Wcast-qual            # Warn about casting away const
# CFLAGS += -Wcast-align           # Warn about alignment casting
# CFLAGS += -Wnull-dereference     # Warn about NULL pointer dereferences (gcc 6+)
# CFLAGS += -fsanitize=address     # AddressSanitizer (memory errors)
# CFLAGS += -fsanitize=pointer-compare  # Pointer comparison sanitizer
# CFLAGS += -fsanitize=pointer-subtract # Pointer subtraction sanitizer
# CFLAGS += -fstack-protector-strong    # Stack protection

# ============================================================================
# BUILD TARGETS
# ============================================================================

all: pointer_basics pointer_basics_buggy pointer_arithmetic \
     pointers_arrays pointer_to_pointer pointers_functions
	@echo ""
	@echo "=========================================="
	@echo "All pointer programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Compiled with: $(CC) $(CFLAGS)"
	@echo ""

# Individual targets
pointer_basics: pointer_basics.c
	$(CC) $(CFLAGS) -o pointer_basics pointer_basics.c
	@echo "Built: pointer_basics"

pointer_basics_buggy: pointer_basics_buggy.c
	$(CC) $(CFLAGS) -o pointer_basics_buggy pointer_basics_buggy.c
	@echo "Built: pointer_basics_buggy (buggy code for learning)"

pointer_arithmetic: pointer_arithmetic.c
	$(CC) $(CFLAGS) -o pointer_arithmetic pointer_arithmetic.c
	@echo "Built: pointer_arithmetic"

pointers_arrays: pointers_arrays.c
	$(CC) $(CFLAGS) -o pointers_arrays pointers_arrays.c
	@echo "Built: pointers_arrays"

pointer_to_pointer: pointer_to_pointer.c
	$(CC) $(CFLAGS) -o pointer_to_pointer pointer_to_pointer.c
	@echo "Built: pointer_to_pointer"

pointers_functions: pointers_functions.c
	$(CC) $(CFLAGS) -o pointers_functions pointers_functions.c
	@echo "Built: pointers_functions"

# ============================================================================
# SPECIAL BUILDS FOR POINTER SAFETY
# ============================================================================

# Build with AddressSanitizer (detects memory errors)
asan: CFLAGS += -fsanitize=address -fno-omit-frame-pointer
asan: all
	@echo ""
	@echo "Built with AddressSanitizer enabled"
	@echo "This will detect:"
	@echo "  - Buffer overflows"
	@echo "  - Use-after-free"
	@echo "  - Double-free"
	@echo "  - Memory leaks"

# Build with pointer sanitizers
psan: CFLAGS += -fsanitize=pointer-compare -fsanitize=pointer-subtract
psan: all
	@echo ""
	@echo "Built with pointer sanitizers enabled"

# Build with all sanitizers
allsan: CFLAGS += -fsanitize=address,undefined,pointer-compare,pointer-subtract
allsan: CFLAGS += -fno-omit-frame-pointer
allsan: all
	@echo ""
	@echo "Built with all sanitizers enabled"

# Build with strict pointer warnings
strict: CFLAGS += -Wpointer-arith -Wcast-qual -Wcast-align
strict: CFLAGS += -Wnull-dereference -Werror
strict: all
	@echo ""
	@echo "Built with strict pointer warnings"

# ============================================================================
# UTILITY TARGETS
# ============================================================================

# Run all correct programs
run: all
	@echo "\n========== Running: pointer_basics =========="
	./pointer_basics
	@echo "\n========== Running: pointer_arithmetic =========="
	./pointer_arithmetic
	@echo "\n========== Running: pointers_arrays =========="
	./pointers_arrays
	@echo "\n========== Running: pointer_to_pointer =========="
	./pointer_to_pointer
	@echo "\n========== Running: pointers_functions =========="
	./pointers_functions

# Run buggy program (educational)
run-buggy: pointer_basics_buggy
	@echo "\n========== Running: pointer_basics_buggy =========="
	./pointer_basics_buggy

# Clean compiled files
clean:
	rm -f pointer_basics pointer_basics_buggy pointer_arithmetic \
		pointers_arrays pointer_to_pointer pointers_functions
	rm -f *.o *.plist
	@echo "Cleaned up all compiled files"

# Display help
help:
	@echo "Module 06: Pointers - Makefile Help"
	@echo ""
	@echo "Available targets:"
	@echo "  make          - Compile all programs"
	@echo "  make clean    - Remove compiled files"
	@echo "  make run      - Compile and run all correct programs"
	@echo "  make run-buggy - Compile and run buggy program"
	@echo "  make asan     - Compile with AddressSanitizer"
	@echo "  make psan     - Compile with pointer sanitizers"
	@echo "  make allsan   - Compile with all sanitizers"
	@echo "  make strict   - Compile with strict pointer warnings"
	@echo "  make CC=clang - Use clang instead of gcc"
	@echo ""
	@echo "Pointer Safety Tips:"
	@echo "  1. Always initialize pointers (or set to NULL)"
	@echo "  2. Check for NULL before dereferencing"
	@echo "  3. Free dynamically allocated memory"
	@echo "  4. Set pointers to NULL after freeing"
	@echo "  5. Don't return pointers to local variables"
	@echo "  6. Be careful with pointer arithmetic"
	@echo ""
	@echo "Example usage:"
	@echo "  make clean && make"
	@echo "  make clean && make CC=clang asan"
	@echo "  make strict"

# Test with both gcc and clang
test-both:
	@echo "Testing with GCC..."
	@make clean > /dev/null
	@make CC=gcc > /dev/null
	@echo "GCC compilation successful!"
	@echo ""
	@echo "Testing with Clang..."
	@make clean > /dev/null
	@make CC=clang > /dev/null
	@echo "Clang compilation successful!"
	@echo ""
	@echo "Both compilers work correctly!"

.PHONY: all clean run run-buggy help asan psan allsan strict test-both
