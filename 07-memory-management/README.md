# Module 07: Advanced Memory Management

Master dynamic memory allocation and avoid memory leaks!

## What You'll Learn

1. Stack vs Heap memory
2. Dynamic memory allocation (malloc, calloc, realloc, free)
3. Memory leaks and debugging
4. Custom memory allocators
5. Best practices

## Stack vs Heap

```mermaid
graph TD
 A[Memory] --> B[Stack]
 A --> C[Heap]
 B --> D[Automatic allocation]
 B --> E[Fast access]
 B --> F[Limited size]
 C --> G[Manual allocation]
 C --> H[Slower access]
 C --> I[Large size]
```

## Dynamic Allocation

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
 // malloc - allocate uninitialized memory
 int *arr = (int*)malloc(5 * sizeof(int));
 if (arr == NULL) {
 printf("Memory allocation failed!\n");
 return 1;
 }

 // calloc - allocate zero-initialized memory
 int *arr2 = (int*)calloc(5, sizeof(int));

 // realloc - resize memory
 arr = (int*)realloc(arr, 10 * sizeof(int));

 // Always free allocated memory
 free(arr);
 free(arr2);

 return 0;
}
```

## Common Memory Errors

1. **Memory leak**: Forgetting to free
2. **Double free**: Freeing twice
3. **Use after free**: Using freed memory
4. **Buffer overflow**: Writing beyond bounds
5. **Null pointer dereference**: Using NULL pointer

## Next Module

[Module 08: Structures and Unions](../08-structures-unions/README.md)


## Files in this Module

Each source file has a companion markdown file with detailed explanations:

| File | Description |
|------|------------|
| [`dynamic_memory.c`](dynamic_memory.md) 📄 | Dynamic Memory demonstration |
| [`memory_buggy.c`](memory_buggy.md) 📄 | Memory Buggy demonstration |
| [`stack_vs_heap.c`](stack_vs_heap.md) 📄 | Stack Vs Heap demonstration |

### Legend

- 📄 = Detailed explanation available
- 🐛 = Contains deliberate bugs for learning

> **🐛 `memory_buggy.c`** has deliberate bugs. Study, compile, fix, and learn.
