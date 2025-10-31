#include <stdio.h>

void main() {
    int a = 10; // Integer variable
    float b = 5.5; // Floating-point variable
    char c = 'A'; // Character variable
    long d = 1234567890; // Long integer variable
    double e = 3.141592653589793; // Double precision floating-point variable
    long long f = 1234567890123456789; // Long long integer variable
    long double g = 2.718281828459045; // Long double precision floating-point variable
    long long int h = 987654321012345678; // Long long integer variable
    unsigned int i = 4294967295; // Unsigned integer variable
    short j = 32767; // Short integer variable
    unsigned short k = 65535; // Unsigned short integer variable
    unsigned long l = 4294967295; // Unsigned long integer variable
    unsigned long long m = 18446744073709551615U; // Unsigned
    unsigned char n = 255; // Unsigned character variable
    signed char o = -128; // Signed character variable
    signed int p = -2147483648; // Signed integer variable
    signed long q = -9223372036854775807L; // Signed long integer variable
    signed long long r = -9223372036854775807LL; // Signed long
    signed short s = -32768; // Signed short integer variable
    signed short int t = -32768; // Signed short integer variable
    signed long int u = -9223372036854775807L; // Signed long integer variable
    signed long long int v = -9223372036854775807LL; // Signed long long integer variable

    // 64-bit system: int (4 bytes), float (4 bytes), char (1 byte)
    printf("Integer: %d\n Size of the integer: %zu bytes\n", a, sizeof(a));
    printf("Float: %.2f\n Size of the float: %zu bytes\n", b, sizeof(b));
    printf("Character: %c\n Size of the character: %zu bytes\n", c, sizeof(c));
    printf("Long: %ld\n Size of the long: %zu bytes\n", d, sizeof(d));
    printf("Double: %.15f\n Size of the double: %zu bytes\n", e, sizeof(e));
    printf("Long Long: %lld\n Size of the long long: %zu bytes\n", f, sizeof(f));
    printf("Long Double: %.15Lf\n Size of the long double: %zu bytes\n", g, sizeof(g));
    printf("Long Long Int: %lld\n Size of the long long int: %zu bytes\n", h, sizeof(h));
    printf("Unsigned Int: %u\n Size of the unsigned int: %zu bytes\n", i, sizeof(i));
    printf("Short: %d\n Size of the short: %zu bytes\n", j, sizeof(j));
    printf("Unsigned Short: %u\n Size of the unsigned short: %zu bytes\n", k, sizeof(k));
    printf("Unsigned Long: %lu\n Size of the unsigned long: %zu bytes\n", l, sizeof(l));
    printf("Unsigned Long Long: %llu\n Size of the unsigned long long: %zu bytes\n", m, sizeof(m));
    printf("Unsigned Char: %u\n Size of the unsigned char: %zu bytes\n", n, sizeof(n));
    printf("Signed Char: %d\n Size of the signed char: %zu bytes\n", o, sizeof(o));
    printf("Signed Int: %d\n Size of the signed int: %zu bytes\n", p, sizeof(p));
    printf("Signed Long: %ld\n Size of the signed long: %zu bytes\n", q, sizeof(q));
    printf("Signed Long Long: %lld\n Size of the signed long long: %zu bytes\n", r, sizeof(r));
    printf("Signed Short: %d\n Size of the signed short: %zu bytes\n", s, sizeof(s));
    printf("Signed Short Int: %d\n Size of the signed short int: %zu bytes\n", t, sizeof(t));
    printf("Signed Long Int: %ld\n Size of the signed long int: %zu bytes\n", u, sizeof(u));
    printf("Signed Long Long Int: %lld\n Size of the signed long long int: %zu bytes\n", v, sizeof(v));
    
}