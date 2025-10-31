/*
 * pointers_functions.c
 * Demonstrates pointers with functions
 * 
 * Topics: Pass by value vs reference, returning pointers, function pointers
 */

#include <stdio.h>
#include <stdlib.h>

// Pass by value - doesn't modify original
void increment_value(int x) {
    x++;
    printf("   Inside increment_value: x = %d\n", x);
}

// Pass by reference - modifies original
void increment_reference(int *x) {
    (*x)++;
    printf("   Inside increment_reference: *x = %d\n", *x);
}

// Swap using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Return pointer (static - safe)
int* get_static_value() {
    static int value = 100;
    return &value;
}

// Function that returns dynamically allocated memory
int* create_array(int size) {
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr != NULL) {
        for (int i = 0; i < size; i++) {
            arr[i] = (i + 1) * 10;
        }
    }
    return arr;
}

// Function pointer example - math operation
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

// Function that takes function pointer as parameter
int calculate(int x, int y, int (*operation)(int, int)) {
    return operation(x, y);
}

// Array parameter (decays to pointer)
void print_array(int *arr, int size) {
    printf("   Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Modify array elements
void double_array_values(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int main() {
    printf("=== Pointers and Functions Demo ===\n\n");
    
    // Pass by value vs pass by reference
    printf("1. Pass by Value vs Pass by Reference:\n");
    int num = 10;
    
    printf("   Original: num = %d\n", num);
    increment_value(num);
    printf("   After increment_value: num = %d (unchanged)\n", num);
    
    increment_reference(&num);
    printf("   After increment_reference: num = %d (changed!)\n\n", num);
    
    // Swapping values
    printf("2. Swapping Values:\n");
    int x = 5, y = 15;
    printf("   Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("   After swap: x = %d, y = %d\n\n", x, y);
    
    // Returning pointer to static variable
    printf("3. Returning Pointer (Static):\n");
    int *ptr = get_static_value();
    printf("   Returned value: %d\n", *ptr);
    *ptr = 200;
    int *ptr2 = get_static_value();
    printf("   After modification: %d\n\n", *ptr2);
    
    // Returning dynamically allocated memory
    printf("4. Returning Dynamically Allocated Array:\n");
    int size = 5;
    int *arr = create_array(size);
    if (arr != NULL) {
        print_array(arr, size);
        free(arr);  // Don't forget to free!
    }
    printf("\n");
    
    // Array as function parameter
    printf("5. Arrays as Function Parameters:\n");
    int numbers[] = {1, 2, 3, 4, 5};
    printf("   Original:\n");
    print_array(numbers, 5);
    
    double_array_values(numbers, 5);
    printf("   After doubling:\n");
    print_array(numbers, 5);
    printf("\n");
    
    // Function pointers
    printf("6. Function Pointers:\n");
    int a = 20, b = 10;
    
    // Declare function pointer
    int (*op)(int, int);
    
    op = add;
    printf("   %d + %d = %d\n", a, b, op(a, b));
    
    op = subtract;
    printf("   %d - %d = %d\n", a, b, op(a, b));
    
    op = multiply;
    printf("   %d * %d = %d\n\n", a, b, op(a, b));
    
    // Function pointer as parameter
    printf("7. Function Pointer as Parameter:\n");
    printf("   calculate(%d, %d, add) = %d\n", a, b, calculate(a, b, add));
    printf("   calculate(%d, %d, subtract) = %d\n", a, b, calculate(a, b, subtract));
    printf("   calculate(%d, %d, multiply) = %d\n\n", a, b, calculate(a, b, multiply));
    
    // Array of function pointers
    printf("8. Array of Function Pointers:\n");
    int (*operations[])(int, int) = {add, subtract, multiply};
    char *op_names[] = {"Add", "Subtract", "Multiply"};
    
    for (int i = 0; i < 3; i++) {
        printf("   %s: %d\n", op_names[i], operations[i](a, b));
    }
    printf("\n");
    
    // Multiple outputs from function using pointers
    printf("9. Multiple Return Values Using Pointers:\n");
    int dividend = 17, divisor = 5;
    int quotient, remainder;
    
    // Simulate a divide function that returns both quotient and remainder
    quotient = dividend / divisor;
    remainder = dividend % divisor;
    
    printf("   %d / %d = %d remainder %d\n", dividend, divisor, quotient, remainder);
    
    return 0;
}
