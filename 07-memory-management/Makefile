# Makefile for Module 07: Memory Management
# Demonstrates compilation with memory error detection tools

# ============================================================================
# COMPILER CONFIGURATION
# ============================================================================

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

# Memory-specific warnings
# CFLAGS += -Wcast-align              # Warn about alignment issues
# CFLAGS += -Wwrite-strings           # Warn about string literal modifications
# CFLAGS += -Wstack-usage=8192        # Warn if stack usage exceeds limit

# ============================================================================
# BUILD TARGETS
# ============================================================================

all: dynamic_memory memory_buggy stack_vs_heap
	@echo ""
	@echo "=========================================="
	@echo "Memory management programs compiled!"
	@echo "=========================================="
	@echo ""
	@echo "To detect memory errors:"
	@echo "  make valgrind   - Run with Valgrind"
	@echo "  make asan       - Compile with AddressSanitizer"
	@echo ""

dynamic_memory: dynamic_memory.c
	$(CC) $(CFLAGS) -o dynamic_memory dynamic_memory.c
	@echo "Built: dynamic_memory"

memory_buggy: memory_buggy.c
	$(CC) $(CFLAGS) -o memory_buggy memory_buggy.c
	@echo "Built: memory_buggy (educational bugs)"

stack_vs_heap: stack_vs_heap.c
	$(CC) $(CFLAGS) -o stack_vs_heap stack_vs_heap.c
	@echo "Built: stack_vs_heap"

# ============================================================================
# MEMORY ERROR DETECTION
# ============================================================================

# Compile with AddressSanitizer
asan: CFLAGS += -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer
asan: clean all
	@echo ""
	@echo "Built with AddressSanitizer"
	@echo "This detects:"
	@echo "  - Buffer overflows"
	@echo "  - Use-after-free"
	@echo "  - Memory leaks"
	@echo "  - Double-free"
	@echo ""
	@echo "Run: ./dynamic_memory"

# Compile with MemorySanitizer (requires clang)
msan: CC = clang
msan: CFLAGS += -fsanitize=memory -fno-omit-frame-pointer
msan: clean all
	@echo ""
	@echo "Built with MemorySanitizer"
	@echo "Detects use of uninitialized memory"

# Run with Valgrind (external tool)
valgrind: all
	@echo ""
	@echo "Running with Valgrind..."
	@echo "================================"
	@which valgrind > /dev/null 2>&1 || (echo "Valgrind not installed!"; exit 1)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		./dynamic_memory 2>&1 | tee valgrind_output.txt
	@echo ""
	@echo "Output saved to valgrind_output.txt"

# Check for memory leaks in buggy program
check-leaks: memory_buggy
	@echo "Checking memory leaks in buggy program..."
	@which valgrind > /dev/null 2>&1 || (echo "Valgrind not installed!"; exit 1)
	valgrind --leak-check=full ./memory_buggy 2>&1 | grep -A 5 "LEAK SUMMARY"

# ============================================================================
# UTILITY TARGETS
# ============================================================================

run: all
	@echo "\n========== Running: dynamic_memory =========="
	./dynamic_memory
	@echo "\n========== Running: stack_vs_heap =========="
	./stack_vs_heap

run-buggy: memory_buggy
	@echo "\n========== Running: memory_buggy =========="
	@echo "This demonstrates common memory errors (educational):"
	./memory_buggy

clean:
	rm -f dynamic_memory memory_buggy stack_vs_heap
	rm -f *.o valgrind_output.txt
	@echo "Cleaned up compiled files"

help:
	@echo "Module 07: Memory Management - Makefile Help"
	@echo ""
	@echo "Available targets:"
	@echo "  make          - Compile all programs"
	@echo "  make clean    - Remove compiled files"
	@echo "  make run      - Run all correct programs"
	@echo "  make run-buggy - Run buggy program (educational)"
	@echo ""
	@echo "Memory error detection:"
	@echo "  make asan     - Compile with AddressSanitizer"
	@echo "  make msan     - Compile with MemorySanitizer (clang)"
	@echo "  make valgrind - Run with Valgrind"
	@echo "  make check-leaks - Check leaks in buggy program"
	@echo ""
	@echo "Memory debugging tools:"
	@echo "  1. AddressSanitizer (ASan) - Google's memory error detector"
	@echo "     Fast, detects buffer overflows, use-after-free, etc."
	@echo ""
	@echo "  2. MemorySanitizer (MSan) - Detects uninitialized memory"
	@echo "     Available with clang only"
	@echo ""
	@echo "  3. Valgrind - Memory debugging and profiling tool"
	@echo "     Slower but very thorough, detects memory leaks"
	@echo ""
	@echo "Best practices:"
	@echo "  1. Always check malloc/calloc return value"
	@echo "  2. Free all allocated memory"
	@echo "  3. Set pointers to NULL after freeing"
	@echo "  4. Don't use memory after freeing"
	@echo "  5. Avoid buffer overflows"
	@echo "  6. Match malloc/free pairs"

.PHONY: all clean run run-buggy help asan msan valgrind check-leaks
