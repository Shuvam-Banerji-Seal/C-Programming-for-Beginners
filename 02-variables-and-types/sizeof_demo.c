/*
 * sizeof_demo.c
 * Demonstrates the sizeof operator
 */

#include <stdio.h>

int main() {
    printf("=== sizeof Operator Demo ===\n\n");
    
    printf("--- Basic Data Types ---\n");
    printf("sizeof(char)           = %lu byte(s)\n", sizeof(char));
    printf("sizeof(short)          = %lu byte(s)\n", sizeof(short));
    printf("sizeof(int)            = %lu byte(s)\n", sizeof(int));
    printf("sizeof(long)           = %lu byte(s)\n", sizeof(long));
    printf("sizeof(long long)      = %lu byte(s)\n", sizeof(long long));
    printf("sizeof(float)          = %lu byte(s)\n", sizeof(float));
    printf("sizeof(double)         = %lu byte(s)\n", sizeof(double));
    printf("sizeof(long double)    = %lu byte(s)\n\n", sizeof(long double));
    
    printf("--- Unsigned Types ---\n");
    printf("sizeof(unsigned char)  = %lu byte(s)\n", sizeof(unsigned char));
    printf("sizeof(unsigned int)   = %lu byte(s)\n", sizeof(unsigned int));
    printf("sizeof(unsigned long)  = %lu byte(s)\n\n", sizeof(unsigned long));
    
    printf("--- Variables ---\n");
    int x = 42;
    float y = 3.14;
    double z = 2.71828;
    char ch = 'A';
    
    printf("sizeof(x) where x is int    = %lu byte(s)\n", sizeof(x));
    printf("sizeof(y) where y is float  = %lu byte(s)\n", sizeof(y));
    printf("sizeof(z) where z is double = %lu byte(s)\n", sizeof(z));
    printf("sizeof(ch) where ch is char = %lu byte(s)\n\n", sizeof(ch));
    
    printf("--- Arrays ---\n");
    int arr[10];
    char str[50];
    printf("sizeof(arr) where arr is int[10]   = %lu bytes\n", sizeof(arr));
    printf("sizeof(str) where str is char[50]  = %lu bytes\n", sizeof(str));
    printf("Number of elements in arr          = %lu\n\n", sizeof(arr) / sizeof(arr[0]));
    
    printf("--- Pointers ---\n");
    int *ptr;
    char *cptr;
    double *dptr;
    printf("sizeof(int*)    = %lu byte(s)\n", sizeof(ptr));
    printf("sizeof(char*)   = %lu byte(s)\n", sizeof(cptr));
    printf("sizeof(double*) = %lu byte(s)\n", sizeof(dptr));
    printf("(All pointers have the same size on a given architecture)\n");
    
    return 0;
}
