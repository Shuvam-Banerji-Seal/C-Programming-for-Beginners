/*
 * loop_control.c
 * Demonstrates break and continue statements
 * 
 * Topics: break, continue, loop control flow
 */

#include <stdio.h>

int main() {
    printf("=== Loop Control Statements Demo ===\n\n");
    
    // BREAK statement
    printf("1. BREAK statement:\n");
    
    // Example 1: Exit loop early
    printf("   Finding first number divisible by 7:\n   ");
    for (int i = 1; i <= 50; i++) {
        if (i % 7 == 0) {
            printf("Found: %d\n", i);
            break;  // Exit loop immediately
        }
    }
    
    // Example 2: Search in array
    printf("\n   Searching for value in array:\n");
    int numbers[] = {3, 7, 12, 5, 19, 8, 14};
    int search = 19;
    int found = 0;
    printf("   Array: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n   Searching for %d: ", search);
    
    for (int i = 0; i < 7; i++) {
        if (numbers[i] == search) {
            printf("Found at index %d!\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Not found\n");
    }
    
    // Example 3: Break in nested loops (only breaks inner loop)
    printf("\n   Break in nested loop:\n");
    for (int i = 1; i <= 3; i++) {
        printf("   Outer loop i=%d: ", i);
        for (int j = 1; j <= 5; j++) {
            if (j == 4) {
                printf("[BREAK] ");
                break;  // Only breaks inner loop
            }
            printf("%d ", j);
        }
        printf("\n");
    }
    
    // CONTINUE statement
    printf("\n2. CONTINUE statement:\n");
    
    // Example 1: Skip even numbers
    printf("   Print odd numbers 1-10: ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip rest of iteration
        }
        printf("%d ", i);
    }
    printf("\n");
    
    // Example 2: Skip multiples of 3
    printf("\n   Print 1-15, skip multiples of 3: ");
    for (int i = 1; i <= 15; i++) {
        if (i % 3 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    
    // Example 3: Process only positive numbers
    printf("\n   Sum only positive numbers:\n");
    int values[] = {5, -3, 8, -1, 12, -7, 4, 0, -2, 9};
    int sum = 0;
    
    printf("   Values: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", values[i]);
    }
    printf("\n   Processing: ");
    
    for (int i = 0; i < 10; i++) {
        if (values[i] <= 0) {
            printf("[skip %d] ", values[i]);
            continue;  // Skip non-positive numbers
        }
        sum += values[i];
        printf("[add %d] ", values[i]);
    }
    printf("\n   Sum of positive numbers: %d\n", sum);
    
    // COMBINING break and continue
    printf("\n3. Combining BREAK and CONTINUE:\n");
    printf("   Process numbers until sum exceeds 50:\n   ");
    
    int total = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        
        total += i;
        printf("%d ", i);
        
        if (total > 50) {
            printf("\n   Sum exceeded 50 (total=%d), stopping!\n", total);
            break;  // Stop when sum exceeds 50
        }
    }
    
    // USING break with while loop
    printf("\n4. BREAK with WHILE loop:\n");
    printf("   User input simulation (stop at 0):\n");
    
    int inputs[] = {5, 12, 7, 0, 3, 8};  // Simulated input
    int idx = 0;
    int count = 0;
    
    while (idx < 6) {
        int input = inputs[idx++];
        printf("   Input: %d", input);
        
        if (input == 0) {
            printf(" - STOP signal received\n");
            break;
        }
        
        count++;
        printf(" - Processed\n");
    }
    printf("   Processed %d values before stop\n", count);
    
    // USING continue with while loop
    printf("\n5. CONTINUE with WHILE loop:\n");
    printf("   Count down, skip multiples of 3:\n   ");
    
    int num = 10;
    while (num > 0) {
        if (num % 3 == 0) {
            num--;
            continue;  // Skip multiples of 3
        }
        printf("%d ", num);
        num--;
    }
    printf("\n");
    
    return 0;
}
