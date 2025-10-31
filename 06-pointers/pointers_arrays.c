/*
 * pointers_arrays.c
 * Demonstrates the relationship between pointers and arrays
 * 
 * Topics: Array decay, pointer equivalence, multi-dimensional arrays
 */

#include <stdio.h>

int main() {
    printf("=== Pointers and Arrays Demo ===\n\n");
    
    // Array name as pointer
    printf("1. Array Name as Pointer:\n");
    int arr[] = {10, 20, 30, 40, 50};
    
    printf("   arr = %p\n", (void*)arr);
    printf("   &arr[0] = %p\n", (void*)&arr[0]);
    printf("   These are the same! Array name decays to pointer.\n\n");
    
    // Accessing elements
    printf("2. Different Ways to Access Array Elements:\n");
    printf("   arr[0] = %d\n", arr[0]);
    printf("   *(arr+0) = %d\n", *(arr+0));
    printf("   *arr = %d\n", *arr);
    printf("   0[arr] = %d (unusual but valid!)\n\n", 0[arr]);
    
    // Pointer to array vs pointer to first element
    printf("3. Pointer to Array vs Pointer to Element:\n");
    int values[] = {1, 2, 3, 4, 5};
    int *ptr = values;           // Pointer to first element
    int (*arr_ptr)[5] = &values; // Pointer to entire array
    
    printf("   ptr = %p (pointer to first element)\n", (void*)ptr);
    printf("   arr_ptr = %p (pointer to entire array)\n", (void*)arr_ptr);
    printf("   ptr+1 = %p (moves by sizeof(int))\n", (void*)(ptr+1));
    printf("   arr_ptr+1 = %p (moves by sizeof(int)*5)\n\n", (void*)(arr_ptr+1));
    
    // Array of pointers
    printf("4. Array of Pointers:\n");
    int a = 10, b = 20, c = 30;
    int *ptr_arr[3] = {&a, &b, &c};
    
    printf("   Array of pointers:\n");
    for (int i = 0; i < 3; i++) {
        printf("      ptr_arr[%d] points to %d\n", i, *ptr_arr[i]);
    }
    printf("\n");
    
    // String array (array of character pointers)
    printf("5. Array of Strings:\n");
    char *fruits[] = {"Apple", "Banana", "Cherry", "Date"};
    int fruit_count = sizeof(fruits) / sizeof(fruits[0]);
    
    printf("   Fruits:\n");
    for (int i = 0; i < fruit_count; i++) {
        printf("      %d. %s\n", i+1, fruits[i]);
    }
    printf("\n");
    
    // 2D array and pointers
    printf("6. 2D Array and Pointers:\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("   Matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("      ");
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\n   Accessing using pointers:\n");
    printf("      matrix[1][2] = %d\n", matrix[1][2]);
    printf("      *(*(matrix+1)+2) = %d\n", *(*(matrix+1)+2));
    printf("      *((int*)matrix + 1*4 + 2) = %d\n\n", *((int*)matrix + 1*4 + 2));
    
    // Passing array to function (decay to pointer)
    printf("7. Array Parameter Decay:\n");
    int nums[] = {5, 15, 25, 35};
    printf("   In main, sizeof(nums) = %zu bytes\n", sizeof(nums));
    printf("   When passed to function, array decays to pointer\n");
    printf("   Function receives pointer, not array\n\n");
    
    // Pointer arithmetic with character arrays
    printf("8. Character Array and Pointers:\n");
    char str[] = "Hello";
    char *cptr = str;
    
    printf("   String: %s\n", str);
    printf("   Character by character:\n      ");
    while (*cptr != '\0') {
        printf("%c ", *cptr);
        cptr++;
    }
    printf("\n\n");
    
    // Dynamic array simulation
    printf("9. Simulating Dynamic Array:\n");
    int size = 5;
    int data[] = {100, 200, 300, 400, 500};
    int *dptr = data;
    
    printf("   Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(dptr + i));
    }
    printf("\n");
    
    printf("   Sum using pointer: ");
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(dptr + i);
    }
    printf("%d\n\n", sum);
    
    // Array bounds and pointers
    printf("10. Array Bounds:\n");
    int bounded[] = {1, 2, 3, 4, 5};
    int *start = bounded;
    int *end = bounded + 5;  // Points one past last element
    
    printf("   Valid range: %p to %p\n", (void*)start, (void*)(end-1));
    printf("   Iterating safely:\n      ");
    for (int *p = start; p < end; p++) {
        printf("%d ", *p);
    }
    printf("\n");
    
    return 0;
}
