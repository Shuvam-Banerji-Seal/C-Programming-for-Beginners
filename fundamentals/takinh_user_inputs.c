#include <stdio.h>

// void menu() {
//     printf("1. Compute nPr\n");
//     printf("2. Compute nCr\n");
//     printf("3. Exit\n");
// }
int main() {
    int c, n, r=0;

start: 
    printf("Enter the value of n: ");
    r = scanf("%d", &n);
    // printf("\n The value of n is %d\n", n);
    // printf("Enter the value of r: %d \n", r);
    if (r != 1) {
        printf("Invalid input for n. Please enter an integer.\n");
        while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
        goto start;
    }


    if (r==1)
    {
        printf("Enter the value of r: ");
        r = scanf("%d", &r);
        if (r != 1) {
            printf("Invalid input for r. Please enter an integer.\n");
            while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
            goto start;
        }
    }

    return 0;
}