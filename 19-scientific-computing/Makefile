# Makefile for Module 19: Scientific Computing
# Numerical methods and simulations

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -g
LDFLAGS = -lm

PROGRAMS = molecular_dynamics

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Scientific computing programs compiled!"
	@echo "=========================================="
	@echo ""

molecular_dynamics: molecular_dynamics.c
	$(CC) $(CFLAGS) -o molecular_dynamics molecular_dynamics.c $(LDFLAGS)
	@echo "Built: molecular_dynamics (physics simulation)"

run: all
	@echo "\n========== Running: molecular_dynamics =========="
	./molecular_dynamics

clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up compiled files"

help:
	@echo "Module 19: Scientific Computing"
	@echo ""
	@echo "Available targets:"
	@echo "  make       - Compile all programs"
	@echo "  make clean - Remove compiled files"
	@echo "  make run   - Run simulations"
	@echo ""
	@echo "Programs:"
	@echo "  molecular_dynamics - Particle physics simulation"

.PHONY: all clean run help
