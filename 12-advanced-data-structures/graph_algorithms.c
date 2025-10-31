/*
 * graph_algorithms.c
 * Graph algorithms implementation
 * Topics: DFS, BFS, shortest path, connected components
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    int weight;
    struct Node *next;
} Node;

typedef struct {
    int num_vertices;
    Node **adj_list;
} Graph;

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Queue operations
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    int value = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Create graph
Graph* createGraph(int vertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = vertices;
    graph->adj_list = (Node**)malloc(vertices * sizeof(Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adj_list[i] = NULL;
    }
    
    return graph;
}

// Add edge
void addEdge(Graph *graph, int src, int dest, int weight) {
    // Add edge from src to dest
    Node *node = (Node*)malloc(sizeof(Node));
    node->vertex = dest;
    node->weight = weight;
    node->next = graph->adj_list[src];
    graph->adj_list[src] = node;
    
    // For undirected graph, add edge from dest to src
    node = (Node*)malloc(sizeof(Node));
    node->vertex = src;
    node->weight = weight;
    node->next = graph->adj_list[dest];
    graph->adj_list[dest] = node;
}

// DFS helper
void DFSUtil(Graph *graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    Node *temp = graph->adj_list[vertex];
    while (temp != NULL) {
        int adj_vertex = temp->vertex;
        if (!visited[adj_vertex]) {
            DFSUtil(graph, adj_vertex, visited);
        }
        temp = temp->next;
    }
}

// DFS traversal
void DFS(Graph *graph, int start) {
    bool *visited = (bool*)calloc(graph->num_vertices, sizeof(bool));
    
    printf("   DFS from vertex %d: ", start);
    DFSUtil(graph, start, visited);
    printf("\n");
    
    free(visited);
}

// BFS traversal
void BFS(Graph *graph, int start) {
    bool *visited = (bool*)calloc(graph->num_vertices, sizeof(bool));
    Queue q;
    initQueue(&q);
    
    visited[start] = true;
    enqueue(&q, start);
    
    printf("   BFS from vertex %d: ", start);
    
    while (!isEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);
        
        Node *temp = graph->adj_list[vertex];
        while (temp != NULL) {
            int adj_vertex = temp->vertex;
            if (!visited[adj_vertex]) {
                visited[adj_vertex] = true;
                enqueue(&q, adj_vertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    
    free(visited);
}

// Find shortest path using BFS (unweighted)
void shortestPath(Graph *graph, int start, int end) {
    bool *visited = (bool*)calloc(graph->num_vertices, sizeof(bool));
    int *distance = (int*)malloc(graph->num_vertices * sizeof(int));
    int *parent = (int*)malloc(graph->num_vertices * sizeof(int));
    Queue q;
    initQueue(&q);
    
    for (int i = 0; i < graph->num_vertices; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    
    visited[start] = true;
    distance[start] = 0;
    enqueue(&q, start);
    
    while (!isEmpty(&q)) {
        int vertex = dequeue(&q);
        
        Node *temp = graph->adj_list[vertex];
        while (temp != NULL) {
            int adj_vertex = temp->vertex;
            if (!visited[adj_vertex]) {
                visited[adj_vertex] = true;
                distance[adj_vertex] = distance[vertex] + 1;
                parent[adj_vertex] = vertex;
                enqueue(&q, adj_vertex);
            }
            temp = temp->next;
        }
    }
    
    if (distance[end] == INT_MAX) {
        printf("   No path from %d to %d\n", start, end);
    } else {
        printf("   Shortest path from %d to %d (distance %d): ", 
               start, end, distance[end]);
        
        // Reconstruct path
        int path[MAX_VERTICES];
        int path_len = 0;
        int current = end;
        
        while (current != -1) {
            path[path_len++] = current;
            current = parent[current];
        }
        
        for (int i = path_len - 1; i >= 0; i--) {
            printf("%d", path[i]);
            if (i > 0) printf(" -> ");
        }
        printf("\n");
    }
    
    free(visited);
    free(distance);
    free(parent);
}

// Count connected components
int countComponents(Graph *graph) {
    bool *visited = (bool*)calloc(graph->num_vertices, sizeof(bool));
    int count = 0;
    
    for (int i = 0; i < graph->num_vertices; i++) {
        if (!visited[i]) {
            DFSUtil(graph, i, visited);
            count++;
        }
    }
    
    free(visited);
    return count;
}

// Check if graph has cycle (for undirected graph)
bool hasCycleUtil(Graph *graph, int vertex, bool visited[], int parent) {
    visited[vertex] = true;
    
    Node *temp = graph->adj_list[vertex];
    while (temp != NULL) {
        int adj_vertex = temp->vertex;
        
        if (!visited[adj_vertex]) {
            if (hasCycleUtil(graph, adj_vertex, visited, vertex)) {
                return true;
            }
        } else if (adj_vertex != parent) {
            return true;
        }
        
        temp = temp->next;
    }
    
    return false;
}

bool hasCycle(Graph *graph) {
    bool *visited = (bool*)calloc(graph->num_vertices, sizeof(bool));
    
    for (int i = 0; i < graph->num_vertices; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(graph, i, visited, -1)) {
                free(visited);
                return true;
            }
        }
    }
    
    free(visited);
    return false;
}

// Print graph
void printGraph(Graph *graph) {
    printf("   Graph adjacency list:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("   [%d]: ", i);
        Node *temp = graph->adj_list[i];
        while (temp != NULL) {
            printf("%d(w=%d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Free graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        Node *temp = graph->adj_list[i];
        while (temp != NULL) {
            Node *to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(graph->adj_list);
    free(graph);
}

int main() {
    printf("=== Graph Algorithms ===\n\n");
    
    // Create graph
    printf("1. Create Graph:\n");
    Graph *graph = createGraph(7);
    
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 4, 5, 1);
    addEdge(graph, 5, 6, 1);
    
    printGraph(graph);
    printf("\n");
    
    // DFS
    printf("2. Depth First Search:\n");
    DFS(graph, 0);
    printf("\n");
    
    // BFS
    printf("3. Breadth First Search:\n");
    BFS(graph, 0);
    printf("\n");
    
    // Shortest path
    printf("4. Shortest Path:\n");
    shortestPath(graph, 0, 6);
    shortestPath(graph, 1, 5);
    printf("\n");
    
    // Cycle detection
    printf("5. Cycle Detection:\n");
    printf("   Graph has cycle: %s\n\n", hasCycle(graph) ? "Yes" : "No");
    
    // Connected components
    printf("6. Connected Components:\n");
    int components = countComponents(graph);
    printf("   Number of connected components: %d\n\n", components);
    
    // Create disconnected graph
    printf("7. Disconnected Graph:\n");
    Graph *graph2 = createGraph(6);
    addEdge(graph2, 0, 1, 1);
    addEdge(graph2, 0, 2, 1);
    addEdge(graph2, 3, 4, 1);
    // Vertex 5 is isolated
    
    printGraph(graph2);
    printf("   Number of connected components: %d\n", countComponents(graph2));
    
    // Cleanup
    freeGraph(graph);
    freeGraph(graph2);
    printf("\n   Memory freed\n");
    
    return 0;
}
