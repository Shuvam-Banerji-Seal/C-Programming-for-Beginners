#include <stdio.h>

// Arithmetic operations
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

// Callback function type
typedef void (*PrintCallback)(int);

// Higher-order function
void forEach(int arr[], int size, PrintCallback callback) {
    for (int i = 0; i < size; i++) {
        callback(arr[i]);
    }
}

// Different print operations
void printDouble(int n) {
    printf("%d ", n * 2);
}

void printSquare(int n) {
    printf("%d ", n * n);
}

void printCube(int n) {
    printf("%d ", n * n * n);
}

// Calculator using function pointers
int calculator(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

int main() {
    printf("=== Function Pointers Demo ===\n\n");
    
    // Basic function pointer
    printf("Basic Function Pointer:\n");
    int (*operation)(int, int);
    
    operation = add;
    printf("5 + 3 = %d\n", operation(5, 3));
    
    operation = subtract;
    printf("5 - 3 = %d\n", operation(5, 3));
    
    operation = multiply;
    printf("5 * 3 = %d\n", operation(5, 3));
    
    operation = divide;
    printf("15 / 3 = %d\n\n", operation(15, 3));
    
    // Array of function pointers
    printf("Array of Function Pointers:\n");
    int (*operations[])(int, int) = {add, subtract, multiply, divide};
    char *names[] = {"add", "subtract", "multiply", "divide"};
    
    for (int i = 0; i < 4; i++) {
        printf("%s(10, 5) = %d\n", names[i], operations[i](10, 5));
    }
    printf("\n");
    
    // Callback functions
    printf("Callback Functions:\n");
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original: ");
    for (int i = 0; i < size; i++) printf("%d ", numbers[i]);
    printf("\n");
    
    printf("Doubled: ");
    forEach(numbers, size, printDouble);
    printf("\n");
    
    printf("Squared: ");
    forEach(numbers, size, printSquare);
    printf("\n");
    
    printf("Cubed: ");
    forEach(numbers, size, printCube);
    printf("\n\n");
    
    // Calculator with function pointers
    printf("Calculator Function:\n");
    printf("calculator(20, 5, add) = %d\n", calculator(20, 5, add));
    printf("calculator(20, 5, multiply) = %d\n", calculator(20, 5, multiply));
    
    return 0;
}
