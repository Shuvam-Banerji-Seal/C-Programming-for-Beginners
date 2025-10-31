/*
 * switch_buggy.c
 * DELIBERATELY BUGGY CODE - For learning purposes
 * 
 * This file contains common mistakes with switch statements.
 * Each bug is explained with comments.
 */

#include <stdio.h>

int main() {
    printf("=== Buggy Switch Statement Demo ===\n\n");
    
    // BUG #1: Missing break statements (unintentional fall-through)
    int day = 3;
    printf("BUG #1: Missing breaks\n");
    switch (day) {
        case 1:
            printf("  Monday\n");
            // WRONG: Missing break! Falls through to next case
        case 2:
            printf("  Tuesday\n");
            // WRONG: Missing break! Falls through to next case
        case 3:
            printf("  Wednesday\n");
            // WRONG: Missing break! Falls through to next case
        case 4:
            printf("  Thursday\n");
            break;  // Only this one has break
        default:
            printf("  Other day\n");
    }
    printf("Without breaks, multiple cases execute!\n\n");
    
    // BUG #2: Using switch with floating point (not allowed)
    // float value = 1.5f;
    // switch (value) {  // COMPILE ERROR: switch expression must be integer type
    //     case 1.5f:
    //         printf("One and a half\n");
    //         break;
    // }
    printf("BUG #2: Cannot use switch with float or double!\n");
    printf("Switch only works with integer types (int, char, enum)\n\n");
    
    // BUG #3: Using non-constant expressions in case labels
    int x = 10;
    int threshold = 5;
    // switch (x) {
    //     case threshold:  // COMPILE ERROR: case label must be a constant
    //         printf("Equal to threshold\n");
    //         break;
    // }
    printf("BUG #3: Case labels must be compile-time constants!\n");
    printf("Cannot use variables in case labels\n\n");
    
    // BUG #4: Duplicate case labels
    char grade = 'A';
    // switch (grade) {
    //     case 'A':
    //         printf("Excellent\n");
    //         break;
    //     case 'A':  // COMPILE ERROR: Duplicate case label
    //         printf("Also excellent?\n");
    //         break;
    // }
    printf("BUG #4: Cannot have duplicate case labels!\n");
    printf("Each case must be unique\n\n");
    
    // BUG #5: Missing default case (not always a bug, but often important)
    int number = 99;
    printf("BUG #5: Missing default case\n");
    switch (number) {
        case 1:
            printf("  Number is 1\n");
            break;
        case 2:
            printf("  Number is 2\n");
            break;
        // WRONG: No default case to handle unexpected values
    }
    printf("No output for number=%d because no default case!\n\n", number);
    
    // BUG #6: Using switch on strings (not directly possible in C)
    // char* color = "red";
    // switch (color) {  // COMPILE ERROR: Cannot switch on pointer/string
    //     case "red":
    //         printf("Color is red\n");
    //         break;
    // }
    printf("BUG #6: Cannot use switch with strings!\n");
    printf("Use if-else with strcmp() for string comparison\n\n");
    
    // BUG #7: Variables declared in case without braces
    int option = 1;
    switch (option) {
        case 1:
            // int temp = 100;  // WRONG: Can cause issues, use braces
            // Better approach shown in case 2
            printf("  Case 1\n");
            break;
        case 2: {  // Correct: Use braces when declaring variables
            int temp = 200;
            printf("  Case 2, temp=%d\n", temp);
            break;
        }
        default:
            printf("  Default case\n");
    }
    printf("BUG #7 Note: Declare variables in case blocks with braces\n\n");
    
    // BUG #8: Using break incorrectly (not in a loop or switch)
    // if (x > 5) {
    //     break;  // COMPILE ERROR: break not in loop or switch
    // }
    printf("BUG #8: break only works inside loops and switch!\n");
    printf("Cannot use break in regular if statements\n\n");
    
    return 0;
}
