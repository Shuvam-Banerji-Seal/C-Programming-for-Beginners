# Makefile for Module 10: Preprocessor

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

all: preprocessor_demo advanced_preprocessor conditional_compilation
	@echo ""
	@echo "=========================================="
	@echo "Module 10 programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Run programs:"
	@echo "  ./preprocessor_demo"
	@echo "  ./advanced_preprocessor"
	@echo "  ./conditional_compilation"
	@echo ""

preprocessor_demo: preprocessor_demo.c
	$(CC) $(CFLAGS) -o preprocessor_demo preprocessor_demo.c

advanced_preprocessor: advanced_preprocessor.c
	$(CC) $(CFLAGS) -o advanced_preprocessor advanced_preprocessor.c

conditional_compilation: conditional_compilation.c
	$(CC) $(CFLAGS) -o conditional_compilation conditional_compilation.c

# Show preprocessor output
preprocess: preprocessor_demo.c
	$(CC) -E preprocessor_demo.c -o preprocessor_demo.i
	@echo "Preprocessed output saved to preprocessor_demo.i"

clean:
	rm -f preprocessor_demo advanced_preprocessor conditional_compilation *.i *.o

.PHONY: all clean preprocess
