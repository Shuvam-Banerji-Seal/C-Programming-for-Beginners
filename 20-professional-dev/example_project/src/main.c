#include <stdio.h>
#include "math_utils.h"

int main() {
    printf("Math Utils Example\n");
    printf("==================\n\n");
    
    int a = 5, b = 3;
    
    printf("Addition: %d + %d = %d\n", a, b, add(a, b));
    printf("Multiplication: %d * %d = %d\n", a, b, multiply(a, b));
    printf("Factorial of %d = %d\n", a, factorial(a));
    
    return 0;
}
