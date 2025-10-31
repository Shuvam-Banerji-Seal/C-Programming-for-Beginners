# Makefile for Module 08: Structures and Unions

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

all: structures_demo unions_demo advanced_structures bitfields_and_unions
	@echo ""
	@echo "=========================================="
	@echo "Module 08 programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Run programs:"
	@echo "  ./structures_demo"
	@echo "  ./unions_demo"
	@echo "  ./advanced_structures"
	@echo "  ./bitfields_and_unions"
	@echo ""

structures_demo: structures_demo.c
	$(CC) $(CFLAGS) -o structures_demo structures_demo.c

unions_demo: unions_demo.c
	$(CC) $(CFLAGS) -o unions_demo unions_demo.c

advanced_structures: advanced_structures.c
	$(CC) $(CFLAGS) -o advanced_structures advanced_structures.c

bitfields_and_unions: bitfields_and_unions.c
	$(CC) $(CFLAGS) -o bitfields_and_unions bitfields_and_unions.c

clean:
	rm -f structures_demo unions_demo advanced_structures bitfields_and_unions *.o

.PHONY: all clean
