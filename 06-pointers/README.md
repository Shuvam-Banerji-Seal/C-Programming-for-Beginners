# Module 06: Pointers

Master pointers - one of the most powerful features of C!

## What You'll Learn

1. Introduction to pointers
2. Pointer arithmetic
3. Pointers and arrays
4. Pointer to pointer
5. Pointers and functions
6. Dynamic memory allocation basics

## Pointer Basics

```c
#include <stdio.h>

int main() {
 int x = 10;
 int *ptr = &x; // ptr stores address of x

 printf("Value of x: %d\n", x);
 printf("Address of x: %p\n", (void*)&x);
 printf("Value of ptr: %p\n", (void*)ptr);
 printf("Value at ptr: %d\n", *ptr);

 *ptr = 20; // Modify x through pointer
 printf("New value of x: %d\n", x);

 return 0;
}
```

## Pointer Arithmetic

```c
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr;

printf("%d\n", *ptr); // 10
printf("%d\n", *(ptr+1)); // 20
printf("%d\n", *(ptr+2)); // 30

ptr++;
printf("%d\n", *ptr); // 20
```

## Pointers and Arrays

```c
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr; // arr decays to pointer

for (int i = 0; i < 5; i++) {
 printf("%d ", *(ptr + i)); // or ptr[i]
}
```

## Pointer to Pointer

```c
int x = 100;
int *ptr = &x;
int **pptr = &ptr;

printf("Value: %d\n", **pptr); // 100
```

## Key Takeaways

- Pointers store memory addresses
- `&` gets address, `*` dereferences
- Pointer arithmetic scales by type size
- Arrays and pointers are closely related
- Always initialize pointers
- Null pointers point to nothing

## Next Module

[Module 07: Advanced Memory Management](../07-memory-management/README.md)


## Files in this Module

Each source file has a companion markdown file with detailed explanations:

| File | Description |
|------|------------|
| [`pointer_arithmetic.c`](pointer_arithmetic.md) 📄 | Pointer Arithmetic demonstration |
| [`pointer_basics.c`](pointer_basics.md) 📄 | Pointer Basics demonstration |
| [`pointer_basics_buggy.c`](pointer_basics_buggy.md) 📄 | Pointer Basics Buggy demonstration |
| [`pointer_to_pointer.c`](pointer_to_pointer.md) 📄 | Pointer To Pointer demonstration |
| [`pointers_arrays.c`](pointers_arrays.md) 📄 | Pointers Arrays demonstration |
| [`pointers_functions.c`](pointers_functions.md) 📄 | Pointers Functions demonstration |

### Legend

- 📄 = Detailed explanation available
- 🐛 = Contains deliberate bugs for learning

> **🐛 `pointer_basics_buggy.c`** has deliberate bugs. Study, compile, fix, and learn.
