/*
 * stack_vs_heap.c
 * Demonstrates the difference between stack and heap memory
 * 
 * Topics: Stack allocation, heap allocation, scope, lifetime
 */

#include <stdio.h>
#include <stdlib.h>

// Global variable (stored in data segment, not stack or heap)
int global_var = 100;

// Function demonstrating stack allocation
void stack_example() {
    int local_var = 50;  // Allocated on stack
    printf("   Local variable (stack): %d\n", local_var);
    printf("   Address: %p\n", (void*)&local_var);
    // local_var is destroyed when function returns
}

// Function demonstrating heap allocation
int* heap_example() {
    int *heap_var = (int*)malloc(sizeof(int));  // Allocated on heap
    if (heap_var != NULL) {
        *heap_var = 75;
        printf("   Heap variable: %d\n", *heap_var);
        printf("   Address: %p\n", (void*)heap_var);
    }
    return heap_var;  // Pointer survives function return
    // Caller must free this memory!
}

// WRONG: Returning pointer to stack variable
int* buggy_return() {
    int local = 42;
    return &local;  // DANGER: local is destroyed after return!
}

int main() {
    printf("=== Stack vs Heap Memory Demo ===\n\n");
    
    // Stack allocation
    printf("1. Stack Allocation:\n");
    printf("   - Automatic allocation/deallocation\n");
    printf("   - Fast access\n");
    printf("   - Limited size (typically 1-8 MB)\n");
    printf("   - LIFO (Last In, First Out)\n\n");
    
    int stack_var1 = 10;
    int stack_var2 = 20;
    int stack_var3 = 30;
    
    printf("   Stack variables:\n");
    printf("      stack_var1: %d at %p\n", stack_var1, (void*)&stack_var1);
    printf("      stack_var2: %d at %p\n", stack_var2, (void*)&stack_var2);
    printf("      stack_var3: %d at %p\n", stack_var3, (void*)&stack_var3);
    printf("   Notice: Addresses are close together (sequential)\n\n");
    
    // Heap allocation
    printf("2. Heap Allocation:\n");
    printf("   - Manual allocation/deallocation (malloc/free)\n");
    printf("   - Slower access\n");
    printf("   - Large size (limited by available RAM)\n");
    printf("   - No specific order\n\n");
    
    int *heap_var1 = (int*)malloc(sizeof(int));
    int *heap_var2 = (int*)malloc(sizeof(int));
    int *heap_var3 = (int*)malloc(sizeof(int));
    
    if (heap_var1 && heap_var2 && heap_var3) {
        *heap_var1 = 100;
        *heap_var2 = 200;
        *heap_var3 = 300;
        
        printf("   Heap variables:\n");
        printf("      heap_var1: %d at %p\n", *heap_var1, (void*)heap_var1);
        printf("      heap_var2: %d at %p\n", *heap_var2, (void*)heap_var2);
        printf("      heap_var3: %d at %p\n", *heap_var3, (void*)heap_var3);
        printf("   Notice: Addresses may be far apart\n\n");
        
        free(heap_var1);
        free(heap_var2);
        free(heap_var3);
    }
    
    // Global variable
    printf("3. Global Variable:\n");
    printf("   - Stored in data segment (not stack or heap)\n");
    printf("   - Exists for entire program lifetime\n");
    printf("   global_var: %d at %p\n\n", global_var, (void*)&global_var);
    
    // Function scope demonstration
    printf("4. Function Scope:\n");
    stack_example();
    printf("   Stack variable is destroyed after function returns\n\n");
    
    int *heap_ptr = heap_example();
    if (heap_ptr != NULL) {
        printf("   Heap variable still accessible: %d\n", *heap_ptr);
        free(heap_ptr);  // Must free manually
        printf("   Freed heap memory\n\n");
    }
    
    // Comparison table
    printf("5. Stack vs Heap Comparison:\n");
    printf("   +----------------+------------------+------------------+\n");
    printf("   | Feature        | Stack            | Heap             |\n");
    printf("   +----------------+------------------+------------------+\n");
    printf("   | Allocation     | Automatic        | Manual           |\n");
    printf("   | Deallocation   | Automatic        | Manual (free)    |\n");
    printf("   | Speed          | Fast             | Slower           |\n");
    printf("   | Size           | Small (MB)       | Large (GB)       |\n");
    printf("   | Fragmentation  | No               | Yes              |\n");
    printf("   | Lifetime       | Function scope   | Until freed      |\n");
    printf("   | Order          | LIFO             | No order         |\n");
    printf("   +----------------+------------------+------------------+\n\n");
    
    // When to use which
    printf("6. When to Use:\n");
    printf("   Stack:\n");
    printf("   - Small, fixed-size data\n");
    printf("   - Local variables\n");
    printf("   - Fast temporary storage\n\n");
    
    printf("   Heap:\n");
    printf("   - Large data structures\n");
    printf("   - Unknown size at compile time\n");
    printf("   - Data that needs to persist\n");
    printf("   - Sharing data between functions\n\n");
    
    // Array example
    printf("7. Array Allocation:\n");
    int stack_array[5] = {1, 2, 3, 4, 5};  // Stack
    int *heap_array = (int*)malloc(5 * sizeof(int));  // Heap
    
    if (heap_array != NULL) {
        for (int i = 0; i < 5; i++) {
            heap_array[i] = stack_array[i];
        }
        
        printf("   Stack array: %p\n", (void*)stack_array);
        printf("   Heap array:  %p\n", (void*)heap_array);
        
        free(heap_array);
    }
    
    return 0;
}
