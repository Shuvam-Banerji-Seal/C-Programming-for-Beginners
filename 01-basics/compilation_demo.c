/*
 * compilation_demo.c
 * A program to demonstrate the compilation process
 * 
 * Compile this with:
 *   gcc -E compilation_demo.c -o compilation_demo.i  (preprocessing)
 *   gcc -S compilation_demo.c -o compilation_demo.s  (compilation to assembly)
 *   gcc -c compilation_demo.c -o compilation_demo.o  (assembly to object)
 *   gcc compilation_demo.o -o compilation_demo       (linking)
 * 
 * Or simply:
 *   gcc compilation_demo.c -o compilation_demo
 */

#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))

int main() {
    int radius = 5;
    float area;
    
    printf("Demonstrating the compilation process\n");
    printf("======================================\n\n");
    
    area = PI * SQUARE(radius);
    
    printf("Circle with radius %d:\n", radius);
    printf("Area = %.2f square units\n", area);
    
    return 0;
}
