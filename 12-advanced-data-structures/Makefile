# Makefile for Module 12: Advanced Data Structures
# Binary search trees and advanced structures

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

PROGRAMS = bst

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Module 12 programs compiled successfully!"
	@echo "=========================================="
	@echo ""

bst: bst.c
	$(CC) $(CFLAGS) -o bst bst.c
	@echo "Built: bst (Binary Search Tree)"

run: all
	@echo "\n========== Running: bst =========="
	./bst

clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up all compiled files"

help:
	@echo "Module 12: Advanced Data Structures"
	@echo ""
	@echo "Available targets:"
	@echo "  make       - Compile all programs"
	@echo "  make clean - Remove compiled files"
	@echo "  make run   - Run programs"
	@echo ""
	@echo "Topics covered:"
	@echo "  - Binary Search Trees"
	@echo "  - Tree traversal"
	@echo "  - AVL Trees (advanced)"
	@echo "  - Heaps and Priority Queues"

.PHONY: all clean run help
