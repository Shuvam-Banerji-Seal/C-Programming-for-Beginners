# Makefile for Module 13: Debugging with GDB
# Examples for learning GDB debugging

CC = gcc
# Important: Always use -g for debugging, -O0 to disable optimization
CFLAGS = -std=c11 -Wall -Wextra -g3 -O0

PROGRAMS = debug_example segfault_example watchpoint_example

all: $(PROGRAMS)
	@echo ""
	@echo "=========================================="
	@echo "GDB Debugging examples compiled!"
	@echo "=========================================="
	@echo ""
	@echo "Compiled with debug symbols (-g3 -O0)"
	@echo ""
	@echo "To debug with GDB:"
	@echo "  gdb ./debug_example"
	@echo "  gdb ./segfault_example"
	@echo "  gdb ./watchpoint_example"
	@echo ""
	@echo "Essential GDB commands:"
	@echo "  (gdb) run              - Run program"
	@echo "  (gdb) break main       - Set breakpoint"
	@echo "  (gdb) next             - Step over"
	@echo "  (gdb) step             - Step into"
	@echo "  (gdb) print var        - Print variable"
	@echo "  (gdb) backtrace        - Show call stack"
	@echo "  (gdb) watch var        - Watch variable"
	@echo ""

debug_example: debug_example.c
	$(CC) $(CFLAGS) -o debug_example debug_example.c
	@echo "Built: debug_example (practice basic debugging)"

segfault_example: segfault_example.c
	$(CC) $(CFLAGS) -o segfault_example segfault_example.c
	@echo "Built: segfault_example (practice crash debugging)"

watchpoint_example: watchpoint_example.c
	$(CC) $(CFLAGS) -o watchpoint_example watchpoint_example.c
	@echo "Built: watchpoint_example (practice watchpoints)"

# Run programs normally (not in debugger)
run: all
	@echo "\n========== Running: debug_example =========="
	./debug_example
	@echo "\n========== Running: segfault_example =========="
	./segfault_example
	@echo "\n========== Running: watchpoint_example =========="
	./watchpoint_example

# Interactive GDB tutorial
gdb-tutorial:
	@echo "=== GDB Tutorial ==="
	@echo ""
	@echo "1. Start debugging:"
	@echo "   gdb ./debug_example"
	@echo ""
	@echo "2. Set breakpoint at main:"
	@echo "   (gdb) break main"
	@echo ""
	@echo "3. Run the program:"
	@echo "   (gdb) run"
	@echo ""
	@echo "4. Step through code:"
	@echo "   (gdb) next          # Step over function calls"
	@echo "   (gdb) step          # Step into function calls"
	@echo ""
	@echo "5. Examine variables:"
	@echo "   (gdb) print i"
	@echo "   (gdb) print result"
	@echo ""
	@echo "6. Continue execution:"
	@echo "   (gdb) continue"
	@echo ""
	@echo "7. Quit GDB:"
	@echo "   (gdb) quit"
	@echo ""

# Clean
clean:
	rm -f $(PROGRAMS) *.o
	@echo "Cleaned up compiled files"

# Help
help:
	@echo "Module 13: Debugging with GDB"
	@echo ""
	@echo "Available targets:"
	@echo "  make              - Compile all examples"
	@echo "  make clean        - Remove compiled files"
	@echo "  make run          - Run examples normally"
	@echo "  make gdb-tutorial - Show GDB tutorial"
	@echo ""
	@echo "Programs:"
	@echo "  debug_example      - Basic debugging practice"
	@echo "  segfault_example   - Crash debugging practice"
	@echo "  watchpoint_example - Variable watching practice"
	@echo ""
	@echo "Start debugging:"
	@echo "  gdb ./debug_example"
	@echo ""
	@echo "GDB Quick Reference:"
	@echo "  break <function>   - Set breakpoint"
	@echo "  run                - Start program"
	@echo "  next               - Execute next line"
	@echo "  step               - Step into function"
	@echo "  print <var>        - Print variable"
	@echo "  backtrace          - Show stack trace"
	@echo "  watch <var>        - Watch variable"
	@echo "  info locals        - Show local variables"
	@echo "  info breakpoints   - List breakpoints"
	@echo "  continue           - Continue execution"
	@echo "  quit               - Exit GDB"

.PHONY: all clean run help gdb-tutorial
