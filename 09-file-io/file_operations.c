/*
 * file_operations.c
 * Demonstrates file I/O operations in C
 * Topics: fopen, fclose, fprintf, fscanf, fread, fwrite
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("=== File I/O Demo ===\n\n");
    
    // Writing to text file
    printf("1. Writing to text file:\n");
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("   Error opening file!\n");
        return 1;
    }
    
    fprintf(fp, "Hello, File I/O!\n");
    fprintf(fp, "Line 2: %d\n", 42);
    fclose(fp);
    printf("   Wrote to test.txt\n\n");
    
    // Reading from text file
    printf("2. Reading from text file:\n");
    fp = fopen("test.txt", "r");
    if (fp != NULL) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("   %s", buffer);
        }
        fclose(fp);
    }
    printf("\n");
    
    // Binary file operations
    printf("3. Binary file operations:\n");
    int numbers[] = {1, 2, 3, 4, 5};
    fp = fopen("data.bin", "wb");
    if (fp != NULL) {
        fwrite(numbers, sizeof(int), 5, fp);
        fclose(fp);
        printf("   Wrote 5 integers to binary file\n");
    }
    
    int read_numbers[5];
    fp = fopen("data.bin", "rb");
    if (fp != NULL) {
        fread(read_numbers, sizeof(int), 5, fp);
        fclose(fp);
        printf("   Read back: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", read_numbers[i]);
        }
        printf("\n");
    }
    
    // Cleanup
    remove("test.txt");
    remove("data.bin");
    printf("\n   Cleaned up test files\n");
    
    return 0;
}
