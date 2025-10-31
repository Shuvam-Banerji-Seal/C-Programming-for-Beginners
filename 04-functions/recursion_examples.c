#include <stdio.h>

// Factorial
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Fibonacci
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Sum of digits
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

// Power function
int power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

// GCD using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Print number in binary
void printBinary(int n) {
    if (n > 1) {
        printBinary(n / 2);
    }
    printf("%d", n % 2);
}

// Tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

// Check if string is palindrome
int isPalindrome(char str[], int start, int end) {
    if (start >= end) return 1;
    if (str[start] != str[end]) return 0;
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    printf("=== Recursion Examples ===\n\n");
    
    // Factorial
    printf("Factorial:\n");
    for (int i = 1; i <= 6; i++) {
        printf("factorial(%d) = %d\n", i, factorial(i));
    }
    printf("\n");
    
    // Fibonacci
    printf("Fibonacci Sequence:\n");
    printf("First 10 numbers: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n\n");
    
    // Sum of digits
    printf("Sum of Digits:\n");
    int num = 12345;
    printf("Sum of digits in %d = %d\n\n", num, sumOfDigits(num));
    
    // Power
    printf("Power Function:\n");
    printf("2^5 = %d\n", power(2, 5));
    printf("3^4 = %d\n\n", power(3, 4));
    
    // GCD
    printf("GCD (Greatest Common Divisor):\n");
    printf("GCD(48, 18) = %d\n", gcd(48, 18));
    printf("GCD(100, 50) = %d\n\n", gcd(100, 50));
    
    // Binary representation
    printf("Binary Representation:\n");
    printf("13 in binary: ");
    printBinary(13);
    printf("\n");
    printf("25 in binary: ");
    printBinary(25);
    printf("\n\n");
    
    // Tower of Hanoi
    printf("Tower of Hanoi (3 disks):\n");
    towerOfHanoi(3, 'A', 'C', 'B');
    printf("\n");
    
    // Palindrome check
    printf("Palindrome Check:\n");
    char str1[] = "racecar";
    char str2[] = "hello";
    printf("'%s' is %s\n", str1, 
           isPalindrome(str1, 0, 6) ? "a palindrome" : "not a palindrome");
    printf("'%s' is %s\n", str2, 
           isPalindrome(str2, 0, 4) ? "a palindrome" : "not a palindrome");
    
    return 0;
}
