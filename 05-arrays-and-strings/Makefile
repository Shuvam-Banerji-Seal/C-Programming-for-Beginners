# Makefile for Module 05: Arrays and Strings
# Examples of array and string manipulation

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

PROGRAMS = array_algorithms string_operations multidimensional_arrays advanced_strings

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Module 05 programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Run programs to explore arrays and strings:"
	@echo "  ./array_algorithms"
	@echo "  ./string_operations"
	@echo "  ./multidimensional_arrays"
	@echo "  ./advanced_strings"
	@echo ""

array_algorithms: array_algorithms.c
	$(CC) $(CFLAGS) -o array_algorithms array_algorithms.c
	@echo "Built: array_algorithms"

string_operations: string_operations.c
	$(CC) $(CFLAGS) -o string_operations string_operations.c
	@echo "Built: string_operations"

multidimensional_arrays: multidimensional_arrays.c
	$(CC) $(CFLAGS) -o multidimensional_arrays multidimensional_arrays.c
	@echo "Built: multidimensional_arrays"

advanced_strings: advanced_strings.c
	$(CC) $(CFLAGS) -o advanced_strings advanced_strings.c
	@echo "Built: advanced_strings"

run: all
	@echo "\n========== Running: array_algorithms =========="
	./array_algorithms
	@echo "\n========== Running: string_operations =========="
	./string_operations
	@echo "\n========== Running: multidimensional_arrays =========="
	./multidimensional_arrays
	@echo "\n========== Running: advanced_strings =========="
	./advanced_strings

clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up all compiled files"

help:
	@echo "Module 05: Arrays and Strings"
	@echo ""
	@echo "Available targets:"
	@echo "  make       - Compile all programs"
	@echo "  make clean - Remove compiled files"
	@echo "  make run   - Run all programs"
	@echo ""
	@echo "Topics covered:"
	@echo "  - One-dimensional arrays"
	@echo "  - Multi-dimensional arrays"
	@echo "  - Array algorithms"
	@echo "  - Character arrays and strings"
	@echo "  - String manipulation"

.PHONY: all clean run help
