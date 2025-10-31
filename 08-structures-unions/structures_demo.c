/*
 * structures_demo.c
 * Demonstrates structures in C
 * Topics: struct definition, initialization, nested structures, arrays of structures
 */

#include <stdio.h>
#include <string.h>

// Basic structure
struct Point {
    int x;
    int y;
};

// Structure with different types
struct Student {
    char name[50];
    int id;
    float gpa;
};

// Nested structure
struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    int id;
    struct Date hire_date;
};

// Using typedef
typedef struct {
    float real;
    float imag;
} Complex;

int main() {
    printf("=== Structures Demo ===\n\n");
    
    // Basic structure usage
    printf("1. Basic Structure:\n");
    struct Point p1 = {10, 20};
    printf("   Point: (%d, %d)\n\n", p1.x, p1.y);
    
    // Student structure
    printf("2. Student Structure:\n");
    struct Student s1;
    strcpy(s1.name, "Alice");
    s1.id = 101;
    s1.gpa = 3.8f;
    printf("   Name: %s, ID: %d, GPA: %.2f\n\n", s1.name, s1.id, s1.gpa);
    
    // Nested structure
    printf("3. Nested Structure:\n");
    struct Employee emp = {"Bob", 201, {15, 6, 2020}};
    printf("   Employee: %s (ID: %d)\n", emp.name, emp.id);
    printf("   Hire Date: %d/%d/%d\n\n", emp.hire_date.day, 
           emp.hire_date.month, emp.hire_date.year);
    
    // Array of structures
    printf("4. Array of Structures:\n");
    struct Point points[3] = {{1,2}, {3,4}, {5,6}};
    for (int i = 0; i < 3; i++) {
        printf("   Point %d: (%d, %d)\n", i, points[i].x, points[i].y);
    }
    printf("\n");
    
    // Typedef usage
    printf("5. Typedef Structure:\n");
    Complex c1 = {3.0f, 4.0f};
    printf("   Complex: %.1f + %.1fi\n", c1.real, c1.imag);
    
    return 0;
}
