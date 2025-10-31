/*
 * operators.c
 * Comprehensive demonstration of all operators in C
 */

#include <stdio.h>

int main() {
    printf("=== C Operators Demo ===\n\n");
    
    // Arithmetic Operators
    printf("--- Arithmetic Operators ---\n");
    int a = 15, b = 4;
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n\n", a % b);
    
    // Relational Operators
    printf("--- Relational Operators ---\n");
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n\n", a <= b);
    
    // Logical Operators
    printf("--- Logical Operators ---\n");
    int x = 1, y = 0;
    printf("x = %d, y = %d\n", x, y);
    printf("x && y: %d\n", x && y);
    printf("x || y: %d\n", x || y);
    printf("!x: %d\n", !x);
    printf("!y: %d\n\n", !y);
    
    // Bitwise Operators
    printf("--- Bitwise Operators ---\n");
    unsigned int p = 5, q = 3;
    printf("p = %u (binary: 0101), q = %u (binary: 0011)\n", p, q);
    printf("p & q = %u (AND)\n", p & q);
    printf("p | q = %u (OR)\n", p | q);
    printf("p ^ q = %u (XOR)\n", p ^ q);
    printf("~p = %u (NOT)\n", ~p);
    printf("p << 1 = %u (Left shift)\n", p << 1);
    printf("p >> 1 = %u (Right shift)\n\n", p >> 1);
    
    // Assignment Operators
    printf("--- Assignment Operators ---\n");
    int n = 10;
    printf("Initial n = %d\n", n);
    n += 5;
    printf("After n += 5: %d\n", n);
    n -= 3;
    printf("After n -= 3: %d\n", n);
    n *= 2;
    printf("After n *= 2: %d\n", n);
    n /= 4;
    printf("After n /= 4: %d\n", n);
    n %= 3;
    printf("After n %%= 3: %d\n\n", n);
    
    // Ternary Operator
    printf("--- Ternary Operator ---\n");
    int max = (a > b) ? a : b;
    printf("Maximum of %d and %d is: %d\n\n", a, b, max);
    
    // sizeof Operator
    printf("--- sizeof Operator ---\n");
    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Size of double: %lu bytes\n", sizeof(double));
    printf("Size of char: %lu bytes\n", sizeof(char));
    
    return 0;
}
