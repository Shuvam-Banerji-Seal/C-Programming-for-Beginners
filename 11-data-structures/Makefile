# Makefile for Module 11: Data Structures

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

all: linked_list stack
	@echo "Data structures programs compiled!"

linked_list: linked_list.c
	$(CC) $(CFLAGS) -o linked_list linked_list.c

stack: stack.c
	$(CC) $(CFLAGS) -o stack stack.c

clean:
	rm -f linked_list stack *.o

.PHONY: all clean
