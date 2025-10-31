#include <stdio.h>

// Function declarations
void greet(void);
int add(int a, int b);
int subtract(int a, int b);
float divide(float a, float b);
int maximum(int a, int b, int c);
void printLine(int length);

int main() {
    printf("=== Basic Functions Demo ===\n\n");
    
    // Simple function with no parameters
    greet();
    
    // Functions with parameters
    printf("5 + 3 = %d\n", add(5, 3));
    printf("10 - 4 = %d\n", subtract(10, 4));
    printf("15.0 / 4.0 = %.2f\n", divide(15.0, 4.0));
    
    // Function with multiple parameters
    printf("Maximum of 5, 12, 8 is: %d\n", maximum(5, 12, 8));
    
    printLine(40);
    
    return 0;
}

void greet(void) {
    printf("Hello from a function!\n");
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int maximum(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

void printLine(int length) {
    for (int i = 0; i < length; i++) {
        printf("-");
    }
    printf("\n");
}
