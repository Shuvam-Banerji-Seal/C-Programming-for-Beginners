#include <stdio.h>

// Linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary search (array must be sorted)
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Find maximum
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Reverse array
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    printf("=== Array Algorithms ===\n\n");
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, size);
    
    // Find maximum
    printf("Maximum: %d\n\n", findMax(arr, size));
    
    // Linear search
    int target = 25;
    int index = linearSearch(arr, size, target);
    printf("Linear search for %d: %s at index %d\n", 
           target, index != -1 ? "Found" : "Not found", index);
    
    // Bubble sort
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    printf("\nBefore bubble sort: ");
    printArray(arr2, size);
    bubbleSort(arr2, size);
    printf("After bubble sort: ");
    printArray(arr2, size);
    
    // Binary search (on sorted array)
    index = binarySearch(arr2, size, target);
    printf("Binary search for %d: %s at index %d\n", 
           target, index != -1 ? "Found" : "Not found", index);
    
    // Reverse array
    printf("\nBefore reverse: ");
    printArray(arr2, size);
    reverseArray(arr2, size);
    printf("After reverse: ");
    printArray(arr2, size);
    
    return 0;
}
