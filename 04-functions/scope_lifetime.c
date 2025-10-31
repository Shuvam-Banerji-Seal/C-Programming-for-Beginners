#include <stdio.h>

// Global variable
int globalVar = 100;

// Function with static variable
void counter() {
    static int count = 0;  // Static variable - retains value between calls
    count++;
    printf("Function called %d times\n", count);
}

// Function with local variable
void localDemo() {
    int local = 10;  // Local variable
    printf("Local variable in localDemo: %d\n", local);
    local = 20;
}

// Function that modifies global variable
void modifyGlobal() {
    printf("Global before modification: %d\n", globalVar);
    globalVar = 200;
    printf("Global after modification: %d\n", globalVar);
}

// Function with shadowing
void shadowDemo() {
    int globalVar = 50;  // Local variable shadows global
    printf("Shadowed variable (local): %d\n", globalVar);
    printf("Global variable (accessed via ::): Cannot directly access in C\n");
}

// Register variable demo
void registerDemo() {
    register int i;  // Suggestion to compiler to use register
    int sum = 0;
    for (i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("Sum of 1-100: %d\n", sum);
}

// Block scope demo
void blockScope() {
    int x = 10;
    printf("Outer block: x = %d\n", x);
    
    {
        int x = 20;  // Different variable in inner block
        printf("Inner block: x = %d\n", x);
        int y = 30;
        printf("Inner block: y = %d\n", y);
    }
    
    printf("Outer block after inner: x = %d\n", x);
    // printf("y = %d\n", y);  // Error: y is not accessible here
}

int main() {
    printf("=== Scope and Lifetime Demo ===\n\n");
    
    // Global variable
    printf("Global Variable:\n");
    printf("Initial global: %d\n", globalVar);
    modifyGlobal();
    printf("Global in main after modification: %d\n\n", globalVar);
    
    // Static variable
    printf("Static Variable:\n");
    counter();
    counter();
    counter();
    printf("\n");
    
    // Local variable
    printf("Local Variable:\n");
    localDemo();
    localDemo();  // local is reset to 10
    printf("\n");
    
    // Variable shadowing
    printf("Variable Shadowing:\n");
    printf("Global in main: %d\n", globalVar);
    shadowDemo();
    printf("Global after shadowDemo: %d\n\n", globalVar);
    
    // Register variable
    printf("Register Variable:\n");
    registerDemo();
    printf("\n");
    
    // Block scope
    printf("Block Scope:\n");
    blockScope();
    
    return 0;
}
