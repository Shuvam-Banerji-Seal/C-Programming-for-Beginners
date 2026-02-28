# Fundamentals: Error Handling and Defensive Programming

Robust C programs anticipate and handle errors gracefully. This module covers
the core strategies for error handling in C and the defensive programming
techniques that prevent bugs before they happen.

## What You'll Learn

1. Error handling strategies: return codes, errno, perror, strerror
2. Error propagation patterns across function boundaries
3. File I/O and memory allocation error handling
4. Defensive programming with assert, input validation, and bounds checking
5. Safe string operations to prevent buffer overflows

## Error Handling Strategies in C

C does not have exceptions. Instead, errors are communicated through return
values and the global `errno` variable. Understanding these mechanisms is
essential for writing reliable programs.

### Return Codes

The most common error handling pattern in C is returning an integer status code:

- **0** means success
- **Non-zero** (typically negative) means an error occurred
- Different non-zero values can represent different error conditions

```c
#define SUCCESS          0
#define ERR_NULL_PTR    -1
#define ERR_OUT_OF_RANGE -2

int safe_divide(int a, int b, int *result) {
    if (result == NULL) return ERR_NULL_PTR;
    if (b == 0) return ERR_OUT_OF_RANGE;
    *result = a / b;
    return SUCCESS;
}
```

When a function needs to return both a value and an error status, the value
is typically written through an output pointer parameter, and the return value
carries the status code.

### errno, perror(), and strerror()

The C standard library uses `errno` (from `<errno.h>`) to report errors from
system calls and library functions:

- `errno` is set to a non-zero value when an error occurs
- `perror("prefix")` prints `prefix: <error message>` to stderr
- `strerror(errno)` returns the error message as a string

```c
#include <errno.h>
#include <stdio.h>
#include <string.h>

FILE *fp = fopen("missing.txt", "r");
if (fp == NULL) {
    perror("fopen");              /* prints: fopen: No such file or directory */
    printf("%s\n", strerror(errno)); /* prints: No such file or directory */
}
```

Important rules for using errno:

1. Set `errno = 0` before calling a function if you plan to check it afterward
2. Check errno only when the function indicates failure (e.g., returns NULL or -1)
3. Save errno immediately -- subsequent calls may overwrite it

### setjmp/longjmp (Non-Local Jumps)

The `<setjmp.h>` header provides `setjmp()` and `longjmp()` for non-local
jumps, which can be used as a rudimentary exception mechanism:

```c
#include <setjmp.h>

jmp_buf jump_buffer;

void risky_function(void) {
    /* Jump back to setjmp with error code 1 */
    longjmp(jump_buffer, 1);
}

int main(void) {
    if (setjmp(jump_buffer) == 0) {
        /* Normal execution path */
        risky_function();
    } else {
        /* Error recovery path */
        printf("An error occurred\n");
    }
    return 0;
}
```

**Caution:** setjmp/longjmp bypass normal control flow and do not run cleanup
code (no destructors, no `free()` calls). They are fragile and rarely the right
choice. Prefer return codes for most error handling.

## Defensive Programming Patterns

Defensive programming means writing code that anticipates misuse and fails
safely rather than producing undefined behavior.

### assert() for Development Checks

`assert()` from `<assert.h>` terminates the program if a condition is false.
Use it to catch programmer errors during development:

```c
#include <assert.h>

unsigned long factorial(int n) {
    assert(n >= 0 && "n must be non-negative");
    /* ... */
}
```

Key rules:

- Use assert for conditions that indicate bugs (invariants, preconditions)
- Do NOT use assert for runtime errors (file not found, bad user input)
- Assertions are removed by compiling with `-DNDEBUG` (production builds)
- Never put side effects inside assert -- the expression may not be evaluated

### Input Validation

All data from external sources (user input, files, network) must be validated
before use:

```c
int validate_username(const char *name) {
    if (name == NULL) return INVALID_NULL;
    size_t len = strlen(name);
    if (len < 3 || len > 31) return INVALID_LENGTH;
    for (size_t i = 0; i < len; i++) {
        if (!isalnum((unsigned char)name[i]) && name[i] != '_')
            return INVALID_CHARS;
    }
    return VALID;
}
```

Validate early, at the boundary of your system. Once data passes validation,
inner functions can use assert to verify invariants rather than re-validating.

### Bounds Checking

C arrays have no built-in bounds checking. Protect against out-of-bounds
access by:

1. Always tracking array size alongside the pointer
2. Checking indices before access
3. Using wrapper structures that pair data with its size

```c
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} SafeArray;

int safe_array_get(const SafeArray *arr, size_t index, int *value) {
    if (arr == NULL || value == NULL) return -1;
    if (index >= arr->size) return -1;
    *value = arr->data[index];
    return 0;
}
```

### NULL Pointer Guards

Always check pointers before dereferencing them, especially:

- Function parameters that come from callers
- Return values from allocation functions (malloc, calloc, realloc)
- Struct members that may be optional

```c
void print_name(const char *name) {
    printf("Name: %s\n", (name != NULL) ? name : "(none)");
}
```

## Common Error Patterns and How to Avoid Them

### 1. Forgetting to Check Return Values

```c
/* BAD: ignoring malloc failure */
int *p = malloc(sizeof(int));
*p = 42;  /* crash if malloc returned NULL */

/* GOOD: always check */
int *p = malloc(sizeof(int));
if (p == NULL) {
    fprintf(stderr, "Out of memory\n");
    return -1;
}
*p = 42;
```

### 2. Losing the Original Pointer with realloc

```c
/* BAD: if realloc fails, original pointer is lost */
ptr = realloc(ptr, new_size);

/* GOOD: use a temporary pointer */
int *temp = realloc(ptr, new_size);
if (temp == NULL) {
    free(ptr);  /* or handle the error */
    return -1;
}
ptr = temp;
```

### 3. Buffer Overflow from Unsafe String Functions

```c
/* BAD: strcpy does not check buffer size */
char buf[10];
strcpy(buf, user_input);  /* overflow if input > 9 chars */

/* GOOD: use snprintf or bounded copy */
char buf[10];
snprintf(buf, sizeof(buf), "%s", user_input);
```

### 4. Using errno Incorrectly

```c
/* BAD: checking errno without confirming failure */
some_function();
if (errno != 0) { /* unreliable */ }

/* GOOD: check return value first, then errno */
if (some_function() == -1) {
    perror("some_function");
}
```

### 5. Not Cleaning Up on Error (Resource Leaks)

Use the goto-cleanup pattern for functions that acquire multiple resources:

```c
int process_file(const char *path) {
    FILE *fp = NULL;
    char *buffer = NULL;
    int result = -1;

    fp = fopen(path, "r");
    if (fp == NULL) goto cleanup;

    buffer = malloc(1024);
    if (buffer == NULL) goto cleanup;

    /* ... do work ... */
    result = 0;

cleanup:
    free(buffer);
    if (fp) fclose(fp);
    return result;
}
```

This pattern ensures that all resources are released regardless of which
step failed.

## Code Examples

1. [error_handling.c](./error_handling.c) - Return codes, errno, perror,
   strerror, file I/O errors, memory allocation errors, error propagation
2. [defensive_programming.c](./defensive_programming.c) - assert, input
   validation, bounds checking, NULL guards, safe string operations

## Building and Running

```bash
make            # Compile all programs
make run        # Run all programs
make debug      # Build with debug symbols
make asan       # Build with AddressSanitizer
make clean      # Remove compiled files
```

## Exercises

1. Write a function `safe_atoi()` that converts a string to an integer with
   full error checking (NULL input, empty string, overflow, trailing garbage).

2. Extend the SafeArray to support dynamic resizing (push/pop operations)
   with proper error handling at every step.

3. Write a program that opens two files, copies contents from one to the
   other, and handles every possible error (open, read, write, close) using
   the goto-cleanup pattern.

4. Create a configuration file parser that validates every line of input and
   reports clear error messages with line numbers.

## Key Takeaways

- C has no exceptions; use return codes and errno for error reporting.
- Always check return values from system calls and library functions.
- Use assert for programmer errors; use validation for external input.
- Track array sizes and check bounds before every access.
- Prefer snprintf over sprintf, and bounded copies over strcpy.
- Use the goto-cleanup pattern to prevent resource leaks on error paths.
- Defensive code costs very little at runtime but prevents entire classes of bugs.
