/*
 * debug_example.c
 * Example program for GDB debugging practice
 * 
 * This program has a bug - can you find it with GDB?
 */

#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int sum_array(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    printf("=== GDB Debugging Example ===\n\n");
    
    // Test factorial
    printf("Factorial examples:\n");
    for (int i = 1; i <= 5; i++) {
        int result = factorial(i);
        printf("  %d! = %d\n", i, result);
    }
    
    // Test array sum
    printf("\nArray sum example:\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("  Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    int total = sum_array(numbers, size);
    printf("  Sum: %d\n", total);
    
    return 0;
}
