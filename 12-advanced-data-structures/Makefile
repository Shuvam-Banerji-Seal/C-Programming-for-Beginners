# Makefile for Module 12: Advanced Data Structures
# Binary search trees and advanced structures

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

PROGRAMS = bst graph_algorithms heap_priority_queue

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Module 12 programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Run programs:"
	@echo "  ./bst"
	@echo "  ./graph_algorithms"
	@echo "  ./heap_priority_queue"
	@echo ""

bst: bst.c
	$(CC) $(CFLAGS) -o bst bst.c
	@echo "Built: bst (Binary Search Tree)"

graph_algorithms: graph_algorithms.c
	$(CC) $(CFLAGS) -o graph_algorithms graph_algorithms.c
	@echo "Built: graph_algorithms"

heap_priority_queue: heap_priority_queue.c
	$(CC) $(CFLAGS) -o heap_priority_queue heap_priority_queue.c
	@echo "Built: heap_priority_queue"

run: all
	@echo "\n========== Running: bst =========="
	./bst
	@echo "\n========== Running: graph_algorithms =========="
	./graph_algorithms
	@echo "\n========== Running: heap_priority_queue =========="
	./heap_priority_queue

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
