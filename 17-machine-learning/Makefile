# Makefile for Module 17: Machine Learning in C
# Simple ML algorithms from scratch

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -g
LDFLAGS = -lm

PROGRAMS = perceptron

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Machine learning programs compiled!"
	@echo "=========================================="
	@echo ""

perceptron: perceptron.c
	$(CC) $(CFLAGS) -o perceptron perceptron.c $(LDFLAGS)
	@echo "Built: perceptron (simple neural network)"

run: all
	@echo "\n========== Running: perceptron =========="
	./perceptron

clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up compiled files"

help:
	@echo "Module 17: Machine Learning in C"
	@echo ""
	@echo "Available targets:"
	@echo "  make       - Compile all programs"
	@echo "  make clean - Remove compiled files"
	@echo "  make run   - Run ML examples"
	@echo ""
	@echo "Programs:"
	@echo "  perceptron - Simple perceptron implementation"

.PHONY: all clean run help
