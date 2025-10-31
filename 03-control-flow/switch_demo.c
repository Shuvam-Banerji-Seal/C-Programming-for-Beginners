/*
 * switch_demo.c
 * Demonstrates proper use of switch statements
 * 
 * Topics: switch-case, break, default, fall-through
 */

#include <stdio.h>

int main() {
    printf("=== Switch Statement Demo ===\n\n");
    
    // Basic switch with break
    int day = 3;
    printf("Day of the week (day=%d):\n", day);
    switch (day) {
        case 1:
            printf("  Monday - Start of work week!\n");
            break;
        case 2:
            printf("  Tuesday\n");
            break;
        case 3:
            printf("  Wednesday - Midweek!\n");
            break;
        case 4:
            printf("  Thursday\n");
            break;
        case 5:
            printf("  Friday - Almost weekend!\n");
            break;
        case 6:
            printf("  Saturday - Weekend!\n");
            break;
        case 7:
            printf("  Sunday - Weekend!\n");
            break;
        default:
            printf("  Invalid day number\n");
    }
    
    // Switch with fall-through (intentional)
    char grade = 'B';
    printf("\nGrade evaluation (grade=%c):\n", grade);
    switch (grade) {
        case 'A':
            printf("  Excellent! 90-100%%\n");
            break;
        case 'B':
        case 'C':
            printf("  Good job! 70-89%%\n");
            break;
        case 'D':
            printf("  You passed. 60-69%%\n");
            break;
        case 'F':
            printf("  Failed. Below 60%%\n");
            break;
        default:
            printf("  Invalid grade\n");
    }
    
    // Switch with multiple operations per case
    char operation = '+';
    int a = 10, b = 5;
    printf("\nSimple calculator (%d %c %d):\n", a, operation, b);
    switch (operation) {
        case '+':
            printf("  Result: %d\n", a + b);
            break;
        case '-':
            printf("  Result: %d\n", a - b);
            break;
        case '*':
            printf("  Result: %d\n", a * b);
            break;
        case '/':
            if (b != 0) {
                printf("  Result: %d\n", a / b);
            } else {
                printf("  Error: Division by zero!\n");
            }
            break;
        case '%':
            if (b != 0) {
                printf("  Result: %d\n", a % b);
            } else {
                printf("  Error: Modulo by zero!\n");
            }
            break;
        default:
            printf("  Invalid operation\n");
    }
    
    // Switch with enum (more readable)
    enum Months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
    int month = MAY;
    printf("\nDays in month (month=%d):\n", month);
    switch (month) {
        case JAN: case MAR: case MAY: case JUL: case AUG: case OCT: case DEC:
            printf("  31 days\n");
            break;
        case APR: case JUN: case SEP: case NOV:
            printf("  30 days\n");
            break;
        case FEB:
            printf("  28 or 29 days (leap year dependent)\n");
            break;
        default:
            printf("  Invalid month\n");
    }
    
    return 0;
}
