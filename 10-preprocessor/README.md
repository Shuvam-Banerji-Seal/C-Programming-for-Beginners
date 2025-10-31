# Module 10: Preprocessor and Macros 🔧

Master the C preprocessor!

## 📚 What You'll Learn

1. Preprocessor directives
2. Macros and macro functions
3. Conditional compilation
4. Header guards
5. Common preprocessor tricks

## 🔧 Preprocessor Directives

```c
#include <stdio.h>

#define PI 3.14159
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SQUARE(x) ((x) * (x))

int main() {
    printf("PI = %f\n", PI);
    printf("MAX(5, 10) = %d\n", MAX(5, 10));
    printf("SQUARE(4) = %d\n", SQUARE(4));
    return 0;
}
```

## 🛡️ Header Guards

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

// Header content here

#endif
```

## ⚙️ Conditional Compilation

```c
#define DEBUG

#ifdef DEBUG
    printf("Debug mode enabled\n");
#endif

#if defined(WINDOWS)
    // Windows code
#elif defined(LINUX)
    // Linux code
#else
    // Other OS code
#endif
```

## 🔜 Next Module

[Module 11: Data Structures Fundamentals](../11-data-structures/README.md)
