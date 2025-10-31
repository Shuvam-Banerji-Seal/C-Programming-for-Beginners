#include <stdio.h>

void main() {
    int a = 10; // Integer variable
    float b = 5.5; // Floating-point variable
    char c = 'A'; // Character variable

    printf("Integer: %d\n", a);
    printf("Float: %.2f\n", b);
    printf("Character: %c\n", c);


    printf("Post-increment:\n");
    printf("Value of a: %d\n", a++); // Post-increment: use the value, then increment
    printf("Value of a after post-increment: %d\n", a); // a is now incremented

    printf("Pre-increment:\n");
    printf("Value of a: %d\n", ++a); // Pre-increment: increment first, then use the value
    printf("Value of a after pre-increment: %d\n", a); // a is now incremented again

    printf("Post-increment on float:\n");
    printf("Value of b: %.2f\n", b++); // Post-increment
    printf("Value of b after post-increment: %.2f\n", b); // b is now incremented

    printf("Pre-increment on float:\n");
    printf("Value of b: %.2f\n", ++b); // Pre-increment
    printf("Value of b after pre-increment: %.2f\n", b); // b is now incremented again

    printf("Post-increment on char:\n");
    printf("Value of c: %c\n", c++); // Post-increment
    printf("Value of c after post-increment: %c\n", c); // c is now incremented


    c = 'Z'; // Reset c to 'Z' for demonstration
    printf("Pre-increment on char:\n");
    printf("Value of c: %c\n", ++c); // Pre-increment
    printf("Value of c after pre-increment: %c\n", c); // c is now incremented again


    printf("Value of a: %d\n after complex expression \n", ++a + a++ + ++a + a++); // Complex expression with mixed increments
}