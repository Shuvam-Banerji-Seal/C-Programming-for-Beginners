/*
 * preprocessor_demo.c
 * Demonstrates C preprocessor directives
 * Topics: #define, #include, #ifdef, macros, conditional compilation
 */

#include <stdio.h>

// Simple macros
#define PI 3.14159
#define MAX_SIZE 100
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define PRINT_VAR(var) printf(#var " = %d\n", var)

// Conditional compilation
#define DEBUG_MODE 1

int main() {
    printf("=== Preprocessor Demo ===\n\n");
    
    // Using macros
    printf("1. Simple Macros:\n");
    printf("   PI = %.5f\n", PI);
    printf("   MAX_SIZE = %d\n\n", MAX_SIZE);
    
    // Function-like macros
    printf("2. Function-like Macros:\n");
    int x = 5;
    printf("   SQUARE(5) = %d\n", SQUARE(x));
    printf("   MAX(10, 20) = %d\n\n", MAX(10, 20));
    
    // Stringification
    printf("3. Stringification:\n");
    int value = 42;
    PRINT_VAR(value);
    printf("\n");
    
    // Conditional compilation
    printf("4. Conditional Compilation:\n");
#ifdef DEBUG_MODE
    printf("   Debug mode is ON\n");
#else
    printf("   Debug mode is OFF\n");
#endif
    
    // Predefined macros
    printf("\n5. Predefined Macros:\n");
    printf("   File: %s\n", __FILE__);
    printf("   Line: %d\n", __LINE__);
    printf("   Date: %s\n", __DATE__);
    printf("   Time: %s\n", __TIME__);
    
    return 0;
}
