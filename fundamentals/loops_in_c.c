#include <stdio.h>


void main() {
    // For Loop
    int i;
    printf("For Loop:\n");
    for (i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("The loop variable after the loop: %d", i); // i will be 6 after the loop
    printf("\n");

    // While Loop
    printf("While Loop:\n");
    int j = 1;
    while (j <= 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n");

    // Do-While Loop
    printf("Do-While Loop:\n");
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 5);
    printf("\n");
}