/*
 * heap_priority_queue.c
 * Min/Max heap and priority queue implementation
 * Topics: Heapify, insertion, extraction, heap sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int size;
    int capacity;
    bool is_max_heap;
} Heap;

// Create heap
Heap* createHeap(int capacity, bool is_max_heap) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->is_max_heap = is_max_heap;
    return heap;
}

// Swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Get parent index
int parent(int i) {
    return (i - 1) / 2;
}

// Get left child index
int leftChild(int i) {
    return 2 * i + 1;
}

// Get right child index
int rightChild(int i) {
    return 2 * i + 2;
}

// Compare based on heap type
bool shouldSwap(Heap *heap, int parent_val, int child_val) {
    if (heap->is_max_heap) {
        return parent_val < child_val;
    } else {
        return parent_val > child_val;
    }
}

// Heapify up (bubble up)
void heapifyUp(Heap *heap, int index) {
    while (index > 0) {
        int parent_idx = parent(index);
        if (shouldSwap(heap, heap->data[parent_idx], heap->data[index])) {
            swap(&heap->data[parent_idx], &heap->data[index]);
            index = parent_idx;
        } else {
            break;
        }
    }
}

// Heapify down (bubble down)
void heapifyDown(Heap *heap, int index) {
    while (true) {
        int target = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if (left < heap->size && 
            shouldSwap(heap, heap->data[target], heap->data[left])) {
            target = left;
        }
        
        if (right < heap->size && 
            shouldSwap(heap, heap->data[target], heap->data[right])) {
            target = right;
        }
        
        if (target != index) {
            swap(&heap->data[index], &heap->data[target]);
            index = target;
        } else {
            break;
        }
    }
}

// Insert element
bool insert(Heap *heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("   Heap is full!\n");
        return false;
    }
    
    heap->data[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
    return true;
}

// Extract root (min or max)
int extract(Heap *heap) {
    if (heap->size == 0) {
        printf("   Heap is empty!\n");
        return -1;
    }
    
    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    
    return root;
}

// Peek at root
int peek(Heap *heap) {
    if (heap->size == 0) {
        printf("   Heap is empty!\n");
        return -1;
    }
    return heap->data[0];
}

// Build heap from array
void buildHeap(Heap *heap, int arr[], int n) {
    heap->size = n;
    for (int i = 0; i < n; i++) {
        heap->data[i] = arr[i];
    }
    
    // Heapify from last non-leaf to root
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(heap, i);
    }
}

// Heap sort
void heapSort(int arr[], int n) {
    Heap *heap = createHeap(n, false);  // Min heap
    buildHeap(heap, arr, n);
    
    // Extract elements in sorted order
    for (int i = 0; i < n; i++) {
        arr[i] = extract(heap);
    }
    
    free(heap->data);
    free(heap);
}

// Print heap
void printHeap(Heap *heap) {
    printf("   Heap (%s): [", heap->is_max_heap ? "Max" : "Min");
    for (int i = 0; i < heap->size; i++) {
        printf("%d", heap->data[i]);
        if (i < heap->size - 1) printf(", ");
    }
    printf("]\n");
}

// Print heap as tree (simple representation)
void printHeapTree(Heap *heap) {
    printf("   Heap Tree:\n");
    int level = 0;
    int count = 0;
    int level_size = 1;
    
    while (count < heap->size) {
        printf("   Level %d: ", level);
        for (int i = 0; i < level_size && count < heap->size; i++, count++) {
            printf("%d ", heap->data[count]);
        }
        printf("\n");
        level++;
        level_size *= 2;
    }
}

// Free heap
void freeHeap(Heap *heap) {
    free(heap->data);
    free(heap);
}

int main() {
    printf("=== Heap and Priority Queue ===\n\n");
    
    // Max heap operations
    printf("1. Max Heap Operations:\n");
    Heap *max_heap = createHeap(20, true);
    
    int values[] = {10, 20, 15, 30, 40, 25, 35};
    printf("   Inserting: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", values[i]);
        insert(max_heap, values[i]);
    }
    printf("\n");
    
    printHeap(max_heap);
    printHeapTree(max_heap);
    printf("   Max element (peek): %d\n\n", peek(max_heap));
    
    // Extract from max heap
    printf("2. Extract from Max Heap:\n");
    printf("   Extracted: %d\n", extract(max_heap));
    printf("   Extracted: %d\n", extract(max_heap));
    printHeap(max_heap);
    printf("\n");
    
    // Min heap operations
    printf("3. Min Heap Operations:\n");
    Heap *min_heap = createHeap(20, false);
    
    for (int i = 0; i < 7; i++) {
        insert(min_heap, values[i]);
    }
    
    printHeap(min_heap);
    printHeapTree(min_heap);
    printf("   Min element (peek): %d\n\n", peek(min_heap));
    
    // Extract from min heap
    printf("4. Extract from Min Heap:\n");
    printf("   Extracted: %d\n", extract(min_heap));
    printf("   Extracted: %d\n", extract(min_heap));
    printHeap(min_heap);
    printf("\n");
    
    // Build heap from array
    printf("5. Build Heap from Array:\n");
    int arr[] = {50, 30, 20, 15, 10, 8, 16};
    Heap *built_heap = createHeap(20, true);
    
    printf("   Original array: [");
    for (int i = 0; i < 7; i++) {
        printf("%d", arr[i]);
        if (i < 6) printf(", ");
    }
    printf("]\n");
    
    buildHeap(built_heap, arr, 7);
    printHeap(built_heap);
    printHeapTree(built_heap);
    printf("\n");
    
    // Heap sort
    printf("6. Heap Sort:\n");
    int sort_arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    printf("   Before sorting: [");
    for (int i = 0; i < n; i++) {
        printf("%d", sort_arr[i]);
        if (i < n-1) printf(", ");
    }
    printf("]\n");
    
    heapSort(sort_arr, n);
    
    printf("   After sorting:  [");
    for (int i = 0; i < n; i++) {
        printf("%d", sort_arr[i]);
        if (i < n-1) printf(", ");
    }
    printf("]\n\n");
    
    // Priority queue simulation
    printf("7. Priority Queue (Max Heap):\n");
    Heap *pq = createHeap(10, true);
    
    printf("   Enqueue tasks with priorities:\n");
    insert(pq, 5);  printf("   Task priority 5 added\n");
    insert(pq, 10); printf("   Task priority 10 added\n");
    insert(pq, 3);  printf("   Task priority 3 added\n");
    insert(pq, 8);  printf("   Task priority 8 added\n");
    
    printf("\n   Dequeue tasks (highest priority first):\n");
    while (pq->size > 0) {
        printf("   Processing task priority: %d\n", extract(pq));
    }
    
    // Cleanup
    freeHeap(max_heap);
    freeHeap(min_heap);
    freeHeap(built_heap);
    freeHeap(pq);
    
    printf("\n   Memory freed\n");
    
    return 0;
}
