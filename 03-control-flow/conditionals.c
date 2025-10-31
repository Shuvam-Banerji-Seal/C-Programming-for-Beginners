/*
 * conditionals.c
 * Demonstrates various conditional statements in C
 * 
 * Topics: if, else, else-if, nested conditionals
 */

#include <stdio.h>

int main() {
    printf("=== Conditional Statements Demo ===\n\n");
    
    // Simple if statement
    int age = 20;
    printf("Age check:\n");
    if (age >= 18) {
        printf("  You are an adult (age: %d)\n", age);
    }
    
    // if-else statement
    int number = 7;
    printf("\nEven/Odd check:\n");
    if (number % 2 == 0) {
        printf("  %d is even\n", number);
    } else {
        printf("  %d is odd\n", number);
    }
    
    // if-else-if ladder
    int score = 85;
    printf("\nGrade calculation:\n");
    if (score >= 90) {
        printf("  Grade: A (score: %d)\n", score);
    } else if (score >= 80) {
        printf("  Grade: B (score: %d)\n", score);
    } else if (score >= 70) {
        printf("  Grade: C (score: %d)\n", score);
    } else if (score >= 60) {
        printf("  Grade: D (score: %d)\n", score);
    } else {
        printf("  Grade: F (score: %d)\n", score);
    }
    
    // Nested if statements
    int driver_age = 25;
    int has_license = 1; // 1 = true, 0 = false
    printf("\nDriving eligibility check:\n");
    if (driver_age >= 18) {
        if (has_license) {
            printf("  You can drive!\n");
        } else {
            printf("  You are old enough but need a license.\n");
        }
    } else {
        printf("  You are too young to drive.\n");
    }
    
    // Ternary operator (shorthand for if-else)
    int x = 10, y = 20;
    int max = (x > y) ? x : y;
    printf("\nTernary operator:\n");
    printf("  Maximum of %d and %d is: %d\n", x, y, max);
    
    // Multiple conditions with logical operators
    int temp = 25;
    printf("\nTemperature comfort check:\n");
    if (temp >= 20 && temp <= 28) {
        printf("  Temperature %d°C is comfortable\n", temp);
    } else if (temp < 20) {
        printf("  Temperature %d°C is cold\n", temp);
    } else {
        printf("  Temperature %d°C is hot\n", temp);
    }
    
    return 0;
}
