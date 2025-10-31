/*
 * stack.c
 * Implements a stack data structure
 * Topics: LIFO, push, pop, peek
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (!is_full(s)) {
        s->items[++s->top] = value;
        printf("   Pushed: %d\n", value);
    } else {
        printf("   Stack overflow!\n");
    }
}

int pop(Stack *s) {
    if (!is_empty(s)) {
        return s->items[s->top--];
    }
    printf("   Stack underflow!\n");
    return -1;
}

int main() {
    printf("=== Stack Demo (LIFO) ===\n\n");
    
    Stack stack;
    init_stack(&stack);
    
    printf("1. Pushing elements:\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printf("\n2. Popping elements:\n");
    printf("   Popped: %d\n", pop(&stack));
    printf("   Popped: %d\n", pop(&stack));
    printf("   Popped: %d\n", pop(&stack));
    
    return 0;
}
