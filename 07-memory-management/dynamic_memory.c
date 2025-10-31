/*
 * dynamic_memory.c
 * Demonstrates dynamic memory allocation in C
 * 
 * Topics: malloc, calloc, realloc, free, memory leaks
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("=== Dynamic Memory Allocation Demo ===\n\n");
    
    // malloc - allocates uninitialized memory
    printf("1. malloc() - Allocate Memory:\n");
    int *ptr1 = (int*)malloc(5 * sizeof(int));
    if (ptr1 == NULL) {
        printf("   Memory allocation failed!\n");
        return 1;
    }
    printf("   Allocated 5 integers\n");
    printf("   Uninitialized values: ");
    for (int i = 0; i < 5; i++) {
        ptr1[i] = (i + 1) * 10;  // Initialize manually
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");
    free(ptr1);
    printf("   Memory freed\n\n");
    
    // calloc - allocates zero-initialized memory
    printf("2. calloc() - Allocate and Zero:\n");
    int *ptr2 = (int*)calloc(5, sizeof(int));
    if (ptr2 == NULL) {
        printf("   Memory allocation failed!\n");
        return 1;
    }
    printf("   Allocated 5 integers (zero-initialized)\n");
    printf("   Initial values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr2[i]);
    }
    printf("\n");
    free(ptr2);
    printf("   Memory freed\n\n");
    
    // realloc - resize memory block
    printf("3. realloc() - Resize Memory:\n");
    int *ptr3 = (int*)malloc(3 * sizeof(int));
    if (ptr3 == NULL) return 1;
    
    for (int i = 0; i < 3; i++) {
        ptr3[i] = i + 1;
    }
    printf("   Original (3 elements): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", ptr3[i]);
    }
    printf("\n");
    
    // Expand to 6 elements
    int *temp = (int*)realloc(ptr3, 6 * sizeof(int));
    if (temp == NULL) {
        free(ptr3);
        return 1;
    }
    ptr3 = temp;
    
    for (int i = 3; i < 6; i++) {
        ptr3[i] = i + 1;
    }
    printf("   After realloc (6 elements): ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", ptr3[i]);
    }
    printf("\n");
    free(ptr3);
    printf("\n");
    
    // Dynamic string
    printf("4. Dynamic String Allocation:\n");
    char *str = (char*)malloc(50 * sizeof(char));
    if (str == NULL) return 1;
    
    strcpy(str, "Hello, Dynamic Memory!");
    printf("   String: %s\n", str);
    printf("   Length: %zu bytes allocated\n", strlen(str) + 1);
    free(str);
    printf("\n");
    
    // 2D array dynamic allocation
    printf("5. Dynamic 2D Array:\n");
    int rows = 3, cols = 4;
    int **matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) return 1;
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }
    
    // Initialize and print
    printf("   Matrix:\n");
    for (int i = 0; i < rows; i++) {
        printf("      ");
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Free 2D array
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("   Matrix freed\n\n");
    
    // Memory size checking
    printf("6. Memory Sizes:\n");
    printf("   sizeof(int) = %zu bytes\n", sizeof(int));
    printf("   sizeof(double) = %zu bytes\n", sizeof(double));
    printf("   sizeof(char) = %zu bytes\n", sizeof(char));
    printf("   sizeof(int*) = %zu bytes\n", sizeof(int*));
    
    return 0;
}
