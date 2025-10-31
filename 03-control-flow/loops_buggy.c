/*
 * loops_buggy.c
 * DELIBERATELY BUGGY CODE - For learning purposes
 * 
 * This file contains common mistakes with loops.
 * Each bug is explained with comments.
 */

#include <stdio.h>

int main() {
    printf("=== Buggy Loops Demo ===\n\n");
    
    // BUG #1: Off-by-one error (fencepost error)
    printf("BUG #1: Off-by-one error\n");
    printf("Want to print 1 to 5, but: ");
    for (int i = 1; i < 5; i++) {  // WRONG: Stops at 4, not 5
        printf("%d ", i);
    }
    printf("(missing 5!)\n");
    printf("Should be: i <= 5 or i < 6\n\n");
    
    // BUG #2: Infinite loop due to wrong condition
    printf("BUG #2: Infinite loop risk\n");
    // Commented out to prevent actual infinite loop
    // int x = 0;
    // while (x >= 0) {  // WRONG: x is always >= 0, never ends!
    //     printf("%d ", x);
    //     x++;
    // }
    printf("while (x >= 0) with x++ will never end!\n");
    printf("Use x < 10 or similar finite condition\n\n");
    
    // BUG #3: Modifying loop counter inside the loop
    printf("BUG #3: Modifying loop counter\n");
    printf("Unpredictable behavior: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        if (i == 5) {
            i = 8;  // WRONG: Modifying loop counter manually
        }
    }
    printf("\nSkipped values due to manual modification!\n\n");
    
    // BUG #4: Floating point comparison in loop
    printf("BUG #4: Floating point loop counter\n");
    printf("May not work as expected: ");
    // This might not iterate exactly 10 times due to floating point precision
    for (float f = 0.0f; f < 1.0f; f += 0.1f) {  // WRONG: Avoid float counters
        printf("%.1f ", f);
    }
    printf("\nFloating point errors can cause unexpected iterations!\n\n");
    
    // BUG #5: Semicolon after loop header
    printf("BUG #5: Semicolon after for statement\n");
    for (int i = 0; i < 5; i++);  // WRONG: Semicolon creates empty loop
    {
        printf("This prints only once, not 5 times!\n");
    }
    printf("\n");
    
    // BUG #6: Wrong increment/decrement operator
    printf("BUG #6: Wrong operator direction\n");
    printf("Want countdown, but using ++: ");
    for (int i = 5; i > 0; i++) {  // WRONG: i++ makes it go up, not down
        if (i > 10) break;  // Safety to prevent infinite loop
        printf("%d ", i);
    }
    printf("(infinite loop potential!)\n");
    printf("Should use i-- for countdown\n\n");
    
    // BUG #7: Uninitialized loop counter
    printf("BUG #7: Uninitialized counter\n");
    int count;  // WRONG: Not initialized
    // The value of count is undefined, could be any value!
    printf("count starts at undefined value (could be: %d)\n", count);
    printf("Always initialize variables before use!\n\n");
    
    // BUG #8: Confusion between = and ==
    printf("BUG #8: Assignment in loop condition\n");
    int val = 0;
    // while (val = 5) {  // WRONG: Assignment, not comparison! Always true
    //     printf("Infinite loop!\n");
    //     if (val > 5) break;
    // }
    printf("while (val = 5) assigns 5 to val and creates infinite loop!\n");
    printf("Should be: while (val == 5) or while (val != 0)\n\n");
    
    // BUG #9: Wrong loop type selection
    printf("BUG #9: Using do-while when condition is false from start\n");
    int num = 10;
    do {
        printf("This executes even though num (%d) < 5 is false!\n", num);
    } while (num < 5);  // WRONG: do-while executes at least once
    printf("Should use while loop if you don't want guaranteed execution\n\n");
    
    // BUG #10: Missing braces with nested loops
    printf("BUG #10: Missing braces in nested context\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            printf("(%d,%d) ", i, j);
            // The line below might seem like it's in the inner loop, but it's not!
    printf("- This prints only once\n");
    printf("Without braces, it's easy to misunderstand scope!\n\n");
    
    // BUG #11: Unreachable code after continue
    printf("BUG #11: Unreachable code\n");
    for (int i = 1; i <= 5; i++) {
        if (i % 2 == 0) {
            continue;
            printf("This never executes! "); // WRONG: Code after continue is unreachable
        }
        printf("%d ", i);
    }
    printf("\nCode after continue is never reached!\n");
    
    return 0;
}
