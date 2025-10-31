#include <stdio.h>

// Pass by value
void tryToModify(int x) {
    x = 100;
    printf("Inside tryToModify: x = %d\n", x);
}

// Pass by reference using pointer
void modify(int *x) {
    *x = 100;
    printf("Inside modify: *x = %d\n", *x);
}

// Swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Return multiple values using pointers
void getMinMax(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int main() {
    printf("=== Pass by Value vs Pass by Reference ===\n\n");
    
    // Pass by value demo
    printf("Pass by Value:\n");
    int num = 10;
    printf("Before: num = %d\n", num);
    tryToModify(num);
    printf("After: num = %d\n\n", num);
    
    // Pass by reference demo
    printf("Pass by Reference:\n");
    num = 10;
    printf("Before: num = %d\n", num);
    modify(&num);
    printf("After: num = %d\n\n", num);
    
    // Swap demo
    printf("Swap Function:\n");
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n\n", x, y);
    
    // Multiple return values
    printf("Return Multiple Values:\n");
    int numbers[] = {23, 45, 12, 67, 34, 89, 11};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int min, max;
    
    getMinMax(numbers, size, &min, &max);
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\nMin: %d, Max: %d\n", min, max);
    
    return 0;
}
