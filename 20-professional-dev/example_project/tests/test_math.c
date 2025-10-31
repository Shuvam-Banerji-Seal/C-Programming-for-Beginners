#include <stdio.h>
#include <assert.h>
#include "math_utils.h"

void test_add() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    assert(add(0, 0) == 0);
    printf("✓ test_add passed\n");
}

void test_multiply() {
    assert(multiply(2, 3) == 6);
    assert(multiply(-2, 3) == -6);
    assert(multiply(0, 5) == 0);
    printf("✓ test_multiply passed\n");
}

void test_factorial() {
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(5) == 120);
    printf("✓ test_factorial passed\n");
}

int main() {
    printf("Running tests...\n");
    test_add();
    test_multiply();
    test_factorial();
    printf("\nAll tests passed!\n");
    return 0;
}
