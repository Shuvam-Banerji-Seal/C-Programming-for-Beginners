/*
 * watchpoint_example.c
 * Example for practicing GDB watchpoints
 * 
 * Learn to track when variables change
 */

#include <stdio.h>

int global_counter = 0;

void increment_counter(int amount) {
    global_counter += amount;
}

void reset_counter() {
    global_counter = 0;
}

int main() {
    printf("=== GDB Watchpoint Example ===\n\n");
    
    printf("Initial counter: %d\n", global_counter);
    
    // Multiple operations that modify the counter
    increment_counter(5);
    printf("After increment(5): %d\n", global_counter);
    
    increment_counter(10);
    printf("After increment(10): %d\n", global_counter);
    
    increment_counter(3);
    printf("After increment(3): %d\n", global_counter);
    
    reset_counter();
    printf("After reset: %d\n", global_counter);
    
    increment_counter(7);
    printf("After increment(7): %d\n", global_counter);
    
    printf("\n=== GDB Watchpoint Practice ===\n");
    printf("To practice:\n");
    printf("1. Compile: gcc -g -o watchpoint watchpoint_example.c\n");
    printf("2. Start GDB: gdb ./watchpoint\n");
    printf("3. Set breakpoint: break main\n");
    printf("4. Run: run\n");
    printf("5. Set watchpoint: watch global_counter\n");
    printf("6. Continue: continue\n");
    printf("7. Observe when variable changes!\n");
    
    return 0;
}
