# Makefile for Module 09: File I/O

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

all: file_operations
	@echo "File I/O programs compiled!"

file_operations: file_operations.c
	$(CC) $(CFLAGS) -o file_operations file_operations.c

clean:
	rm -f file_operations *.o test.txt data.bin

.PHONY: all clean
