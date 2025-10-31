/*
 * multidimensional_arrays.c
 * Advanced multi-dimensional array operations
 * Topics: 2D arrays, 3D arrays, matrix operations, dynamic allocation
 */

#include <stdio.h>
#include <stdlib.h>

// Matrix addition
void matrixAdd(int rows, int cols, int a[rows][cols], int b[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Matrix multiplication
void matrixMultiply(int r1, int c1, int a[r1][c1], int r2, int c2, int b[r2][c2], int result[r1][c2]) {
    if (c1 != r2) {
        printf("Cannot multiply: dimensions incompatible\n");
        return;
    }
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Matrix transpose
void matrixTranspose(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Print matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("   ");
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Spiral order traversal of matrix
void spiralTraversal(int rows, int cols, int matrix[rows][cols]) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    printf("   Spiral order: ");
    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;
        
        // Print right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;
        
        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }
        
        // Print left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
    printf("\n");
}

// Search in sorted 2D matrix
int searchMatrix(int rows, int cols, int matrix[rows][cols], int target) {
    int row = 0, col = cols - 1;
    
    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            printf("   Found %d at position (%d, %d)\n", target, row, col);
            return 1;
        } else if (matrix[row][col] > target) {
            col--;
        } else {
            row++;
        }
    }
    printf("   %d not found in matrix\n", target);
    return 0;
}

// 3D array demonstration
void demonstrate3DArray() {
    printf("4. 3D Array (3x3x3 cube):\n");
    
    int cube[3][3][3];
    int value = 1;
    
    // Initialize 3D array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cube[i][j][k] = value++;
            }
        }
    }
    
    // Print each layer
    for (int i = 0; i < 3; i++) {
        printf("   Layer %d:\n", i);
        for (int j = 0; j < 3; j++) {
            printf("   ");
            for (int k = 0; k < 3; k++) {
                printf("%3d ", cube[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    printf("=== Multi-Dimensional Arrays ===\n\n");
    
    // Matrix addition
    printf("1. Matrix Addition:\n");
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int sum[2][3];
    
    printf("   Matrix A:\n");
    printMatrix(2, 3, a);
    printf("   Matrix B:\n");
    printMatrix(2, 3, b);
    
    matrixAdd(2, 3, a, b, sum);
    printf("   Sum:\n");
    printMatrix(2, 3, sum);
    printf("\n");
    
    // Matrix multiplication
    printf("2. Matrix Multiplication:\n");
    int m1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int m2[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int product[2][2];
    
    printf("   Matrix M1 (2x3):\n");
    printMatrix(2, 3, m1);
    printf("   Matrix M2 (3x2):\n");
    printMatrix(3, 2, m2);
    
    matrixMultiply(2, 3, m1, 3, 2, m2, product);
    printf("   Product (2x2):\n");
    printMatrix(2, 2, product);
    printf("\n");
    
    // Matrix transpose
    printf("3. Matrix Transpose:\n");
    int original[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int transposed[2][3];
    
    printf("   Original (3x2):\n");
    printMatrix(3, 2, original);
    
    matrixTranspose(3, 2, original, transposed);
    printf("   Transposed (2x3):\n");
    printMatrix(2, 3, transposed);
    printf("\n");
    
    // 3D arrays
    demonstrate3DArray();
    
    // Spiral traversal
    printf("5. Spiral Traversal:\n");
    int spiral[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    printf("   Matrix:\n");
    printMatrix(3, 4, spiral);
    spiralTraversal(3, 4, spiral);
    printf("\n");
    
    // Search in sorted matrix
    printf("6. Search in Sorted Matrix:\n");
    int sorted[4][4] = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    printf("   Matrix:\n");
    printMatrix(4, 4, sorted);
    searchMatrix(4, 4, sorted, 8);
    searchMatrix(4, 4, sorted, 15);
    
    return 0;
}
