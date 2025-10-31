/*
 * advanced_structures.c
 * Advanced structure operations
 * Topics: Nested structures, bit fields, enums, pointers to structures, self-referential structures
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Enum for days of the week
typedef enum {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} DayOfWeek;

// Enum for status
typedef enum {
    PENDING,
    IN_PROGRESS,
    COMPLETED,
    CANCELLED
} Status;

// Bit fields for compact storage
typedef struct {
    unsigned int is_active : 1;    // 1 bit
    unsigned int priority : 3;     // 3 bits (0-7)
    unsigned int category : 4;     // 4 bits (0-15)
    unsigned int reserved : 24;    // Reserved bits
} Flags;

// Date structure
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Address structure
typedef struct {
    char street[100];
    char city[50];
    char state[30];
    int zip_code;
} Address;

// Person with nested structure
typedef struct {
    char name[50];
    int age;
    Address address;
    Date birth_date;
} Person;

// Complex nested structure - Employee
typedef struct {
    int employee_id;
    char name[50];
    char department[50];
    float salary;
    Date hire_date;
    Address office_address;
    Status status;
    Flags flags;
} Employee;

// Self-referential structure - Binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to print date
void printDate(Date d) {
    printf("%02d/%02d/%d", d.day, d.month, d.year);
}

// Function to print address
void printAddress(Address addr) {
    printf("%s, %s, %s %d", addr.street, addr.city, addr.state, addr.zip_code);
}

// Function to print day name
const char* getDayName(DayOfWeek day) {
    switch(day) {
        case MONDAY: return "Monday";
        case TUESDAY: return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY: return "Thursday";
        case FRIDAY: return "Friday";
        case SATURDAY: return "Saturday";
        case SUNDAY: return "Sunday";
        default: return "Unknown";
    }
}

// Function to print status
const char* getStatusName(Status s) {
    switch(s) {
        case PENDING: return "Pending";
        case IN_PROGRESS: return "In Progress";
        case COMPLETED: return "Completed";
        case CANCELLED: return "Cancelled";
        default: return "Unknown";
    }
}

// Function to demonstrate pointer to structure
void updateSalary(Employee *emp, float percentage) {
    emp->salary *= (1.0f + percentage / 100.0f);
}

// Create tree node
TreeNode* createNode(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into BST
TreeNode* insert(TreeNode *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Inorder traversal
void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    printf("=== Advanced Structures ===\n\n");
    
    // 1. Enum demonstration
    printf("1. Enumerations:\n");
    DayOfWeek today = FRIDAY;
    printf("   Today is %s (value: %d)\n", getDayName(today), today);
    printf("   Weekend starts on %s\n\n", getDayName(SATURDAY));
    
    // 2. Nested structures
    printf("2. Nested Structures:\n");
    Person person;
    strcpy(person.name, "John Doe");
    person.age = 30;
    strcpy(person.address.street, "123 Main St");
    strcpy(person.address.city, "Springfield");
    strcpy(person.address.state, "IL");
    person.address.zip_code = 62701;
    person.birth_date.day = 15;
    person.birth_date.month = 6;
    person.birth_date.year = 1994;
    
    printf("   Name: %s\n", person.name);
    printf("   Age: %d\n", person.age);
    printf("   Address: ");
    printAddress(person.address);
    printf("\n   Birth Date: ");
    printDate(person.birth_date);
    printf("\n\n");
    
    // 3. Complex structure with multiple nested structures
    printf("3. Complex Employee Structure:\n");
    Employee emp = {
        .employee_id = 1001,
        .name = "Alice Smith",
        .department = "Engineering",
        .salary = 75000.0f,
        .hire_date = {1, 3, 2020},
        .office_address = {"456 Tech Blvd", "San Francisco", "CA", 94102},
        .status = IN_PROGRESS,
        .flags = {.is_active = 1, .priority = 5, .category = 2}
    };
    
    printf("   Employee ID: %d\n", emp.employee_id);
    printf("   Name: %s\n", emp.name);
    printf("   Department: %s\n", emp.department);
    printf("   Salary: $%.2f\n", emp.salary);
    printf("   Hire Date: ");
    printDate(emp.hire_date);
    printf("\n   Office: ");
    printAddress(emp.office_address);
    printf("\n   Status: %s\n", getStatusName(emp.status));
    printf("   Active: %s\n", emp.flags.is_active ? "Yes" : "No");
    printf("   Priority: %d\n", emp.flags.priority);
    printf("\n");
    
    // 4. Pointer to structure
    printf("4. Pointer to Structure:\n");
    Employee *empPtr = &emp;
    printf("   Current salary: $%.2f\n", empPtr->salary);
    updateSalary(empPtr, 10.0f);  // 10% raise
    printf("   After 10%% raise: $%.2f\n\n", empPtr->salary);
    
    // 5. Array of structures
    printf("5. Array of Structures:\n");
    Employee team[3] = {
        {2001, "Bob Johnson", "Marketing", 65000.0f, {5, 8, 2021}, 
         {"789 Market St", "Boston", "MA", 2108}, COMPLETED, {1, 3, 1}},
        {2002, "Carol White", "Sales", 70000.0f, {12, 1, 2022}, 
         {"321 Sales Ave", "Chicago", "IL", 60601}, PENDING, {1, 7, 3}},
        {2003, "Dave Brown", "Engineering", 80000.0f, {20, 4, 2019}, 
         {"654 Dev Dr", "Austin", "TX", 73301}, IN_PROGRESS, {1, 6, 2}}
    };
    
    printf("   Team Members:\n");
    for (int i = 0; i < 3; i++) {
        printf("   %d. %s (%s) - $%.2f - %s\n",
               i+1, team[i].name, team[i].department, 
               team[i].salary, getStatusName(team[i].status));
    }
    printf("\n");
    
    // 6. Bit fields
    printf("6. Bit Fields (compact storage):\n");
    printf("   Size of Flags structure: %zu bytes\n", sizeof(Flags));
    printf("   Employee flags:\n");
    printf("     Active: %d\n", emp.flags.is_active);
    printf("     Priority: %d (0-7)\n", emp.flags.priority);
    printf("     Category: %d (0-15)\n\n", emp.flags.category);
    
    // 7. Self-referential structure (Binary Search Tree)
    printf("7. Self-Referential Structure (BST):\n");
    TreeNode *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    
    printf("   Inserting: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", values[i]);
        root = insert(root, values[i]);
    }
    
    printf("\n   Inorder traversal: ");
    inorder(root);
    printf("\n   (Sorted order)\n");
    
    return 0;
}
