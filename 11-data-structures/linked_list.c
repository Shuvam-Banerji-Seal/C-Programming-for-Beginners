/*
 * linked_list.c
 * Implements a singly linked list
 * Topics: Nodes, insertion, deletion, traversal
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create new node
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

// Insert at beginning
void insert_front(Node **head, int data) {
    Node *new_node = create_node(data);
    if (new_node != NULL) {
        new_node->next = *head;
        *head = new_node;
    }
}

// Print list
void print_list(Node *head) {
    Node *current = head;
    printf("   List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free list
void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    printf("=== Linked List Demo ===\n\n");
    
    Node *head = NULL;
    
    printf("1. Inserting elements:\n");
    insert_front(&head, 30);
    insert_front(&head, 20);
    insert_front(&head, 10);
    print_list(head);
    
    printf("\n2. List structure:\n");
    printf("   Each node contains data and pointer to next\n");
    printf("   Dynamic size - grows/shrinks as needed\n");
    
    // Cleanup
    free_list(head);
    printf("\n   Memory freed\n");
    
    return 0;
}
