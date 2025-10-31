/*
 * file_processing.c
 * File processing and text manipulation
 * Topics: Line-by-line processing, word counting, search and replace
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Count words in a file
typedef struct {
    int lines;
    int words;
    int characters;
} FileStats;

FileStats analyzeFile(const char *filename) {
    FileStats stats = {0, 0, 0};
    FILE *fp = fopen(filename, "r");
    
    if (fp == NULL) {
        perror("Error opening file");
        return stats;
    }
    
    char ch;
    int in_word = 0;
    
    while ((ch = fgetc(fp)) != EOF) {
        stats.characters++;
        
        if (ch == '\n') {
            stats.lines++;
        }
        
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            stats.words++;
        }
    }
    
    fclose(fp);
    return stats;
}

// Search for a word in file
int searchInFile(const char *filename, const char *word) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 0;
    }
    
    char line[256];
    int line_num = 0;
    int count = 0;
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        line_num++;
        char *pos = line;
        while ((pos = strstr(pos, word)) != NULL) {
            count++;
            printf("     Line %d: ...%.*s...\n", 
                   line_num, 
                   (int)strlen(word) + 20, 
                   pos);
            pos += strlen(word);
        }
    }
    
    fclose(fp);
    return count;
}

// Replace word in file
void replaceInFile(const char *filename, const char *old_word, const char *new_word) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Error creating temp file");
        fclose(fp);
        return;
    }
    
    char line[256];
    int replacements = 0;
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *pos;
        char buffer[512] = "";
        char *current = line;
        
        while ((pos = strstr(current, old_word)) != NULL) {
            // Copy text before match
            strncat(buffer, current, pos - current);
            // Add replacement
            strcat(buffer, new_word);
            // Move past the old word
            current = pos + strlen(old_word);
            replacements++;
        }
        // Copy remaining text
        strcat(buffer, current);
        
        fputs(buffer, temp);
    }
    
    fclose(fp);
    fclose(temp);
    
    // Replace original file
    remove(filename);
    rename("temp.txt", filename);
    
    printf("   Made %d replacements\n", replacements);
}

// Reverse file content
void reverseFile(const char *filename, const char *output) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    
    // Read all lines
    char **lines = NULL;
    int count = 0;
    char buffer[256];
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        lines = realloc(lines, (count + 1) * sizeof(char*));
        lines[count] = malloc(strlen(buffer) + 1);
        strcpy(lines[count], buffer);
        count++;
    }
    fclose(fp);
    
    // Write in reverse order
    FILE *out = fopen(output, "w");
    if (out == NULL) {
        perror("Error creating output file");
        for (int i = 0; i < count; i++) {
            free(lines[i]);
        }
        free(lines);
        return;
    }
    
    for (int i = count - 1; i >= 0; i--) {
        fputs(lines[i], out);
        free(lines[i]);
    }
    
    fclose(out);
    free(lines);
    printf("   Reversed %d lines to %s\n", count, output);
}

// Merge two files
void mergeFiles(const char *file1, const char *file2, const char *output) {
    FILE *out = fopen(output, "w");
    if (out == NULL) {
        perror("Error creating output file");
        return;
    }
    
    // Copy first file
    FILE *fp1 = fopen(file1, "r");
    if (fp1 != NULL) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp1) != NULL) {
            fputs(buffer, out);
        }
        fclose(fp1);
    }
    
    // Copy second file
    FILE *fp2 = fopen(file2, "r");
    if (fp2 != NULL) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp2) != NULL) {
            fputs(buffer, out);
        }
        fclose(fp2);
    }
    
    fclose(out);
    printf("   Merged %s and %s into %s\n", file1, file2, output);
}

int main() {
    printf("=== File Processing ===\n\n");
    
    // Create test file
    printf("1. Creating Test File:\n");
    FILE *fp = fopen("test.txt", "w");
    fprintf(fp, "Hello World\n");
    fprintf(fp, "This is a test file\n");
    fprintf(fp, "C programming is fun\n");
    fprintf(fp, "File I/O operations\n");
    fprintf(fp, "Hello again\n");
    fclose(fp);
    printf("   Created test.txt\n\n");
    
    // Analyze file
    printf("2. File Statistics:\n");
    FileStats stats = analyzeFile("test.txt");
    printf("   Lines: %d\n", stats.lines);
    printf("   Words: %d\n", stats.words);
    printf("   Characters: %d\n\n", stats.characters);
    
    // Search in file
    printf("3. Search for 'Hello':\n");
    int occurrences = searchInFile("test.txt", "Hello");
    printf("   Found %d occurrences\n\n", occurrences);
    
    // Replace in file
    printf("4. Replace 'Hello' with 'Hi':\n");
    replaceInFile("test.txt", "Hello", "Hi");
    printf("\n");
    
    // Create second test file
    FILE *fp2 = fopen("test2.txt", "w");
    fprintf(fp2, "Additional content\n");
    fprintf(fp2, "More text here\n");
    fclose(fp2);
    
    // Merge files
    printf("5. Merge Files:\n");
    mergeFiles("test.txt", "test2.txt", "merged.txt");
    printf("\n");
    
    // Reverse file
    printf("6. Reverse File:\n");
    reverseFile("test.txt", "reversed.txt");
    
    // Display results
    printf("\n7. Display Merged File:\n");
    fp = fopen("merged.txt", "r");
    if (fp != NULL) {
        char line[256];
        printf("   Content:\n");
        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("     %s", line);
        }
        fclose(fp);
    }
    
    // Cleanup
    printf("\n\n8. Cleanup:\n");
    remove("test.txt");
    remove("test2.txt");
    remove("merged.txt");
    remove("reversed.txt");
    printf("   Temporary files removed\n");
    
    return 0;
}
