# Makefile for Module 16: Network Programming
# TCP/IP socket programming examples

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -g

PROGRAMS = tcp_server tcp_client

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "Network programs compiled successfully!"
	@echo "=========================================="
	@echo ""
	@echo "Usage:"
	@echo "  Terminal 1: ./tcp_server"
	@echo "  Terminal 2: ./tcp_client"
	@echo ""

tcp_server: tcp_server.c
	$(CC) $(CFLAGS) -o tcp_server tcp_server.c
	@echo "Built: tcp_server"

tcp_client: tcp_client.c
	$(CC) $(CFLAGS) -o tcp_client tcp_client.c
	@echo "Built: tcp_client"

clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up compiled files"

help:
	@echo "Module 16: Network Programming"
	@echo ""
	@echo "Available targets:"
	@echo "  make       - Compile all programs"
	@echo "  make clean - Remove compiled files"
	@echo ""
	@echo "Programs:"
	@echo "  tcp_server - TCP server example"
	@echo "  tcp_client - TCP client example"
	@echo ""
	@echo "To test:"
	@echo "  1. Run server: ./tcp_server"
	@echo "  2. Run client: ./tcp_client (in another terminal)"

.PHONY: all clean help
