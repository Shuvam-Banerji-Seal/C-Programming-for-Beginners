/*
 * segfault_example.c
 * Example program that demonstrates common segmentation faults
 * 
 * Use GDB to find and understand the crashes
 */

#include <stdio.h>
#include <stdlib.h>

void example1_null_pointer() {
    printf("\n=== Example 1: NULL Pointer Dereference ===\n");
    int *ptr = NULL;
    // UNCOMMENT TO TRIGGER: printf("Value: %d\n", *ptr);
    printf("Avoided NULL dereference (commented out)\n");
}

void example2_buffer_overflow() {
    printf("\n=== Example 2: Buffer Overflow ===\n");
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Array elements:\n");
    for (int i = 0; i < 5; i++) {  // Safe access
        printf("  arr[%d] = %d\n", i, arr[i]);
    }
    // UNSAFE: arr[10] = 999;  // Would cause undefined behavior
    printf("Safe array access demonstrated\n");
}

void example3_use_after_free() {
    printf("\n=== Example 3: Use After Free ===\n");
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 42;
        printf("Allocated value: %d\n", *ptr);
        free(ptr);
        // UNSAFE: printf("After free: %d\n", *ptr);  // Use after free
        ptr = NULL;  // Good practice
        printf("Properly freed and set to NULL\n");
    }
}

void example4_stack_overflow() {
    printf("\n=== Example 4: Stack Overflow (Infinite Recursion) ===\n");
    printf("Stack overflow example (not executed to avoid crash)\n");
    // UNSAFE: example4_stack_overflow();  // Infinite recursion
}

int main() {
    printf("=== GDB Segfault Examples ===\n");
    printf("These examples demonstrate common crash scenarios\n");
    printf("Unsafe code is commented out to prevent actual crashes\n");
    
    example1_null_pointer();
    example2_buffer_overflow();
    example3_use_after_free();
    example4_stack_overflow();
    
    printf("\n=== All Examples Completed Safely ===\n");
    printf("\nTo practice debugging:\n");
    printf("1. Uncomment unsafe code\n");
    printf("2. Compile with: gcc -g -o segfault segfault_example.c\n");
    printf("3. Run in GDB: gdb ./segfault\n");
    printf("4. Use 'run', 'backtrace', 'frame', 'print' commands\n");
    
    return 0;
}
