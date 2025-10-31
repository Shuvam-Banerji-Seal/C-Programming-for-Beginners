/*
 * unions_demo.c
 * Demonstrates unions in C
 * Topics: union definition, memory sharing, use cases
 */

#include <stdio.h>
#include <string.h>

// Basic union
union Data {
    int i;
    float f;
    char str[20];
};

// Union for type punning
typedef union {
    float f;
    unsigned int bits;
} FloatBits;

int main() {
    printf("=== Unions Demo ===\n\n");
    
    // Basic union usage
    printf("1. Basic Union:\n");
    union Data data;
    
    data.i = 10;
    printf("   data.i = %d\n", data.i);
    
    data.f = 220.5f;
    printf("   data.f = %.1f\n", data.f);
    printf("   data.i = %d (corrupted!)\n\n", data.i);
    
    // Size comparison
    printf("2. Memory Usage:\n");
    printf("   Size of union Data: %zu bytes\n", sizeof(union Data));
    printf("   (Only enough for largest member)\n\n");
    
    // Type punning
    printf("3. Float Bit Representation:\n");
    FloatBits fb;
    fb.f = 3.14f;
    printf("   Float: %.2f\n", fb.f);
    printf("   Bits: 0x%08X\n", fb.bits);
    
    return 0;
}
