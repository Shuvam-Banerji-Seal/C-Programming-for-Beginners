# Makefile for Module 15: Game Projects
# Simple game implementations

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -g

PROGRAMS = tictactoe

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Game projects compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Play the games:"
	@echo "  ./tictactoe"
	@echo ""

tictactoe: tictactoe.c
	$(CC) $(CFLAGS) -o tictactoe tictactoe.c
	@echo "Built: tictactoe (Tic-Tac-Toe game)"

run: all
	@echo "\n========== Running: tictactoe =========="
	./tictactoe

clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up compiled files"

help:
	@echo "Module 15: Game Projects"
	@echo ""
	@echo "Available targets:"
	@echo "  make       - Compile all games"
	@echo "  make clean - Remove compiled files"
	@echo "  make run   - Play games"
	@echo ""
	@echo "Games:"
	@echo "  tictactoe  - Classic Tic-Tac-Toe"

.PHONY: all clean run help
