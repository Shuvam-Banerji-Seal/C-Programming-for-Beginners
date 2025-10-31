/*
 * advanced_file_io.c
 * Advanced file I/O operations
 * Topics: CSV parsing, structured data I/O, file positioning, error handling
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student records
typedef struct {
    int id;
    char name[50];
    float gpa;
    int age;
} Student;

// Write students to CSV file
void writeCSV(const char *filename, Student students[], int count) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }
    
    // Write header
    fprintf(fp, "ID,Name,GPA,Age\n");
    
    // Write data
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%.2f,%d\n", 
                students[i].id, students[i].name, 
                students[i].gpa, students[i].age);
    }
    
    fclose(fp);
    printf("   Wrote %d records to %s\n", count, filename);
}

// Read students from CSV file
int readCSV(const char *filename, Student students[], int max_count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 0;
    }
    
    char line[200];
    int count = 0;
    
    // Skip header
    fgets(line, sizeof(line), fp);
    
    // Read data
    while (fgets(line, sizeof(line), fp) != NULL && count < max_count) {
        sscanf(line, "%d,%[^,],%f,%d", 
               &students[count].id, 
               students[count].name,
               &students[count].gpa,
               &students[count].age);
        count++;
    }
    
    fclose(fp);
    return count;
}

// Write binary records
void writeBinaryRecords(const char *filename, Student students[], int count) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening binary file for writing");
        return;
    }
    
    // Write count first
    fwrite(&count, sizeof(int), 1, fp);
    
    // Write all records
    fwrite(students, sizeof(Student), count, fp);
    
    fclose(fp);
    printf("   Wrote %d binary records to %s\n", count, filename);
}

// Read binary records
int readBinaryRecords(const char *filename, Student students[], int max_count) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening binary file for reading");
        return 0;
    }
    
    int count;
    // Read count
    fread(&count, sizeof(int), 1, fp);
    
    if (count > max_count) {
        count = max_count;
    }
    
    // Read records
    fread(students, sizeof(Student), count, fp);
    
    fclose(fp);
    return count;
}

// File positioning demonstration
void demonstrateFilePositioning(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    
    printf("\n4. File Positioning:\n");
    
    // Get file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    printf("   File size: %ld bytes\n", size);
    
    // Read record at specific position
    int record_num = 2;  // Third record (0-indexed)
    long offset = sizeof(int) + (record_num * sizeof(Student));
    
    fseek(fp, offset, SEEK_SET);
    Student s;
    fread(&s, sizeof(Student), 1, fp);
    
    printf("   Record at position %d:\n", record_num);
    printf("     ID: %d, Name: %s, GPA: %.2f, Age: %d\n",
           s.id, s.name, s.gpa, s.age);
    
    // Read from current position
    printf("   Current position: %ld\n", ftell(fp));
    
    // Read next record
    fread(&s, sizeof(Student), 1, fp);
    printf("   Next record:\n");
    printf("     ID: %d, Name: %s, GPA: %.2f, Age: %d\n",
           s.id, s.name, s.gpa, s.age);
    
    fclose(fp);
}

// Append to file
void appendToCSV(const char *filename, Student *student) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file for appending");
        return;
    }
    
    fprintf(fp, "%d,%s,%.2f,%d\n", 
            student->id, student->name, 
            student->gpa, student->age);
    
    fclose(fp);
    printf("   Appended record to %s\n", filename);
}

// Count lines in file
int countLines(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    
    int count = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    
    fclose(fp);
    return count;
}

// Copy file
void copyFile(const char *source, const char *dest) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return;
    }
    
    FILE *dst = fopen(dest, "wb");
    if (dst == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }
    
    char buffer[1024];
    size_t bytes;
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }
    
    fclose(src);
    fclose(dst);
    printf("   Copied %s to %s\n", source, dest);
}

int main() {
    printf("=== Advanced File I/O ===\n\n");
    
    // Sample data
    Student students[] = {
        {1, "Alice Smith", 3.8f, 20},
        {2, "Bob Johnson", 3.6f, 21},
        {3, "Carol White", 3.9f, 19},
        {4, "Dave Brown", 3.7f, 22},
        {5, "Eve Davis", 3.5f, 20}
    };
    int count = 5;
    
    // 1. Write and read CSV
    printf("1. CSV File Operations:\n");
    writeCSV("students.csv", students, count);
    
    Student read_students[10];
    int read_count = readCSV("students.csv", read_students, 10);
    printf("   Read %d records from CSV:\n", read_count);
    for (int i = 0; i < read_count && i < 3; i++) {
        printf("     %d: %s (GPA: %.2f)\n", 
               read_students[i].id, read_students[i].name, read_students[i].gpa);
    }
    printf("\n");
    
    // 2. Binary file operations
    printf("2. Binary File Operations:\n");
    writeBinaryRecords("students.dat", students, count);
    
    Student binary_students[10];
    int binary_count = readBinaryRecords("students.dat", binary_students, 10);
    printf("   Read %d binary records:\n", binary_count);
    for (int i = 0; i < binary_count && i < 3; i++) {
        printf("     %d: %s (GPA: %.2f)\n", 
               binary_students[i].id, binary_students[i].name, binary_students[i].gpa);
    }
    printf("\n");
    
    // 3. File positioning
    demonstrateFilePositioning("students.dat");
    printf("\n");
    
    // 4. Append to file
    printf("5. Append to CSV:\n");
    Student new_student = {6, "Frank Miller", 3.4f, 23};
    appendToCSV("students.csv", &new_student);
    
    int lines = countLines("students.csv");
    printf("   Total lines in CSV: %d\n\n", lines);
    
    // 5. File copy
    printf("6. File Copy:\n");
    copyFile("students.csv", "students_backup.csv");
    printf("\n");
    
    // 6. Error handling demonstration
    printf("7. Error Handling:\n");
    FILE *fp = fopen("nonexistent.txt", "r");
    if (fp == NULL) {
        printf("   Successfully caught error: ");
        perror("fopen");
    } else {
        fclose(fp);
    }
    printf("\n");
    
    // Cleanup
    printf("8. Cleanup:\n");
    remove("students.csv");
    remove("students.dat");
    remove("students_backup.csv");
    printf("   Temporary files removed\n");
    
    return 0;
}
