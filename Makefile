# Master Makefile for Complete C Programming Course
# Builds all modules with examples

# Modules to build
MODULES = 03-control-flow \
          06-pointers \
          07-memory-management \
          08-structures-unions \
          09-file-io \
          10-preprocessor \
          11-data-structures

.PHONY: all clean help test $(MODULES)

# Default target: build all modules
all:
	@echo "=========================================="
	@echo "Building All Modules"
	@echo "=========================================="
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

# Build individual modules
03-control-flow:
	@echo "Building Module 03: Control Flow"
	@$(MAKE) -C 03-control-flow

06-pointers:
	@echo "Building Module 06: Pointers"
	@$(MAKE) -C 06-pointers

07-memory-management:
	@echo "Building Module 07: Memory Management"
	@$(MAKE) -C 07-memory-management

08-structures-unions:
	@echo "Building Module 08: Structures and Unions"
	@$(MAKE) -C 08-structures-unions

09-file-io:
	@echo "Building Module 09: File I/O"
	@$(MAKE) -C 09-file-io

10-preprocessor:
	@echo "Building Module 10: Preprocessor"
	@$(MAKE) -C 10-preprocessor

11-data-structures:
	@echo "Building Module 11: Data Structures"
	@$(MAKE) -C 11-data-structures

# Clean all modules
clean:
	@echo "Cleaning all modules..."
	@for module in $(MODULES); do \
		echo "Cleaning $$module..."; \
		$(MAKE) -C $$module clean; \
	done
	@echo "All modules cleaned!"

# Test compilation with GCC
test-gcc:
	@echo "Testing compilation with GCC..."
	@$(MAKE) clean
	@$(MAKE) CC=gcc

# Test compilation with Clang
test-clang:
	@echo "Testing compilation with Clang..."
	@$(MAKE) clean
	@$(MAKE) CC=clang

# Test both compilers
test-both: test-gcc test-clang
	@echo ""
	@echo "Both GCC and Clang compilation successful!"

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
