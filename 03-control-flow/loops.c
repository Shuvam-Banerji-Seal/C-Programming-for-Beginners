/*
 * loops.c
 * Demonstrates all types of loops in C
 * 
 * Topics: for, while, do-while loops
 */

#include <stdio.h>

int main() {
    printf("=== Loops Demo ===\n\n");
    
    // FOR LOOP
    printf("1. FOR LOOP Examples:\n");
    printf("   Counting 1 to 5: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("   Even numbers 0 to 10: ");
    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("   Countdown from 5: ");
    for (int i = 5; i > 0; i--) {
        printf("%d ", i);
    }
    printf("Blast off!\n\n");
    
    // Multiple variables in for loop
    printf("   Multiple variables: ");
    for (int i = 0, j = 10; i < 5; i++, j--) {
        printf("(%d,%d) ", i, j);
    }
    printf("\n\n");
    
    // WHILE LOOP
    printf("2. WHILE LOOP Examples:\n");
    printf("   Counting 1 to 5: ");
    int count = 1;
    while (count <= 5) {
        printf("%d ", count);
        count++;
    }
    printf("\n");
    
    // Finding power of 2
    printf("   Powers of 2 less than 1000: ");
    int power = 1;
    while (power < 1000) {
        printf("%d ", power);
        power *= 2;
    }
    printf("\n");
    
    // Sum of numbers
    printf("   Sum of first 10 numbers: ");
    int sum = 0;
    int n = 1;
    while (n <= 10) {
        sum += n;
        n++;
    }
    printf("%d\n\n", sum);
    
    // DO-WHILE LOOP
    printf("3. DO-WHILE LOOP Examples:\n");
    printf("   Counting 1 to 5: ");
    int i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 5);
    printf("\n");
    
    // Always executes at least once
    printf("   Condition false from start: ");
    int j = 10;
    do {
        printf("%d ", j);  // This still prints once!
        j++;
    } while (j < 10);
    printf("(executed once even though condition was false)\n\n");
    
    // INFINITE LOOP (with break)
    printf("4. INFINITE LOOP with break:\n");
    printf("   Numbers until 5: ");
    int num = 1;
    while (1) {  // Infinite loop
        printf("%d ", num);
        if (num >= 5) {
            break;  // Exit condition
        }
        num++;
    }
    printf("\n\n");
    
    // MULTIPLICATION TABLE
    printf("5. Multiplication table of 5:\n");
    for (int k = 1; k <= 10; k++) {
        printf("   5 x %2d = %2d\n", k, 5 * k);
    }
    
    // FACTORIAL CALCULATION
    printf("\n6. Factorial of 5:\n");
    int factorial = 1;
    int number = 5;
    for (int m = 1; m <= number; m++) {
        factorial *= m;
    }
    printf("   %d! = %d\n", number, factorial);
    
    // FIBONACCI SEQUENCE
    printf("\n7. First 10 Fibonacci numbers:\n   ");
    int fib1 = 0, fib2 = 1, nextFib;
    printf("%d %d ", fib1, fib2);
    for (int f = 2; f < 10; f++) {
        nextFib = fib1 + fib2;
        printf("%d ", nextFib);
        fib1 = fib2;
        fib2 = nextFib;
    }
    printf("\n");
    
    return 0;
}
