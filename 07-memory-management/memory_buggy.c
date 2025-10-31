/*
 * memory_buggy.c
 * DELIBERATELY BUGGY CODE - For learning purposes
 * 
 * Common memory management mistakes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("=== Buggy Memory Management Demo ===\n\n");
    
    // BUG #1: Memory leak - forgot to free
    printf("BUG #1: Memory leak\n");
    int *leak = (int*)malloc(100 * sizeof(int));
    if (leak != NULL) {
        leak[0] = 42;
        printf("   Allocated memory but never freed!\n");
        // WRONG: Missing free(leak);
    }
    printf("   This is a memory leak!\n\n");
    
    // BUG #2: Double free
    printf("BUG #2: Double free\n");
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 10;
        free(ptr);
        // free(ptr);  // WRONG: Double free - undefined behavior!
        printf("   Freeing the same pointer twice causes corruption!\n");
    }
    printf("\n");
    
    // BUG #3: Use after free
    printf("BUG #3: Use after free\n");
    int *ptr2 = (int*)malloc(sizeof(int));
    if (ptr2 != NULL) {
        *ptr2 = 20;
        free(ptr2);
        // *ptr2 = 30;  // WRONG: Using freed memory!
        // printf("%d\n", *ptr2);  // WRONG: Reading freed memory!
        printf("   Never use pointer after freeing!\n");
    }
    printf("\n");
    
    // BUG #4: Not checking malloc return value
    printf("BUG #4: Not checking malloc return\n");
    // int *ptr3 = (int*)malloc(sizeof(int));
    // *ptr3 = 100;  // WRONG: What if malloc failed?
    printf("   Always check if malloc returned NULL!\n\n");
    
    // BUG #5: Buffer overflow
    printf("BUG #5: Buffer overflow\n");
    int *arr = (int*)malloc(5 * sizeof(int));
    if (arr != NULL) {
        for (int i = 0; i < 5; i++) {
            arr[i] = i;
        }
        // arr[10] = 99;  // WRONG: Writing beyond allocated memory!
        printf("   Writing beyond allocated memory is undefined!\n");
        free(arr);
    }
    printf("\n");
    
    // BUG #6: Incorrect size calculation
    printf("BUG #6: Incorrect size calculation\n");
    // int *ptr4 = (int*)malloc(10);  // WRONG: Allocated 10 bytes, not 10 ints!
    int *ptr4 = (int*)malloc(10 * sizeof(int));  // Correct
    if (ptr4 != NULL) {
        printf("   Use sizeof() to calculate correct size!\n");
        free(ptr4);
    }
    printf("\n");
    
    // BUG #7: Lost pointer (memory leak)
    printf("BUG #7: Lost pointer\n");
    int *ptr5 = (int*)malloc(sizeof(int));
    if (ptr5 != NULL) {
        *ptr5 = 50;
        ptr5 = NULL;  // WRONG: Lost the pointer, can't free now!
        // Memory leaked
    }
    printf("   Lost pointer before freeing - memory leaked!\n\n");
    
    // BUG #8: Mixing malloc/free with new/delete
    printf("BUG #8: Mixing allocators\n");
    printf("   In C: use malloc/free together\n");
    printf("   In C++: use new/delete together\n");
    printf("   Never mix them!\n\n");
    
    // BUG #9: Returning pointer to local variable
    printf("BUG #9: Returning local variable address\n");
    printf("   Local variables are on stack, destroyed after function returns\n");
    printf("   Use malloc for data that outlives function scope\n\n");
    
    // BUG #10: Incorrect realloc usage
    printf("BUG #10: Incorrect realloc usage\n");
    int *ptr6 = (int*)malloc(5 * sizeof(int));
    if (ptr6 != NULL) {
        // ptr6 = (int*)realloc(ptr6, 10 * sizeof(int));  // WRONG: if realloc fails, ptr6 is lost!
        int *temp = (int*)realloc(ptr6, 10 * sizeof(int));  // Correct
        if (temp != NULL) {
            ptr6 = temp;
            printf("   Always check realloc return before reassigning!\n");
        }
        free(ptr6);
    }
    printf("\n");
    
    // BUG #11: Freeing stack memory
    printf("BUG #11: Freeing stack memory\n");
    int stack_var = 42;
    // free(&stack_var);  // WRONG: Can only free heap memory!
    printf("   Only free memory allocated with malloc/calloc/realloc!\n\n");
    
    // BUG #12: Partial deallocation of 2D array
    printf("BUG #12: Partial 2D array deallocation\n");
    int **matrix = (int**)malloc(3 * sizeof(int*));
    if (matrix != NULL) {
        for (int i = 0; i < 3; i++) {
            matrix[i] = (int*)malloc(4 * sizeof(int));
        }
        // WRONG: Only freeing main pointer
        // free(matrix);  // Leaks row memory!
        
        // Correct: Free in reverse order
        for (int i = 0; i < 3; i++) {
            free(matrix[i]);
        }
        free(matrix);
        printf("   Must free all levels of nested allocations!\n");
    }
    printf("\n");
    
    // BUG #13: Using sizeof on pointer
    printf("BUG #13: sizeof on pointer vs array\n");
    int *dyn_arr = (int*)malloc(10 * sizeof(int));
    if (dyn_arr != NULL) {
        // int size = sizeof(dyn_arr) / sizeof(int);  // WRONG: gives pointer size!
        printf("   sizeof(pointer) gives pointer size, not array size!\n");
        printf("   Keep track of array size separately\n");
        free(dyn_arr);
    }
    
    return 0;
}
