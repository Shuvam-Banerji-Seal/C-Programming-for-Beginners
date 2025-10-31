# Makefile for Module 02: Variables and Data Types
# Examples of C data types, operators, and type conversions

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

PROGRAMS = simple_int_printing data_types sizeof_demo operators \
           increment_decrement type_conversion

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Module 02 programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Run individual programs to explore:"
	@echo "  ./data_types"
	@echo "  ./operators"
	@echo "  ./sizeof_demo"
	@echo ""

simple_int_printing: simple_int_printing.c
	$(CC) $(CFLAGS) -o simple_int_printing simple_int_printing.c
	@echo "Built: simple_int_printing"

data_types: data_types.c
	$(CC) $(CFLAGS) -o data_types data_types.c
	@echo "Built: data_types (all C data types)"

sizeof_demo: sizeof_demo.c
	$(CC) $(CFLAGS) -o sizeof_demo sizeof_demo.c
	@echo "Built: sizeof_demo (memory sizes)"

operators: operators.c
	$(CC) $(CFLAGS) -o operators operators.c
	@echo "Built: operators (arithmetic, logical, bitwise)"

increment_decrement: increment_decrement.c
	$(CC) $(CFLAGS) -o increment_decrement increment_decrement.c
	@echo "Built: increment_decrement (++/--)"

type_conversion: type_conversion.c
	$(CC) $(CFLAGS) -o type_conversion type_conversion.c
	@echo "Built: type_conversion (casting)"

# Run all programs
run: all
	@echo "\n========== Running: data_types =========="
	./data_types
	@echo "\n========== Running: sizeof_demo =========="
	./sizeof_demo
	@echo "\n========== Running: operators =========="
	./operators

clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up all compiled files"

help:
	@echo "Module 02: Variables and Data Types"
	@echo ""
	@echo "Available targets:"
	@echo "  make       - Compile all programs"
	@echo "  make clean - Remove compiled files"
	@echo "  make run   - Run main programs"
	@echo ""
	@echo "Programs explore:"
	@echo "  - Primitive data types (int, float, char, double)"
	@echo "  - Type sizes and ranges"
	@echo "  - Operators (arithmetic, logical, bitwise)"
	@echo "  - Type conversion and casting"
	@echo "  - Increment/decrement operators"

.PHONY: all clean run help
