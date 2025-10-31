/*
 * pointer_basics_buggy.c
 * DELIBERATELY BUGGY CODE - For learning purposes
 * 
 * This file contains common pointer mistakes.
 * Each bug is explained with comments.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Buggy Pointer Demo ===\n\n");
    
    // BUG #1: Uninitialized pointer (dangling pointer)
    printf("BUG #1: Uninitialized pointer\n");
    int *ptr1;  // WRONG: Uninitialized, points to random memory
    // *ptr1 = 10;  // SEGMENTATION FAULT: Writing to random memory
    printf("Uninitialized pointer contains garbage address\n");
    printf("NEVER dereference uninitialized pointers!\n\n");
    
    // BUG #2: Dereferencing NULL pointer
    printf("BUG #2: Dereferencing NULL pointer\n");
    int *ptr2 = NULL;
    // int value = *ptr2;  // SEGMENTATION FAULT: Dereferencing NULL
    printf("NULL pointer: %p\n", (void*)ptr2);
    printf("Always check if pointer is NULL before dereferencing!\n\n");
    
    // BUG #3: Type mismatch
    printf("BUG #3: Type mismatch\n");
    int x = 100;
    // float *fptr = &x;  // COMPILE WARNING: Type mismatch
    // Pointer type should match variable type
    printf("Pointer type must match the variable type!\n\n");
    
    // BUG #4: Using & incorrectly
    printf("BUG #4: Incorrect use of & operator\n");
    int y = 50;
    int *ptr3 = &y;
    // int z = &y;  // COMPILE WARNING: Assigning pointer to int
    printf("Use & to get address, not to assign to regular variables\n\n");
    
    // BUG #5: Using * incorrectly on non-pointer
    printf("BUG #5: Dereferencing non-pointer\n");
    int a = 10;
    // int b = *a;  // COMPILE ERROR: Cannot dereference non-pointer
    printf("Can only use * on pointer variables!\n\n");
    
    // BUG #6: Lost pointer
    printf("BUG #6: Lost pointer (memory leak)\n");
    int *ptr4 = malloc(sizeof(int));
    if (ptr4 != NULL) {
        *ptr4 = 42;
        printf("Allocated memory, value: %d\n", *ptr4);
        ptr4 = NULL;  // WRONG: Lost reference without freeing!
        // Memory leaked - can't free it now
    }
    printf("Lost the pointer before freeing - memory leaked!\n\n");
    
    // BUG #7: Using freed memory (dangling pointer)
    printf("BUG #7: Using freed memory\n");
    int *ptr5 = malloc(sizeof(int));
    if (ptr5 != NULL) {
        *ptr5 = 100;
        free(ptr5);
        // *ptr5 = 200;  // WRONG: Writing to freed memory
        // printf("%d\n", *ptr5);  // WRONG: Reading freed memory
        printf("Never use pointer after freeing!\n");
        ptr5 = NULL;  // Good practice: set to NULL after freeing
    }
    printf("\n");
    
    // BUG #8: Pointer arithmetic overflow
    printf("BUG #8: Pointer arithmetic out of bounds\n");
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr6 = arr;
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // WRONG: Accessing beyond array bounds
    // printf("arr[10] = %d\n", *(ptr6 + 10));  // Undefined behavior
    printf("Pointer arithmetic beyond array bounds is undefined!\n\n");
    
    // BUG #9: Comparing pointers from different arrays
    printf("BUG #9: Comparing unrelated pointers\n");
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {4, 5, 6};
    int *p1 = arr1;
    int *p2 = arr2;
    // if (p1 < p2) {  // WRONG: Comparing pointers to different objects
    //     printf("Undefined behavior\n");
    // }
    printf("Only compare pointers to elements of same array!\n\n");
    
    // BUG #10: Returning pointer to local variable
    printf("BUG #10: Returning address of local variable\n");
    printf("See function example - returns dangling pointer\n");
    printf("Local variables are destroyed when function returns!\n\n");
    
    // BUG #11: Incorrect pointer size assumptions
    printf("BUG #11: Pointer size assumptions\n");
    int arr3[10];
    // int size = sizeof(arr3) / sizeof(int);  // Correct: 10
    int *ptr7 = arr3;
    // int wrong_size = sizeof(ptr7) / sizeof(int);  // WRONG: Gives pointer size
    printf("sizeof(pointer) gives pointer size, not array size!\n");
    printf("Pointer size: %zu bytes\n", sizeof(ptr7));
    printf("Array size: %zu elements\n\n", sizeof(arr3) / sizeof(int));
    
    // BUG #12: Missing const correctness
    printf("BUG #12: Modifying const data\n");
    const int const_val = 42;
    // int *ptr8 = &const_val;  // COMPILE WARNING: Discarding const
    const int *ptr8 = &const_val;  // Correct
    // *ptr8 = 50;  // COMPILE ERROR: Cannot modify const through pointer
    printf("Use const int* for pointers to const data\n\n");
    
    // BUG #13: Double free
    printf("BUG #13: Double free\n");
    int *ptr9 = malloc(sizeof(int));
    if (ptr9 != NULL) {
        *ptr9 = 77;
        free(ptr9);
        // free(ptr9);  // WRONG: Double free - undefined behavior!
        printf("Freeing memory twice causes corruption!\n");
    }
    printf("\n");
    
    // BUG #14: Pointer indirection confusion
    printf("BUG #14: Indirection confusion\n");
    int val = 10;
    int *ptr10 = &val;
    // Correct: *ptr10 = 20
    // Wrong: ptr10 = 20  // COMPILE WARNING: Assigning int to pointer
    printf("Use *ptr to modify value, not ptr\n");
    printf("ptr is the address, *ptr is the value\n");
    
    return 0;
}
