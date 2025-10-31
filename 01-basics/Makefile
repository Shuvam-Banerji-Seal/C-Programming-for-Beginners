# Makefile for Module 01: Getting Started with C
# Basic compilation examples for beginners

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

# Programs to build
PROGRAMS = hello_world hello_user basic_io compilation_demo

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Module 01 programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Compiled with: $(CC) $(CFLAGS)"
	@echo ""
	@echo "To run programs:"
	@echo "  ./hello_world"
	@echo "  ./hello_user"
	@echo "  ./basic_io"
	@echo "  ./compilation_demo"
	@echo ""

hello_world: hello_world.c
	$(CC) $(CFLAGS) -o hello_world hello_world.c
	@echo "Built: hello_world (your first C program)"

hello_user: hello_user.c
	$(CC) $(CFLAGS) -o hello_user hello_user.c
	@echo "Built: hello_user (user input)"

basic_io: basic_io.c
	$(CC) $(CFLAGS) -o basic_io basic_io.c
	@echo "Built: basic_io (input/output examples)"

compilation_demo: compilation_demo.c
	$(CC) $(CFLAGS) -o compilation_demo compilation_demo.c
	@echo "Built: compilation_demo (compilation process)"

# Show compilation steps for hello_world
steps: hello_world.c
	@echo "=== Compilation Steps for hello_world.c ==="
	@echo ""
	@echo "1. Preprocessing:"
	$(CC) -E hello_world.c -o hello_world.i
	@echo "   Created: hello_world.i (preprocessed)"
	@echo ""
	@echo "2. Compilation (to assembly):"
	$(CC) -S hello_world.c -o hello_world.s
	@echo "   Created: hello_world.s (assembly)"
	@echo ""
	@echo "3. Assembly (to object code):"
	$(CC) -c hello_world.c -o hello_world.o
	@echo "   Created: hello_world.o (object file)"
	@echo ""
	@echo "4. Linking:"
	$(CC) hello_world.o -o hello_world
	@echo "   Created: hello_world (executable)"
	@echo ""
	@echo "Intermediate files created for demonstration"

# Run all programs
run: all
	@echo "\n========== Running: hello_world =========="
	./hello_world
	@echo "\n========== Running: compilation_demo =========="
	./compilation_demo

# Clean compiled files
clean:
	rm -f $(PROGRAMS) *.o *.i *.s
	@echo "Cleaned up all compiled files"

# Help
help:
	@echo "Module 01: Getting Started with C"
	@echo ""
	@echo "Available targets:"
	@echo "  make          - Compile all programs"
	@echo "  make clean    - Remove compiled files"
	@echo "  make run      - Run programs"
	@echo "  make steps    - Show compilation steps"
	@echo "  make CC=clang - Use Clang compiler"
	@echo ""
	@echo "Programs:"
	@echo "  hello_world      - Classic 'Hello, World!'"
	@echo "  hello_user       - Get user input"
	@echo "  basic_io         - Input/output examples"
	@echo "  compilation_demo - Understand compilation"

.PHONY: all clean run help steps
