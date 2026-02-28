# Makefile for Fundamentals: Error Handling and Defensive Programming
# Compilation and testing of error handling demonstration programs

# ============================================================================
# COMPILER CONFIGURATION
# ============================================================================

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

# Programs to build
PROGRAMS = error_handling defensive_programming

# ============================================================================
# BUILD TARGETS
# ============================================================================

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Error handling programs compiled!"
	@echo "=========================================="
	@echo ""
	@echo "To run programs:"
	@echo "  ./error_handling"
	@echo "  ./defensive_programming"
	@echo ""

error_handling: error_handling.c
	$(CC) $(CFLAGS) -o error_handling error_handling.c
	@echo "Built: error_handling"

defensive_programming: defensive_programming.c
	$(CC) $(CFLAGS) -o defensive_programming defensive_programming.c
	@echo "Built: defensive_programming"

# ============================================================================
# DEBUG AND SANITIZER TARGETS
# ============================================================================

# Build with debug symbols and no optimization
debug: CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O0 -g3
debug: clean all
	@echo ""
	@echo "Built with debug symbols (-O0 -g3)"
	@echo "Use with: gdb ./error_handling"

# Build with AddressSanitizer for memory error detection
asan: CFLAGS += -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer
asan: clean all
	@echo ""
	@echo "Built with AddressSanitizer"
	@echo "Detects buffer overflows, use-after-free, and memory leaks"

# ============================================================================
# RUN TARGETS
# ============================================================================

run: all
	@echo "\n========== Running: error_handling =========="
	./error_handling
	@echo "\n========== Running: defensive_programming =========="
	./defensive_programming

run-error: error_handling
	@echo "\n========== Running: error_handling =========="
	./error_handling

run-defensive: defensive_programming
	@echo "\n========== Running: defensive_programming =========="
	./defensive_programming

# ============================================================================
# UTILITY TARGETS
# ============================================================================

clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up compiled files"

help:
	@echo "Fundamentals: Error Handling and Defensive Programming"
	@echo ""
	@echo "Available targets:"
	@echo "  make              - Compile all programs"
	@echo "  make clean        - Remove compiled files"
	@echo "  make run          - Run all programs"
	@echo "  make run-error    - Run error_handling only"
	@echo "  make run-defensive - Run defensive_programming only"
	@echo "  make debug        - Build with debug symbols"
	@echo "  make asan         - Build with AddressSanitizer"
	@echo ""
	@echo "Programs:"
	@echo "  error_handling         - errno, perror, return codes, file and memory errors"
	@echo "  defensive_programming  - assert, validation, bounds checking, safe strings"

.PHONY: all clean run run-error run-defensive help debug asan
