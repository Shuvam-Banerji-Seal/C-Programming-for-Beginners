# Makefile for Module 09: File I/O

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

all: file_operations advanced_file_io file_processing
	@echo ""
	@echo "=========================================="
	@echo "Module 09 programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Run programs:"
	@echo "  ./file_operations"
	@echo "  ./advanced_file_io"
	@echo "  ./file_processing"
	@echo ""

file_operations: file_operations.c
	$(CC) $(CFLAGS) -o file_operations file_operations.c

advanced_file_io: advanced_file_io.c
	$(CC) $(CFLAGS) -o advanced_file_io advanced_file_io.c

file_processing: file_processing.c
	$(CC) $(CFLAGS) -o file_processing file_processing.c

clean:
	rm -f file_operations advanced_file_io file_processing *.o *.txt *.dat *.csv *.bin

.PHONY: all clean
