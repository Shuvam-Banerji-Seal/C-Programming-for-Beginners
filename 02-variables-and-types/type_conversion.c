/*
 * type_conversion.c
 * Demonstrates implicit and explicit type conversion
 */

#include <stdio.h>

int main() {
    printf("=== Type Conversion in C ===\n\n");
    
    // Implicit Type Conversion
    printf("--- Implicit Type Conversion ---\n");
    int i = 10;
    float f = 3.14;
    double result;
    
    result = i + f;  // int promoted to float
    printf("int %d + float %.2f = double %.2lf\n", i, f, result);
    
    char c = 'A';
    int ascii = c;  // char promoted to int
    printf("char '%c' as int = %d\n\n", c, ascii);
    
    // Explicit Type Conversion (Casting)
    printf("--- Explicit Type Conversion ---\n");
    float num = 9.8;
    int truncated = (int)num;
    printf("float %.1f cast to int = %d\n", num, truncated);
    
    // Integer division vs float division
    printf("\n--- Division Examples ---\n");
    int a = 7, b = 2;
    printf("Integer division: %d / %d = %d\n", a, b, a / b);
    printf("Float division: %d / %d = %.2f\n", a, b, (float)a / b);
    
    // Type promotion in expressions
    printf("\n--- Type Promotion ---\n");
    char ch1 = 'a';
    char ch2 = 'b';
    int sum = ch1 + ch2;  // chars promoted to int
    printf("'%c' + '%c' = %d (ASCII values)\n", ch1, ch2, sum);
    
    // Narrowing conversion (potential data loss)
    printf("\n--- Narrowing Conversion ---\n");
    double large = 1234567.89;
    float smaller = (float)large;
    int smallest = (int)smaller;
    printf("double: %.2lf\n", large);
    printf("float: %.2f\n", smaller);
    printf("int: %d (decimal part lost)\n", smallest);
    
    // Practical example: Fahrenheit to Celsius
    printf("\n--- Practical Example ---\n");
    int fahrenheit = 98;
    float celsius = (5.0 / 9.0) * (fahrenheit - 32);
    printf("%d°F = %.2f°C\n", fahrenheit, celsius);
    
    return 0;
}
