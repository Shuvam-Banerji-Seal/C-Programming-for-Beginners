# Module 13: Debugging with GDB 🐛

Master the GNU Debugger (GDB) for efficient debugging and problem-solving!

## 📚 What You'll Learn

1. Introduction to GDB
2. Setting breakpoints and watchpoints
3. Stepping through code
4. Examining variables and memory
5. Advanced GDB techniques
6. Debugging memory issues

## 🎯 Introduction to GDB

GDB (GNU Debugger) is a powerful tool for debugging C programs. It allows you to:
- Pause program execution at specific points
- Examine variable values
- Step through code line by line
- Inspect memory and registers
- Analyze crashes and core dumps

### Compiling for Debug

Always compile with debug symbols (`-g` flag):

```bash
gcc -g -o program program.c
```

## 🔧 Basic GDB Commands

### Starting GDB

```bash
# Start GDB with your program
gdb ./program

# Or with arguments
gdb --args ./program arg1 arg2

# Run the program
(gdb) run

# Run with arguments
(gdb) run arg1 arg2
```

### Essential Commands Cheat Sheet

```
Command         Short   Description
-------         -----   -----------
run             r       Start/restart program
break           b       Set breakpoint
continue        c       Continue execution
next            n       Step over (next line)
step            s       Step into (enter functions)
print           p       Print variable value
list            l       Show source code
quit            q       Exit GDB
help            h       Get help
backtrace       bt      Show call stack
info            i       Show information
```

## 🎯 Setting Breakpoints

### Basic Breakpoints

```bash
# Break at function
(gdb) break main
(gdb) break functionName

# Break at line number
(gdb) break 25
(gdb) break file.c:25

# Break at condition
(gdb) break 25 if x > 10

# List all breakpoints
(gdb) info breakpoints

# Delete breakpoint
(gdb) delete 1

# Disable/enable breakpoint
(gdb) disable 1
(gdb) enable 1
```

### Watchpoints

Watch when a variable changes:

```bash
# Watch variable
(gdb) watch myVar

# Watch expression
(gdb) watch myVar > 100

# Read watchpoint
(gdb) rwatch myVar

# Access watchpoint (read or write)
(gdb) awatch myVar
```

## 🚶 Stepping Through Code

```bash
# Step to next line (skip function calls)
(gdb) next
(gdb) n

# Step into function calls
(gdb) step
(gdb) s

# Continue until current function returns
(gdb) finish

# Continue to next iteration of loop
(gdb) until

# Continue execution
(gdb) continue
(gdb) c
```

## 🔍 Examining Variables

### Print Variables

```bash
# Print variable
(gdb) print myVar
(gdb) p myVar

# Print with format
(gdb) p/x myVar    # Hexadecimal
(gdb) p/d myVar    # Decimal
(gdb) p/t myVar    # Binary
(gdb) p/c myVar    # Character
(gdb) p/f myVar    # Float

# Print array
(gdb) p myArray
(gdb) p myArray[0]@10  # First 10 elements

# Print structure
(gdb) p myStruct
(gdb) p myStruct.field
```

### Display Variables

Auto-display after each step:

```bash
# Display variable
(gdb) display myVar

# List displays
(gdb) info display

# Delete display
(gdb) undisplay 1
```

## 🧠 Examining Memory

```bash
# Examine memory
(gdb) x/10x address    # 10 hex values
(gdb) x/10d address    # 10 decimal values
(gdb) x/10s address    # 10 strings
(gdb) x/10i address    # 10 instructions

# Format: x/[count][format][size] address
# Formats: x(hex) d(decimal) s(string) i(instruction)
# Sizes: b(byte) h(halfword) w(word) g(giant/8bytes)
```

## 📊 Call Stack

```bash
# Show backtrace
(gdb) backtrace
(gdb) bt

# Show full backtrace
(gdb) bt full

# Move up/down call stack
(gdb) up
(gdb) down

# Show current frame
(gdb) frame

# Show info about frame
(gdb) info frame
```

## 🐞 Debugging Example

### Sample Program with Bugs

```c
#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);  // Missing base case check
}

int divide(int a, int b) {
    return a / b;  // Potential division by zero
}

int main() {
    int x = 5;
    int *ptr = NULL;
    
    printf("Factorial of %d: %d\n", x, factorial(x));
    
    // Bug: dereferencing NULL pointer
    // printf("Value: %d\n", *ptr);
    
    // Bug: division by zero
    printf("Division: %d\n", divide(10, 0));
    
    // Bug: memory leak
    int *arr = (int*)malloc(10 * sizeof(int));
    // No free(arr)
    
    return 0;
}
```

### GDB Session Example

```bash
$ gcc -g -o debug debug.c
$ gdb ./debug

(gdb) break main
Breakpoint 1 at 0x...: file debug.c, line 14.

(gdb) run
Starting program: ./debug
Breakpoint 1, main () at debug.c:14

(gdb) next
(gdb) print x
$1 = 5

(gdb) step  # Step into factorial
factorial (n=5) at debug.c:5

(gdb) backtrace
#0  factorial (n=5) at debug.c:5
#1  0x... in main () at debug.c:16

(gdb) continue
Continuing.
Program received signal SIGFPE, Arithmetic exception.
```

## 🔧 Advanced Techniques

### Core Dumps

```bash
# Enable core dumps
ulimit -c unlimited

# Debug core dump
gdb ./program core

# Analyze
(gdb) bt
(gdb) info registers
```

### Conditional Breakpoints

```bash
# Break only when condition is true
(gdb) break 25 if i == 10

# Break after N hits
(gdb) ignore 1 10  # Ignore first 10 hits
```

### Commands on Breakpoint

```bash
(gdb) break 25
(gdb) commands 1
> print i
> print arr[i]
> continue
> end
```

## 🧪 Debugging Memory Issues

### Valgrind Integration

```bash
# Check for memory leaks
valgrind --leak-check=full ./program

# With GDB
valgrind --vgdb=yes --vgdb-error=0 ./program

# In another terminal
gdb ./program
(gdb) target remote | vgdb
```

### Memory Debugging Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void memoryLeakExample() {
    int *arr = (int*)malloc(100 * sizeof(int));
    // Forgot to free
}

void bufferOverflow() {
    char buffer[10];
    strcpy(buffer, "This is way too long!");  // Buffer overflow
}

void useAfterFree() {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 42;
    free(ptr);
    printf("%d\n", *ptr);  // Use after free
}

int main() {
    memoryLeakExample();
    return 0;
}
```

## 📖 GDB Tips and Tricks

### Useful Settings

```bash
# Pretty print structures
(gdb) set print pretty on

# Show array indices
(gdb) set print array-indexes on

# Save history
(gdb) set history save on
(gdb) set history size 10000
```

### Custom Commands

Create `.gdbinit` file:

```gdb
# Auto-display useful info
define hook-stop
    info registers
    x/16xw $rsp
end

# Custom print command
define parray
    set $i = 0
    while $i < $arg1
        print $arg0[$i]
        set $i = $i + 1
    end
end
```

## 📖 Code Examples

1. [debug_example.c](./debug_example.c) - Program with common bugs
2. [memory_errors.c](./memory_errors.c) - Memory-related issues
3. [segfault_demo.c](./segfault_demo.c) - Segmentation fault debugging
4. [gdb_tutorial.sh](./gdb_tutorial.sh) - Step-by-step GDB tutorial script

## ✏️ Exercises

1. Debug a program with null pointer dereference
2. Find and fix a memory leak
3. Debug an infinite recursion
4. Fix a buffer overflow
5. Debug a multi-threaded program
6. Analyze a core dump
7. Debug optimized code (-O2)
8. Create custom GDB commands

## 🎯 Key Takeaways

- Always compile with `-g` flag for debugging
- Use breakpoints strategically
- `print` and `display` are your friends
- Backtrace shows the call stack
- Watchpoints catch variable changes
- Valgrind helps find memory issues
- GDB can attach to running processes
- Learn keyboard shortcuts for efficiency

## 🔜 Next Module

Ready to create GUIs? Head to [Module 14: GTK4 GUI Programming](../14-gtk4-gui/README.md)

---

**Pro Tip**: Create a `.gdbinit` file in your home directory with your favorite settings and commands!
