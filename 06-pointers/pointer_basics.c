/*
 * pointer_basics.c
 * Introduction to pointers in C
 * 
 * Topics: Pointer declaration, address-of (&), dereference (*), NULL pointers
 */

#include <stdio.h>
#include <stddef.h>  // For NULL

int main() {
    printf("=== Pointer Basics Demo ===\n\n");
    
    // Basic pointer declaration and initialization
    int x = 42;
    int *ptr = &x;  // ptr stores the address of x
    
    printf("1. Basic Pointer Operations:\n");
    printf("   Value of x: %d\n", x);
    printf("   Address of x: %p\n", (void*)&x);
    printf("   Value stored in ptr (address of x): %p\n", (void*)ptr);
    printf("   Value pointed to by ptr: %d\n", *ptr);
    printf("   Size of pointer: %zu bytes\n\n", sizeof(ptr));
    
    // Modifying through pointer
    printf("2. Modifying Value Through Pointer:\n");
    printf("   Before: x = %d\n", x);
    *ptr = 100;  // Change value of x through pointer
    printf("   After (*ptr = 100): x = %d\n\n", x);
    
    // Different types of pointers
    printf("3. Different Pointer Types:\n");
    int i = 10;
    float f = 3.14f;
    char c = 'A';
    double d = 2.718;
    
    int *iptr = &i;
    float *fptr = &f;
    char *cptr = &c;
    double *dptr = &d;
    
    printf("   int pointer:    %p -> %d\n", (void*)iptr, *iptr);
    printf("   float pointer:  %p -> %.2f\n", (void*)fptr, *fptr);
    printf("   char pointer:   %p -> %c\n", (void*)cptr, *cptr);
    printf("   double pointer: %p -> %.3f\n\n", (void*)dptr, *dptr);
    
    // NULL pointer
    printf("4. NULL Pointer:\n");
    int *null_ptr = NULL;
    printf("   NULL pointer value: %p\n", (void*)null_ptr);
    if (null_ptr == NULL) {
        printf("   Pointer is NULL (safe to check before dereferencing)\n");
    }
    // NEVER dereference a NULL pointer - it causes segmentation fault!
    // printf("%d\n", *null_ptr);  // DON'T DO THIS!
    printf("\n");
    
    // Pointer to constant
    printf("5. Pointer to Constant:\n");
    int value = 50;
    const int *const_ptr = &value;
    printf("   Value: %d\n", *const_ptr);
    // *const_ptr = 60;  // COMPILE ERROR: Cannot modify through pointer to const
    value = 60;  // But we can modify value directly
    printf("   Value modified directly: %d\n", *const_ptr);
    printf("\n");
    
    // Constant pointer
    printf("6. Constant Pointer:\n");
    int val1 = 10, val2 = 20;
    int *const ptr_const = &val1;
    printf("   Value: %d\n", *ptr_const);
    *ptr_const = 15;  // Can modify value
    printf("   Modified value: %d\n", *ptr_const);
    // ptr_const = &val2;  // COMPILE ERROR: Cannot change where pointer points
    printf("\n");
    
    // Void pointer (generic pointer)
    printf("7. Void Pointer (Generic):\n");
    void *void_ptr;
    int num = 123;
    void_ptr = &num;
    printf("   Void pointer can point to any type\n");
    printf("   Value: %d (cast required)\n", *(int*)void_ptr);
    
    float fnum = 45.67f;
    void_ptr = &fnum;
    printf("   Now pointing to float: %.2f\n\n", *(float*)void_ptr);
    
    // Multiple pointers to same variable
    printf("8. Multiple Pointers to Same Variable:\n");
    int shared = 999;
    int *p1 = &shared;
    int *p2 = &shared;
    
    printf("   shared = %d\n", shared);
    printf("   *p1 = %d, *p2 = %d\n", *p1, *p2);
    *p1 = 111;
    printf("   After *p1 = 111:\n");
    printf("   shared = %d, *p2 = %d\n", shared, *p2);
    
    return 0;
}
