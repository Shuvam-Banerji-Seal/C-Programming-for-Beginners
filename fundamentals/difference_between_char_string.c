#include <stdio.h>

int main() {
    char ch = 'A'; // Character variable // ASCII Value 65
    char str[] = "Hello, World!"; // String (array of characters)

    // Print the character and its size
    printf("Character: %c\n", ch);
    printf("Size of character: %zu bytes\n", sizeof(ch));

    // Print the string and its size
    printf("String: %s\n", str);
    printf("Size of string (including null terminator): %zu bytes\n", sizeof(str));
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        printf("Character at index %d: %c, ASCII Value: %d\n", i, str[i], str[i]); // implicit type casting
        count++;
    }
    printf("Total characters in string (excluding null terminator): %d\n", count);

    //explicit type casting
    int asciiValue = (int)ch; // Convert char to int to get ASCII value
    printf("ASCII Value of character '%c': %d\n", ch, asciiValue);

    

    return 0;
}