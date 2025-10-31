#include <stdio.h>
#include <string.h>

// Custom string length
int myStrLen(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Custom string copy
void myStrCpy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Custom string concatenate
void myStrCat(char dest[], char src[]) {
    int i = 0, j = 0;
    while (dest[i] != '\0') i++;
    while (src[j] != '\0') {
        dest[i++] = src[j++];
    }
    dest[i] = '\0';
}

// Custom string compare
int myStrCmp(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Reverse string
void reverseString(char str[]) {
    int length = myStrLen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

// Check palindrome
int isPalindrome(char str[]) {
    int length = myStrLen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("=== Custom String Operations ===\n\n");
    
    char str1[100] = "Hello";
    char str2[100] = "World";
    char str3[100];
    
    // Length
    printf("Length of '%s': %d\n", str1, myStrLen(str1));
    
    // Copy
    myStrCpy(str3, str1);
    printf("Copied string: %s\n", str3);
    
    // Concatenate
    myStrCat(str3, " ");
    myStrCat(str3, str2);
    printf("Concatenated: %s\n", str3);
    
    // Compare
    printf("Compare '%s' and '%s': %d\n", str1, str2, myStrCmp(str1, str2));
    
    // Reverse
    char str4[] = "Palindrome";
    printf("Original: %s\n", str4);
    reverseString(str4);
    printf("Reversed: %s\n", str4);
    
    // Palindrome check
    char str5[] = "racecar";
    char str6[] = "hello";
    printf("'%s' is %s\n", str5, isPalindrome(str5) ? "a palindrome" : "not a palindrome");
    printf("'%s' is %s\n", str6, isPalindrome(str6) ? "a palindrome" : "not a palindrome");
    
    return 0;
}
