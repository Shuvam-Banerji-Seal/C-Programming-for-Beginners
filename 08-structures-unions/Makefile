# Makefile for Module 08: Structures and Unions

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

all: structures_demo unions_demo
	@echo "All structures/unions programs compiled!"

structures_demo: structures_demo.c
	$(CC) $(CFLAGS) -o structures_demo structures_demo.c

unions_demo: unions_demo.c
	$(CC) $(CFLAGS) -o unions_demo unions_demo.c

clean:
	rm -f structures_demo unions_demo *.o

.PHONY: all clean
