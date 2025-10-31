# Makefile for Module 10: Preprocessor

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

all: preprocessor_demo
	@echo "Preprocessor programs compiled!"

preprocessor_demo: preprocessor_demo.c
	$(CC) $(CFLAGS) -o preprocessor_demo preprocessor_demo.c

# Show preprocessor output
preprocess: preprocessor_demo.c
	$(CC) -E preprocessor_demo.c -o preprocessor_demo.i
	@echo "Preprocessed output saved to preprocessor_demo.i"

clean:
	rm -f preprocessor_demo preprocessor_demo.i *.o

.PHONY: all clean preprocess
