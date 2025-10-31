/*
 * basic_io.c
 * Demonstrates basic input/output operations in C
 */

#include <stdio.h>

int main() {
    int age;
    float height;
    char grade;
    
    printf("=== Basic Input/Output Demo ===\n\n");
    
    // Integer input/output
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("You are %d years old.\n\n", age);
    
    // Float input/output
    printf("Enter your height in meters (e.g., 1.75): ");
    scanf("%f", &height);
    printf("Your height is %.2f meters.\n\n", height);
    
    // Character input/output
    printf("Enter your grade (A, B, C, etc.): ");
    scanf(" %c", &grade);  // Note the space before %c to skip whitespace
    printf("Your grade is: %c\n\n", grade);
    
    // Summary
    printf("=== Summary ===\n");
    printf("Age: %d years\n", age);
    printf("Height: %.2f meters\n", height);
    printf("Grade: %c\n", grade);
    
    return 0;
}
