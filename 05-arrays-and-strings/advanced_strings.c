/*
 * advanced_strings.c
 * Advanced string algorithms and manipulation
 * Topics: Pattern matching, string tokenization, anagrams, palindromes
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Check if string is palindrome
bool isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;
        
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Check if two strings are anagrams
bool areAnagrams(const char *str1, const char *str2) {
    int count1[256] = {0};
    int count2[256] = {0};
    
    // Count characters in first string
    for (int i = 0; str1[i]; i++) {
        count1[(unsigned char)str1[i]]++;
    }
    
    // Count characters in second string
    for (int i = 0; str2[i]; i++) {
        count2[(unsigned char)str2[i]]++;
    }
    
    // Compare counts
    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

// Reverse words in a string
void reverseWords(char *str) {
    int n = strlen(str);
    
    // Reverse the entire string
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
    
    // Reverse each word
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            int end = i - 1;
            while (start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
}

// Naive pattern matching
int patternMatch(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i;  // Pattern found at index i
        }
    }
    return -1;  // Pattern not found
}

// Count all occurrences of pattern in text
int countOccurrences(const char *text, const char *pattern) {
    int count = 0;
    int n = strlen(text);
    int m = strlen(pattern);
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            count++;
        }
    }
    return count;
}

// Remove duplicates from string
void removeDuplicates(char *str) {
    int len = strlen(str);
    if (len < 2) return;
    
    int tail = 1;
    for (int i = 1; i < len; i++) {
        int j;
        for (j = 0; j < tail; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == tail) {
            str[tail] = str[i];
            tail++;
        }
    }
    str[tail] = '\0';
}

// Longest common prefix
void longestCommonPrefix(char *strings[], int count, char *result) {
    if (count == 0) {
        result[0] = '\0';
        return;
    }
    
    int index = 0;
    while (1) {
        char current = strings[0][index];
        if (current == '\0') break;
        
        for (int i = 1; i < count; i++) {
            if (strings[i][index] != current) {
                result[index] = '\0';
                return;
            }
        }
        result[index] = current;
        index++;
    }
    result[index] = '\0';
}

// Run-length encoding
void runLengthEncode(const char *str, char *encoded) {
    int len = strlen(str);
    int j = 0;
    
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        j += sprintf(encoded + j, "%c%d", str[i], count);
    }
}

// Tokenization demo
void demonstrateTokenization() {
    printf("8. String Tokenization:\n");
    char str[] = "Hello,World,How,Are,You";
    char *token;
    
    printf("   Original: %s\n", str);
    printf("   Tokens: ");
    
    token = strtok(str, ",");
    while (token != NULL) {
        printf("[%s] ", token);
        token = strtok(NULL, ",");
    }
    printf("\n\n");
}

int main() {
    printf("=== Advanced String Operations ===\n\n");
    
    // Palindrome check
    printf("1. Palindrome Check:\n");
    char *test1 = "A man a plan a canal Panama";
    char *test2 = "Hello World";
    printf("   \"%s\" is %s\n", test1, isPalindrome(test1) ? "a palindrome" : "not a palindrome");
    printf("   \"%s\" is %s\n\n", test2, isPalindrome(test2) ? "a palindrome" : "not a palindrome");
    
    // Anagram check
    printf("2. Anagram Check:\n");
    char *str1 = "listen";
    char *str2 = "silent";
    char *str3 = "hello";
    printf("   \"%s\" and \"%s\" are %s\n", str1, str2, 
           areAnagrams(str1, str2) ? "anagrams" : "not anagrams");
    printf("   \"%s\" and \"%s\" are %s\n\n", str1, str3, 
           areAnagrams(str1, str3) ? "anagrams" : "not anagrams");
    
    // Reverse words
    printf("3. Reverse Words:\n");
    char sentence[] = "Hello World from C Programming";
    printf("   Original: %s\n", sentence);
    reverseWords(sentence);
    printf("   Reversed: %s\n\n", sentence);
    
    // Pattern matching
    printf("4. Pattern Matching:\n");
    char *text = "AABAACAADAABAABA";
    char *pattern = "AABA";
    int pos = patternMatch(text, pattern);
    printf("   Text: %s\n", text);
    printf("   Pattern: %s\n", pattern);
    printf("   First occurrence at index: %d\n", pos);
    printf("   Total occurrences: %d\n\n", countOccurrences(text, pattern));
    
    // Remove duplicates
    printf("5. Remove Duplicates:\n");
    char dup[] = "programming";
    printf("   Original: %s\n", dup);
    removeDuplicates(dup);
    printf("   After removing duplicates: %s\n\n", dup);
    
    // Longest common prefix
    printf("6. Longest Common Prefix:\n");
    char *strs[] = {"flower", "flow", "flight"};
    char prefix[100];
    longestCommonPrefix(strs, 3, prefix);
    printf("   Strings: ");
    for (int i = 0; i < 3; i++) {
        printf("\"%s\" ", strs[i]);
    }
    printf("\n   Longest common prefix: \"%s\"\n\n", prefix);
    
    // Run-length encoding
    printf("7. Run-Length Encoding:\n");
    char *original = "aaabbccccaa";
    char encoded[100];
    runLengthEncode(original, encoded);
    printf("   Original: %s\n", original);
    printf("   Encoded: %s\n\n", encoded);
    
    // Tokenization
    demonstrateTokenization();
    
    return 0;
}
