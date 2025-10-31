/*
 * pointer_arithmetic.c
 * Demonstrates pointer arithmetic in C
 * 
 * Topics: Pointer increment/decrement, pointer addition/subtraction,
 *         pointer difference, relationship with arrays
 */

#include <stdio.h>

int main() {
    printf("=== Pointer Arithmetic Demo ===\n\n");
    
    // Basic pointer arithmetic with integers
    printf("1. Basic Pointer Arithmetic (int):\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // Points to first element
    
    printf("   Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("   Base address: %p\n", (void*)ptr);
    printf("   *ptr = %d\n", *ptr);
    printf("   *(ptr+1) = %d\n", *(ptr+1));
    printf("   *(ptr+2) = %d\n", *(ptr+2));
    printf("   Address of ptr+1: %p (difference: %ld bytes)\n", 
           (void*)(ptr+1), (char*)(ptr+1) - (char*)ptr);
    printf("\n");
    
    // Incrementing and decrementing pointers
    printf("2. Incrementing and Decrementing:\n");
    ptr = arr;  // Reset to start
    printf("   Initial: *ptr = %d, address = %p\n", *ptr, (void*)ptr);
    
    ptr++;  // Move to next element
    printf("   After ptr++: *ptr = %d, address = %p\n", *ptr, (void*)ptr);
    
    ptr += 2;  // Move forward by 2
    printf("   After ptr+=2: *ptr = %d, address = %p\n", *ptr, (void*)ptr);
    
    ptr--;  // Move back by 1
    printf("   After ptr--: *ptr = %d, address = %p\n\n", *ptr, (void*)ptr);
    
    // Pointer arithmetic with different types
    printf("3. Pointer Arithmetic with Different Types:\n");
    
    char char_arr[] = {'A', 'B', 'C', 'D', 'E'};
    char *cptr = char_arr;
    printf("   char array: ");
    for (int i = 0; i < 5; i++) printf("%c ", char_arr[i]);
    printf("\n");
    printf("   Address gap (char): %ld byte\n", (cptr+1) - cptr);
    
    short short_arr[] = {100, 200, 300};
    short *sptr = short_arr;
    printf("   short array: ");
    for (int i = 0; i < 3; i++) printf("%d ", short_arr[i]);
    printf("\n");
    printf("   Address gap (short): %ld bytes\n", (char*)(sptr+1) - (char*)sptr);
    
    double double_arr[] = {1.1, 2.2, 3.3};
    double *dptr = double_arr;
    printf("   double array: ");
    for (int i = 0; i < 3; i++) printf("%.1f ", double_arr[i]);
    printf("\n");
    printf("   Address gap (double): %ld bytes\n\n", (char*)(dptr+1) - (char*)dptr);
    
    // Pointer difference
    printf("4. Pointer Difference:\n");
    int numbers[] = {5, 15, 25, 35, 45, 55};
    int *start = &numbers[1];
    int *end = &numbers[5];
    
    printf("   Array: ");
    for (int i = 0; i < 6; i++) printf("%d ", numbers[i]);
    printf("\n");
    printf("   start points to: %d (index 1)\n", *start);
    printf("   end points to: %d (index 5)\n", *end);
    printf("   end - start = %ld elements\n\n", end - start);
    
    // Array subscript notation vs pointer notation
    printf("5. Array Subscript vs Pointer Notation:\n");
    int data[] = {100, 200, 300, 400, 500};
    int *p = data;
    
    printf("   Using array notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("      data[%d] = %d\n", i, data[i]);
    }
    
    printf("   Using pointer notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("      *(p+%d) = %d\n", i, *(p+i));
    }
    printf("\n");
    
    // Traversing array with pointer
    printf("6. Traversing Array with Pointer:\n");
    int values[] = {2, 4, 6, 8, 10};
    int *vptr = values;
    
    printf("   Forward traversal: ");
    for (int i = 0; i < 5; i++, vptr++) {
        printf("%d ", *vptr);
    }
    printf("\n");
    
    vptr = &values[4];  // Point to last element
    printf("   Backward traversal: ");
    for (int i = 0; i < 5; i++, vptr--) {
        printf("%d ", *vptr);
    }
    printf("\n\n");
    
    // Pointer comparison
    printf("7. Pointer Comparison:\n");
    int sequence[] = {1, 2, 3, 4, 5};
    int *first = &sequence[0];
    int *last = &sequence[4];
    
    if (first < last) {
        printf("   first comes before last in memory\n");
    }
    
    int *current = first;
    printf("   Elements from first to last: ");
    while (current <= last) {
        printf("%d ", *current);
        current++;
    }
    printf("\n\n");
    
    // Complex example: Finding element in array
    printf("8. Finding Element Using Pointers:\n");
    int search_arr[] = {12, 45, 67, 23, 89, 34, 56};
    int search_value = 89;
    int size = sizeof(search_arr) / sizeof(search_arr[0]);
    
    printf("   Array: ");
    for (int i = 0; i < size; i++) printf("%d ", search_arr[i]);
    printf("\n");
    printf("   Searching for: %d\n", search_value);
    
    int *search_ptr = search_arr;
    int found = 0;
    while (search_ptr < search_arr + size) {
        if (*search_ptr == search_value) {
            printf("   Found at index: %ld\n", search_ptr - search_arr);
            found = 1;
            break;
        }
        search_ptr++;
    }
    if (!found) {
        printf("   Not found\n");
    }
    
    return 0;
}
