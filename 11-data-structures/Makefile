# Makefile for Module 11: Data Structures

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

all: linked_list stack doubly_linked_list hash_table
	@echo ""
	@echo "=========================================="
	@echo "Module 11 programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Run programs:"
	@echo "  ./linked_list"
	@echo "  ./stack"
	@echo "  ./doubly_linked_list"
	@echo "  ./hash_table"
	@echo ""

linked_list: linked_list.c
	$(CC) $(CFLAGS) -o linked_list linked_list.c

stack: stack.c
	$(CC) $(CFLAGS) -o stack stack.c

doubly_linked_list: doubly_linked_list.c
	$(CC) $(CFLAGS) -o doubly_linked_list doubly_linked_list.c

hash_table: hash_table.c
	$(CC) $(CFLAGS) -o hash_table hash_table.c

clean:
	rm -f linked_list stack doubly_linked_list hash_table *.o

.PHONY: all clean
