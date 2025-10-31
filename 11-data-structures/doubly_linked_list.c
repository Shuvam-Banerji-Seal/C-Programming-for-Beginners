/*
 * doubly_linked_list.c
 * Doubly linked list implementation
 * Topics: Insertion, deletion, traversal in both directions
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} DoublyLinkedList;

// Initialize list
void initList(DoublyLinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Create node
Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

// Insert at front
void insertFront(DoublyLinkedList *list, int data) {
    Node *node = createNode(data);
    if (node == NULL) return;
    
    if (list->head == NULL) {
        list->head = list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->size++;
}

// Insert at end
void insertEnd(DoublyLinkedList *list, int data) {
    Node *node = createNode(data);
    if (node == NULL) return;
    
    if (list->tail == NULL) {
        list->head = list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// Insert at position
int insertAt(DoublyLinkedList *list, int data, int position) {
    if (position < 0 || position > list->size) {
        return 0;
    }
    
    if (position == 0) {
        insertFront(list, data);
        return 1;
    }
    
    if (position == list->size) {
        insertEnd(list, data);
        return 1;
    }
    
    Node *node = createNode(data);
    if (node == NULL) return 0;
    
    Node *current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    node->next = current->next;
    node->prev = current;
    current->next->prev = node;
    current->next = node;
    list->size++;
    
    return 1;
}

// Delete from front
int deleteFront(DoublyLinkedList *list) {
    if (list->head == NULL) return 0;
    
    Node *temp = list->head;
    int data = temp->data;
    
    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    
    free(temp);
    list->size--;
    return data;
}

// Delete from end
int deleteEnd(DoublyLinkedList *list) {
    if (list->tail == NULL) return 0;
    
    Node *temp = list->tail;
    int data = temp->data;
    
    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    
    free(temp);
    list->size--;
    return data;
}

// Delete by value
int deleteValue(DoublyLinkedList *list, int value) {
    Node *current = list->head;
    
    while (current != NULL) {
        if (current->data == value) {
            if (current == list->head) {
                deleteFront(list);
            } else if (current == list->tail) {
                deleteEnd(list);
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
                list->size--;
            }
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Search
Node* search(DoublyLinkedList *list, int value) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Print forward
void printForward(DoublyLinkedList *list) {
    Node *current = list->head;
    printf("   Forward:  NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Print backward
void printBackward(DoublyLinkedList *list) {
    Node *current = list->tail;
    printf("   Backward: NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Reverse list
void reverseList(DoublyLinkedList *list) {
    Node *current = list->head;
    Node *temp = NULL;
    
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp != NULL) {
        temp = list->head;
        list->head = list->tail;
        list->tail = temp;
    }
}

// Free list
void freeList(DoublyLinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = list->tail = NULL;
    list->size = 0;
}

int main() {
    printf("=== Doubly Linked List ===\n\n");
    
    DoublyLinkedList list;
    initList(&list);
    
    // Insert operations
    printf("1. Insert Operations:\n");
    insertEnd(&list, 10);
    insertEnd(&list, 20);
    insertEnd(&list, 30);
    printf("   After insertEnd(10, 20, 30):\n");
    printForward(&list);
    
    insertFront(&list, 5);
    printf("   After insertFront(5):\n");
    printForward(&list);
    
    insertAt(&list, 15, 2);
    printf("   After insertAt(15, position 2):\n");
    printForward(&list);
    printf("   Size: %d\n\n", list.size);
    
    // Traversal
    printf("2. Bidirectional Traversal:\n");
    printForward(&list);
    printBackward(&list);
    printf("\n");
    
    // Search
    printf("3. Search:\n");
    Node *found = search(&list, 15);
    if (found != NULL) {
        printf("   Found value 15\n");
    }
    found = search(&list, 100);
    if (found == NULL) {
        printf("   Value 100 not found\n\n");
    }
    
    // Delete operations
    printf("4. Delete Operations:\n");
    deleteFront(&list);
    printf("   After deleteFront():\n");
    printForward(&list);
    
    deleteEnd(&list);
    printf("   After deleteEnd():\n");
    printForward(&list);
    
    deleteValue(&list, 15);
    printf("   After deleteValue(15):\n");
    printForward(&list);
    printf("   Size: %d\n\n", list.size);
    
    // Reverse
    printf("5. Reverse List:\n");
    insertEnd(&list, 40);
    insertEnd(&list, 50);
    printf("   Before reverse:\n");
    printForward(&list);
    
    reverseList(&list);
    printf("   After reverse:\n");
    printForward(&list);
    
    // Cleanup
    freeList(&list);
    printf("\n   Memory freed\n");
    
    return 0;
}
