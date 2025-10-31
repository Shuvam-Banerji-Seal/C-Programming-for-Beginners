/*
 * pointer_to_pointer.c
 * Demonstrates pointer to pointer (double pointers)
 * 
 * Topics: Double pointers, triple pointers, use cases
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that modifies a pointer
void allocate_memory(int **ptr, int value) {
    *ptr = (int*)malloc(sizeof(int));
    if (*ptr != NULL) {
        **ptr = value;
    }
}

// Function to swap two pointers
void swap_pointers(int **p1, int **p2) {
    int *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    printf("=== Pointer to Pointer Demo ===\n\n");
    
    // Basic double pointer
    printf("1. Basic Double Pointer:\n");
    int x = 42;
    int *ptr = &x;      // Pointer to int
    int **pptr = &ptr;  // Pointer to pointer to int
    
    printf("   Value of x: %d\n", x);
    printf("   Address of x: %p\n", (void*)&x);
    printf("   Value of ptr (address of x): %p\n", (void*)ptr);
    printf("   Address of ptr: %p\n", (void*)&ptr);
    printf("   Value of pptr (address of ptr): %p\n", (void*)pptr);
    printf("   Value pointed to by *pptr (value of ptr): %p\n", (void*)*pptr);
    printf("   Value pointed to by **pptr (value of x): %d\n\n", **pptr);
    
    // Modifying value through double pointer
    printf("2. Modifying Through Double Pointer:\n");
    printf("   Before: x = %d\n", x);
    **pptr = 100;
    printf("   After **pptr = 100: x = %d\n\n", x);
    
    // Array of pointers with double pointer
    printf("3. Array of Pointers:\n");
    int a = 10, b = 20, c = 30;
    int *arr[] = {&a, &b, &c};
    int **pp = arr;  // pp points to first element of array
    
    printf("   Values: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", **(pp + i));
    }
    printf("\n\n");
    
    // 2D array using pointer to pointer
    printf("4. 2D Array Simulation:\n");
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};
    int *rows[] = {row1, row2, row3};
    int **matrix = rows;
    
    printf("   Matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("      ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(*(matrix + i) + j));
            // Same as: matrix[i][j]
        }
        printf("\n");
    }
    printf("\n");
    
    // String array (array of strings)
    printf("5. Array of Strings:\n");
    char *names[] = {"Alice", "Bob", "Charlie", "David"};
    char **name_ptr = names;
    
    printf("   Names:\n");
    for (int i = 0; i < 4; i++) {
        printf("      %s (length: %zu)\n", *(name_ptr + i), 
               strlen(*(name_ptr + i)));
    }
    printf("\n");
    
    // Function modifying pointer through double pointer
    printf("6. Function Modifying Pointer:\n");
    int *dynamic = NULL;
    printf("   Before: dynamic = %p\n", (void*)dynamic);
    
    allocate_memory(&dynamic, 999);
    
    if (dynamic != NULL) {
        printf("   After allocation: dynamic = %p\n", (void*)dynamic);
        printf("   Value: %d\n", *dynamic);
        free(dynamic);
        dynamic = NULL;
    }
    printf("\n");
    
    // Swapping pointers
    printf("7. Swapping Pointers:\n");
    int val1 = 111, val2 = 222;
    int *p1 = &val1;
    int *p2 = &val2;
    
    printf("   Before swap:\n");
    printf("      p1 points to %d\n", *p1);
    printf("      p2 points to %d\n", *p2);
    
    swap_pointers(&p1, &p2);
    
    printf("   After swap:\n");
    printf("      p1 points to %d\n", *p1);
    printf("      p2 points to %d\n", *p2);
    printf("\n");
    
    // Triple pointer
    printf("8. Triple Pointer:\n");
    int num = 777;
    int *p = &num;
    int **pp2 = &p;
    int ***ppp = &pp2;
    
    printf("   Value: %d\n", num);
    printf("   Through *p: %d\n", *p);
    printf("   Through **pp: %d\n", **pp2);
    printf("   Through ***ppp: %d\n", ***ppp);
    printf("\n");
    
    // Command line arguments simulation
    printf("9. Command Line Arguments Pattern:\n");
    char *argv[] = {"program", "-v", "--help", "file.txt"};
    int argc = 4;
    char **args = argv;
    
    printf("   Arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("      argv[%d] = %s\n", i, args[i]);
    }
    
    return 0;
}
