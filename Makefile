# ============================================================================
# Master Makefile for Complete C Programming Course
# Builds all modules with examples
# ============================================================================
#
# WHAT IS A MAKEFILE?
# -------------------
# A Makefile is a script used by the `make` utility to automate building
# (compiling) programs. Instead of typing long compiler commands by hand,
# you define "targets" (things to build) and "recipes" (how to build them).
# When you type `make` in a terminal, it reads this file and runs the
# appropriate commands.
#
# HOW THIS MAKEFILE WORKS:
# ------------------------
# This is the "root" Makefile for the entire course. It does NOT compile
# C files directly. Instead, it delegates to each module's own Makefile
# using the $(MAKE) -C <directory> pattern (explained below).
#
# Think of it as a manager that tells each module: "go build yourself."
#
# HOW TO USE:
# -----------
#   make              Build every module in the course
#   make clean        Delete all compiled files in every module
#   make <module>     Build just one module, e.g. make 06-pointers
#   make test-gcc     Rebuild everything using GCC to verify it compiles
#   make test-clang   Rebuild everything using Clang to verify it compiles
#   make test-both    Test with both GCC and Clang
#   make help         Show a usage summary
#
# PREREQUISITES:
# --------------
# You need the following installed:
#   - gcc (the GNU C Compiler) and/or clang
#   - make (GNU Make)
#   - Standard C library headers (usually installed with gcc)
#   On Debian/Ubuntu: sudo apt install build-essential
#   On macOS: xcode-select --install
#
# KEY MAKEFILE CONCEPTS USED HERE:
# --------------------------------
# 1. VARIABLES   - Store values for reuse, e.g. MODULES = ...
#                   Referenced with $(VARIABLE_NAME).
# 2. TARGETS     - The name before the colon, e.g. "all:" or "clean:".
#                   You run them with `make <target>`.
# 3. RECIPES     - The indented lines under a target (MUST use a TAB, not
#                   spaces). These are the shell commands Make executes.
# 4. .PHONY      - Tells Make that a target is not a real file. Without
#                   this, if a file named "clean" existed, `make clean`
#                   would do nothing because Make thinks it's up-to-date.
# 5. $(MAKE) -C  - Runs `make` in a subdirectory. The -C flag means
#                   "change to this directory first, then run make there."
#                   $(MAKE) is a special variable that refers to the `make`
#                   command itself, ensuring recursive calls use the same
#                   version of Make.
# 6. @ prefix    - Putting @ before a recipe line suppresses printing the
#                   command itself; only its output is shown. Without @,
#                   Make prints each command before executing it.
# 7. \ (backslash) - At the end of a line, continues the command on the
#                   next line. Used for readability in long lists/loops.
# 8. $$ (double dollar) - In a recipe, $$ produces a literal $ for the
#                   shell. Make uses single $ for its own variables, so
#                   $$module becomes $module when passed to the shell.
#
# ============================================================================

# ----------------------------------------------------------------------------
# MODULES LIST
# ----------------------------------------------------------------------------
# The MODULES variable holds the list of subdirectories to build.
# Each subdirectory must contain its own Makefile that knows how to compile
# the C files inside it. The backslash (\) at the end of each line is a
# line-continuation character so we can spread the list across multiple
# lines for readability.
MODULES = 01-basics \
          02-variables-and-types \
          03-control-flow \
          04-functions \
          05-arrays-and-strings \
          06-pointers \
          07-memory-management \
          08-structures-unions \
          09-file-io \
          10-preprocessor \
          11-data-structures \
          12-advanced-data-structures \
          13-debugging-gdb \
          15-game-projects \
          16-network-programming \
          17-machine-learning \
          19-scientific-computing

# ----------------------------------------------------------------------------
# PHONY TARGETS DECLARATION
# ----------------------------------------------------------------------------
# .PHONY tells Make these targets are NOT real files on disk. They are just
# names for actions. Without .PHONY, if you had a file called "clean" in
# this directory, `make clean` would say "clean is up to date" and skip it.
# We also list $(MODULES) as phony because the module directory names ARE
# real directories, and we always want `make 06-pointers` to run the recipe.
.PHONY: all clean help test $(MODULES)

# ----------------------------------------------------------------------------
# DEFAULT TARGET: all
# ----------------------------------------------------------------------------
# The first target in a Makefile is the "default" — it runs when you type
# `make` with no arguments. Here, "all" loops through every module and
# builds it by calling each module's own Makefile.
all:
	@echo "=========================================="
	@echo "Building All Modules"
	@echo "=========================================="
# Shell for-loop that iterates over each module directory.
# - @        suppresses printing the loop command itself
# - $$module uses $$ so that Make passes a literal $module to the shell
# - $(MAKE) -C $$module  runs `make` inside that module's directory
# - || exit 1  stops the loop immediately if any module fails to build
	@for module in $(MODULES); do \
		echo ""; \
		echo "Building $$module..."; \
		$(MAKE) -C $$module || exit 1; \
	done
	@echo ""
	@echo "=========================================="
	@echo "All modules built successfully!"
	@echo "=========================================="
	@echo ""
	@echo "To run examples, navigate to individual modules:"
	@echo "  cd 03-control-flow && make run"
	@echo "  cd 06-pointers && make run"
	@echo ""
	@echo "For compilation help, see COMPILATION_GUIDE.md"

# ----------------------------------------------------------------------------
# INDIVIDUAL MODULE TARGETS
# ----------------------------------------------------------------------------
# Each target below lets you build a single module by name, e.g.:
#   make 03-control-flow
#
# Pattern used:  $(MAKE) -C <directory>
#   - $(MAKE) is a built-in variable that expands to the path of `make`
#     itself. Using $(MAKE) instead of a hard-coded `make` ensures that
#     recursive builds use the same Make program and inherit flags.
#   - -C <directory> tells Make to change into that directory before
#     reading its Makefile and executing targets.
#   - @ before the command suppresses printing the command line.
# ----------------------------------------------------------------------------

# Module 01: Basics (hello world, compilation fundamentals)
01-basics:
	@echo "Building Module 01: Basics"
	@$(MAKE) -C 01-basics

# Module 02: Variables and Types (int, float, char, etc.)
02-variables-and-types:
	@echo "Building Module 02: Variables and Types"
	@$(MAKE) -C 02-variables-and-types

# Module 03: Control Flow (if/else, switch, loops)
03-control-flow:
	@echo "Building Module 03: Control Flow"
	@$(MAKE) -C 03-control-flow

# Module 06: Pointers (addresses, dereferencing, pointer arithmetic)
06-pointers:
	@echo "Building Module 06: Pointers"
	@$(MAKE) -C 06-pointers

# Module 07: Memory Management (malloc, free, dynamic allocation)
07-memory-management:
	@echo "Building Module 07: Memory Management"
	@$(MAKE) -C 07-memory-management

# Module 08: Structures and Unions (struct, union, typedef)
08-structures-unions:
	@echo "Building Module 08: Structures and Unions"
	@$(MAKE) -C 08-structures-unions

# Module 09: File I/O (reading/writing files with fopen, fread, etc.)
09-file-io:
	@echo "Building Module 09: File I/O"
	@$(MAKE) -C 09-file-io

# Module 10: Preprocessor (#define, #include, macros, conditional compilation)
10-preprocessor:
	@echo "Building Module 10: Preprocessor"
	@$(MAKE) -C 10-preprocessor

# Module 04: Functions (declarations, definitions, scope, recursion)
04-functions:
	@echo "Building Module 04: Functions"
	@$(MAKE) -C 04-functions

# Module 05: Arrays and Strings (arrays, string functions, multidimensional)
05-arrays-and-strings:
	@echo "Building Module 05: Arrays and Strings"
	@$(MAKE) -C 05-arrays-and-strings

# Module 11: Data Structures (linked lists, stacks, queues)
11-data-structures:
	@echo "Building Module 11: Data Structures"
	@$(MAKE) -C 11-data-structures

# Module 12: Advanced Data Structures (trees, hash tables, graphs)
12-advanced-data-structures:
	@echo "Building Module 12: Advanced Data Structures"
	@$(MAKE) -C 12-advanced-data-structures

# Module 13: Debugging with GDB (breakpoints, watchpoints, stepping)
13-debugging-gdb:
	@echo "Building Module 13: Debugging with GDB"
	@$(MAKE) -C 13-debugging-gdb

# Module 15: Game Projects (terminal-based games in C)
15-game-projects:
	@echo "Building Module 15: Game Projects"
	@$(MAKE) -C 15-game-projects

# Module 16: Network Programming (sockets, client-server, HTTP)
16-network-programming:
	@echo "Building Module 16: Network Programming"
	@$(MAKE) -C 16-network-programming

# Module 17: Machine Learning (basic ML algorithms in C)
17-machine-learning:
	@echo "Building Module 17: Machine Learning"
	@$(MAKE) -C 17-machine-learning

# Module 19: Scientific Computing (numerical methods, simulations)
19-scientific-computing:
	@echo "Building Module 19: Scientific Computing"
	@$(MAKE) -C 19-scientific-computing

# ----------------------------------------------------------------------------
# CLEAN TARGET
# ----------------------------------------------------------------------------
# Removes all compiled files (executables, object files, etc.) from every
# module. Uses the same for-loop pattern as the "all" target, but calls
# `make clean` in each subdirectory instead of the default target.
# Note: we don't use || exit 1 here — we want to keep cleaning even if
# one module's clean fails (e.g., if a module has no compiled files).
clean:
	@echo "Cleaning all modules..."
	@for module in $(MODULES); do \
		echo "Cleaning $$module..."; \
		$(MAKE) -C $$module clean; \
	done
	@echo "All modules cleaned!"

# ----------------------------------------------------------------------------
# COMPILER TESTING TARGETS
# ----------------------------------------------------------------------------
# These targets verify that the entire codebase compiles with a specific
# compiler. They first clean everything, then rebuild with CC set to the
# chosen compiler. CC=gcc or CC=clang overrides the CC variable in each
# module's Makefile, so every source file is compiled with that compiler.

# Test compilation with GCC (the GNU Compiler Collection)
test-gcc:
	@echo "Testing compilation with GCC..."
	@$(MAKE) clean
	@$(MAKE) CC=gcc

# Test compilation with Clang (LLVM-based compiler)
test-clang:
	@echo "Testing compilation with Clang..."
	@$(MAKE) clean
	@$(MAKE) CC=clang

# Test with both compilers sequentially (test-gcc runs first, then test-clang)
# "test-gcc test-clang" after the colon are called "prerequisites" — Make
# will run those targets first before executing this target's recipe.
test-both: test-gcc test-clang
	@echo ""
	@echo "Both GCC and Clang compilation successful!"

# ----------------------------------------------------------------------------
# HELP TARGET
# ----------------------------------------------------------------------------
# Displays a user-friendly summary of all available targets and examples.
# This is a common convention in Makefiles — provide a "help" target so
# users can quickly learn how to use the build system.

# Show help
help:
	@echo "Complete C Programming Course - Master Makefile"
	@echo ""
	@echo "Available targets:"
	@echo "  make              - Build all modules"
	@echo "  make clean        - Clean all modules"
	@echo "  make <module>     - Build specific module"
	@echo "  make test-gcc     - Test with GCC"
	@echo "  make test-clang   - Test with Clang"
	@echo "  make test-both    - Test with both compilers"
	@echo "  make help         - Show this help"
	@echo ""
	@echo "Available modules:"
	@for module in $(MODULES); do \
		echo "  - $$module"; \
	done
	@echo ""
	@echo "Example usage:"
	@echo "  make                    # Build everything"
	@echo "  make 06-pointers        # Build pointers module only"
	@echo "  make clean              # Clean all"
	@echo "  cd 03-control-flow      # Navigate to module"
	@echo "  make run                # Run examples in module"
	@echo ""
	@echo "For detailed compilation guide, see: COMPILATION_GUIDE.md"
