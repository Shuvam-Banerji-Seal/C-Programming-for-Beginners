# Contributing to C Programming for Beginners

Thank you for your interest in contributing to this project. This guide covers
everything you need to get started.

## Table of Contents

1. [Development Environment Setup](#development-environment-setup)
2. [Code Style Guidelines](#code-style-guidelines)
3. [Adding a New Module](#adding-a-new-module)
4. [Compiling and Testing](#compiling-and-testing)
5. [Creating Buggy Examples](#creating-buggy-examples)
6. [Pull Request Guidelines](#pull-request-guidelines)
7. [Reporting Issues](#reporting-issues)

## Development Environment Setup

**Required tools:**

- GCC (>= 9.0) or Clang (>= 10.0), GNU Make, Git
- A text editor or IDE with C support

**Optional tools:**

- GDB, Valgrind, Doxygen, LaTeX (for PDF notes)

**Quick start:**

```bash
git clone <repository-url>
cd C-Programming-for-Beginners
make          # Build all modules
make clean    # Remove all compiled files
```

## Code Style Guidelines

### Indentation and Formatting

- Use **4 spaces** for indentation (no tabs).
- Place opening braces on the same line as the statement.
- Use blank lines to separate logical sections.

### File Headers

Every `.c` file must begin with a block comment:

```c
/*
 * filename.c
 * Brief description of what this file demonstrates
 */
```

### Section Comments

Use section-style comments to divide code into logical parts:

```c
// BUG #1: Description of the issue
// This explains what went wrong and why
```

### Compiler Standard

All code targets **C11**. Compile with:

```
-std=c11 -Wall -Wextra -Wpedantic -O2 -g
```

### Naming

- Use `snake_case` for variables, functions, and file names.
- Use `UPPER_CASE` for macros and constants.
- Use descriptive names that a beginner can understand.

## Adding a New Module

### Directory Structure

Modules are numbered sequentially (`01-basics`, `02-variables-and-types`, etc.).
Each module directory must contain:

```
NN-module-name/
    README.md       # Explanation and learning objectives
    Makefile        # Build rules for all programs in this module
    example.c       # One or more example source files
```

### Makefile Template

```makefile
# Makefile for Module NN: Module Title

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g

PROGRAMS = program1 program2

all: $(PROGRAMS)

program1: program1.c
	$(CC) $(CFLAGS) -o program1 program1.c

program2: program2.c
	$(CC) $(CFLAGS) -o program2 program2.c

clean:
	rm -f $(PROGRAMS) *.o

.PHONY: all clean
```

### README Template

Each module README should include a title, learning objectives, concept
explanations, and build/run instructions.

### Registration

1. Add the module to the `MODULES` list in the root `Makefile`.
2. Add compiled binary names to `.gitignore` under a comment for the module.

## Compiling and Testing

The root `Makefile` builds every module:

```bash
make              # Build all modules
make clean        # Clean all build artifacts
make -C 01-basics # Build a single module
```

For detailed compiler flag explanations, see `COMPILATION_GUIDE.md`.

Before submitting, confirm that `make clean && make` succeeds with no warnings
from the root directory and that each new program runs correctly.

## Creating Buggy Examples

Buggy examples are a core teaching tool in this project. They demonstrate common
mistakes so students can learn to recognize and fix them.

### Naming Convention

Buggy files use the suffix `_buggy.c`:

```
conditionals.c        # Correct version
conditionals_buggy.c  # Version with deliberate bugs
```

### Required Structure

```c
/*
 * example_buggy.c
 * DELIBERATELY BUGGY CODE - For learning purposes
 *
 * This file contains common mistakes with <topic>.
 * Each bug is explained with comments.
 */
```

Each bug must be numbered (BUG #1, BUG #2, ...), accompanied by a comment
explaining the mistake and the correct alternative, and represent a realistic
mistake that beginners actually make.

Add the compiled buggy binary name to `.gitignore`.

## Pull Request Guidelines

1. **One topic per PR.** Do not mix unrelated changes.
2. **Follow the code style** described above.
3. **Build cleanly.** Run `make clean && make` from the repository root.
4. **Write a clear description.** Explain what the PR adds or fixes and why.
5. **Update documentation.** If you add a module, update the root README and
   `.gitignore` as needed.
6. **Keep commits focused.** Each commit should represent a single logical change
   with a descriptive message.

## Reporting Issues

When opening an issue, please include:

- **Summary:** A clear, one-line description of the problem.
- **Module:** Which module or file is affected (e.g., `03-control-flow/loops.c`).
- **Steps to reproduce:** Exact commands to trigger the issue.
- **Expected behavior:** What should happen.
- **Actual behavior:** What happens instead.
- **Environment:** OS, compiler version (`gcc --version`), and architecture.

For feature requests, describe the proposed module or example and explain how it
fits into the course structure.

## License

By contributing, you agree that your contributions will be licensed under the
same license as the rest of the project. See the `LICENSE` file for details.