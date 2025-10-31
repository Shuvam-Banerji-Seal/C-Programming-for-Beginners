/*
 * nested_loops.c
 * Demonstrates nested loops and pattern printing
 * 
 * Topics: Nested loops, pattern printing, multiplication tables
 */

#include <stdio.h>

int main() {
    printf("=== Nested Loops Demo ===\n\n");
    
    // 1. Simple nested loop
    printf("1. Simple nested loop (3x3 grid):\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
    
    // 2. Multiplication table
    printf("\n2. Multiplication table (5x5):\n");
    printf("   ");
    for (int i = 1; i <= 5; i++) {
        printf("%4d", i);
    }
    printf("\n   ");
    for (int i = 1; i <= 5; i++) {
        printf("----");
    }
    printf("\n");
    
    for (int i = 1; i <= 5; i++) {
        printf("%2d |", i);
        for (int j = 1; j <= 5; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    
    // 3. Right-angled triangle (stars)
    printf("\n3. Right-angled triangle:\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    // 4. Inverted right triangle
    printf("\n4. Inverted right triangle:\n");
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    // 5. Pyramid
    printf("\n5. Pyramid:\n");
    for (int i = 1; i <= 5; i++) {
        // Print spaces
        for (int j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // 6. Diamond pattern
    printf("\n6. Diamond pattern:\n");
    int n = 5;
    // Upper half
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // 7. Number pyramid
    printf("\n7. Number pyramid:\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    // 8. Hollow square
    printf("\n8. Hollow square:\n");
    int size = 5;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    // 9. Pascal's triangle
    printf("\n9. Pascal's triangle:\n");
    int rows = 6;
    for (int i = 0; i < rows; i++) {
        // Print spaces
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }
        
        // Calculate and print values
        int value = 1;
        for (int j = 0; j <= i; j++) {
            printf("%d ", value);
            value = value * (i - j) / (j + 1);
        }
        printf("\n");
    }
    
    return 0;
}
