# Module 05: Arrays and Strings 📚

Master arrays and string manipulation - the foundation of data handling in C!

## 📚 What You'll Learn

1. One-dimensional and multi-dimensional arrays
2. Character arrays and strings
3. String manipulation without string.h
4. Common string operations
5. Array algorithms

## 📊 Arrays

### One-Dimensional Arrays

```c
#include <stdio.h>

int main() {
    // Array declaration and initialization
    int numbers[5] = {10, 20, 30, 40, 50};
    
    // Accessing elements
    printf("First element: %d\n", numbers[0]);
    printf("Third element: %d\n", numbers[2]);
    
    // Iterating through array
    printf("All elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Array size
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("Array size: %d\n", size);
    
    return 0;
}
```

### Multi-Dimensional Arrays

```c
#include <stdio.h>

int main() {
    // 2D array (matrix)
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Accessing elements
    printf("Element at [1][2]: %d\n", matrix[1][2]);
    
    // Printing matrix
    printf("Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## 🔤 Strings

### Character Arrays

```c
#include <stdio.h>

int main() {
    // String as character array
    char name[] = "John";
    char greeting[20] = "Hello";
    
    // String with explicit null terminator
    char word[] = {'H', 'i', '\0'};
    
    printf("Name: %s\n", name);
    printf("Greeting: %s\n", greeting);
    printf("Word: %s\n", word);
    
    // Character by character
    for (int i = 0; name[i] != '\0'; i++) {
        printf("%c ", name[i]);
    }
    printf("\n");
    
    return 0;
}
```

### String Length

```c
int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
```

### String Copy

```c
void stringCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
```

### String Concatenate

```c
void stringConcat(char dest[], char src[]) {
    int i = 0, j = 0;
    
    // Find end of dest
    while (dest[i] != '\0') {
        i++;
    }
    
    // Append src to dest
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}
```

### String Compare

```c
int stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}
```

## 🔧 Array Algorithms

### Linear Search

```c
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  // Not found
}
```

### Binary Search

```c
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
```

### Bubble Sort

```c
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
```

## 📖 Code Examples

1. [arrays_basics.c](./arrays_basics.c) - Array fundamentals
2. [2d_arrays.c](./2d_arrays.c) - Multi-dimensional arrays
3. [string_operations.c](./string_operations.c) - String manipulation
4. [array_algorithms.c](./array_algorithms.c) - Search and sort
5. [string_exercises.c](./string_exercises.c) - Advanced string problems

## ✏️ Exercises

1. Write a function to reverse an array
2. Find the second largest element in an array
3. Implement string reverse function
4. Check if a string is a palindrome
5. Remove duplicates from an array
6. Implement selection sort
7. Merge two sorted arrays
8. Count vowels and consonants in a string

## 🎯 Key Takeaways

- Arrays are zero-indexed in C
- Array size must be known at compile time (or use dynamic allocation)
- Strings are null-terminated character arrays
- Always check array bounds to avoid buffer overflow
- Pass array size to functions as arrays decay to pointers
- Multi-dimensional arrays are stored in row-major order

## 🔜 Next Module

Ready to master pointers? Head to [Module 06: Pointers](../06-pointers/README.md)

---

**Remember**: Strings in C are just character arrays with a null terminator!
