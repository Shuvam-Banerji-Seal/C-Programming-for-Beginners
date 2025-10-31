/*
 * conditionals_buggy.c
 * DELIBERATELY BUGGY CODE - For learning purposes
 * 
 * This file contains common mistakes with conditional statements.
 * Each bug is explained with comments.
 */

#include <stdio.h>

int main() {
    printf("=== Buggy Conditional Statements Demo ===\n\n");
    
    // BUG #1: Using assignment (=) instead of comparison (==)
    // This assigns 18 to age instead of comparing!
    int age = 20;
    if (age = 18) {  // WRONG: should be age == 18
        printf("BUG #1: Age is exactly 18\n");
    }
    // After this, age is now 18, not 20!
    printf("Age is now: %d (should be 20 but got modified!)\n\n", age);
    
    // BUG #2: Missing braces leading to unexpected behavior
    int score = 85;
    if (score > 90)
        printf("BUG #2: Excellent!\n");
        printf("This always prints!\n");  // WRONG: Always executes, not just when score > 90
    printf("\n");
    
    // BUG #3: Semicolon after if condition (null statement)
    int x = 5;
    if (x > 0);  // WRONG: Semicolon creates empty statement
    {
        printf("BUG #3: This always prints regardless of condition!\n\n");
    }
    
    // BUG #4: Comparing floats with == (precision issues)
    float value = 0.1f + 0.1f + 0.1f;  // May not be exactly 0.3 due to floating point precision
    if (value == 0.3f) {  // WRONG: May fail due to floating point precision
        printf("BUG #4: Value is exactly 0.3\n");
    } else {
        printf("BUG #4: Value is NOT exactly 0.3 (it's %.20f)\n", value);
    }
    printf("This demonstrates floating point precision issues!\n\n");
    
    // BUG #5: Missing break in logical conditions
    int number = 10;
    // Wrong logic: should check if number is between 5 and 15
    if (number > 5 && number < 15) {  // Correct way
        printf("BUG #5 Fixed: Number is between 5 and 15\n");
    }
    // Common mistake thinking:
    // if (5 < number < 15)  // WRONG: This doesn't work as expected!
    // The above gets evaluated as (5 < number) < 15, which is always true
    printf("\n");
    
    // BUG #6: Incorrect operator precedence without parentheses
    int a = 5, b = 10, c = 15;
    if (a < b && b < c || a > c) {  // Might not behave as expected
        printf("BUG #6: Operator precedence might surprise you!\n");
    }
    // Better: if ((a < b && b < c) || (a > c))
    printf("Always use parentheses for clarity!\n\n");
    
    // BUG #7: Using bitwise AND (&) instead of logical AND (&&)
    int flag1 = 1, flag2 = 2;
    if (flag1 & flag2) {  // WRONG: Bitwise AND, not logical AND
        printf("BUG #7: This uses bitwise AND, not logical AND!\n");
    }
    // Correct: if (flag1 && flag2)
    printf("Use && for logical operations, & for bitwise!\n\n");
    
    // BUG #8: Off-by-one error in range checking
    int day = 7;
    if (day >= 1 && day < 7) {  // WRONG: Excludes day 7 (Sunday)
        printf("BUG #8: Valid weekday\n");
    } else {
        printf("BUG #8: Invalid or missing Sunday! (day=%d)\n", day);
    }
    // Correct: if (day >= 1 && day <= 7)
    printf("\n");
    
    return 0;
}
