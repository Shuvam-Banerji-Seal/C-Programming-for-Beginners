# Makefile for Module 04: Functions
# Examples of function declaration, definition, and usage

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

PROGRAMS = basic_functions pass_by_value_reference recursion_examples \
           scope_lifetime function_pointers

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Module 04 programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Explore function concepts:"
	@echo "  ./basic_functions"
	@echo "  ./recursion_examples"
	@echo "  ./function_pointers"
	@echo ""

basic_functions: basic_functions.c
	$(CC) $(CFLAGS) -o basic_functions basic_functions.c
	@echo "Built: basic_functions"

pass_by_value_reference: pass_by_value_reference.c
	$(CC) $(CFLAGS) -o pass_by_value_reference pass_by_value_reference.c
	@echo "Built: pass_by_value_reference"

recursion_examples: recursion_examples.c
	$(CC) $(CFLAGS) -o recursion_examples recursion_examples.c
	@echo "Built: recursion_examples"

scope_lifetime: scope_lifetime.c
	$(CC) $(CFLAGS) -o scope_lifetime scope_lifetime.c
	@echo "Built: scope_lifetime"

function_pointers: function_pointers.c
	$(CC) $(CFLAGS) -o function_pointers function_pointers.c
	@echo "Built: function_pointers"

# Run all programs
run: all
	@echo "\n========== Running: basic_functions =========="
	./basic_functions
	@echo "\n========== Running: recursion_examples =========="
	./recursion_examples
	@echo "\n========== Running: function_pointers =========="
	./function_pointers

clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up all compiled files"

help:
	@echo "Module 04: Functions"
	@echo ""
	@echo "Available targets:"
	@echo "  make       - Compile all programs"
	@echo "  make clean - Remove compiled files"
	@echo "  make run   - Run all programs"
	@echo ""
	@echo "Topics covered:"
	@echo "  - Function declaration and definition"
	@echo "  - Parameters and return values"
	@echo "  - Pass by value vs reference"
	@echo "  - Recursion"
	@echo "  - Scope and lifetime"
	@echo "  - Function pointers"

.PHONY: all clean run help
