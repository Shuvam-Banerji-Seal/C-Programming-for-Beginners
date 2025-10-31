#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Create new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert node
Node* insert(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Search
Node* search(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Inorder traversal
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find minimum
Node* findMin(Node *root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete node
Node* deleteNode(Node *root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Count nodes
int countNodes(Node *root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Height of tree
int height(Node *root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    printf("=== Binary Search Tree Implementation ===\n\n");
    
    Node *root = NULL;
    
    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printf("Tree structure (values inserted: 50, 30, 70, 20, 40, 60, 80)\n\n");
    
    // Traversals
    printf("Inorder traversal (sorted): ");
    inorder(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n\n");
    
    // Tree properties
    printf("Total nodes: %d\n", countNodes(root));
    printf("Tree height: %d\n\n", height(root));
    
    // Search
    int key = 40;
    Node *found = search(root, key);
    printf("Search for %d: %s\n", key, found ? "Found" : "Not found");
    
    key = 100;
    found = search(root, key);
    printf("Search for %d: %s\n\n", key, found ? "Found" : "Not found");
    
    // Delete
    printf("Deleting 20...\n");
    root = deleteNode(root, 20);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    
    printf("\nDeleting 30...\n");
    root = deleteNode(root, 30);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    
    printf("\nDeleting 50 (root)...\n");
    root = deleteNode(root, 50);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    
    return 0;
}
