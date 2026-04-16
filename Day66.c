/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node* adjLists[MAX];
    int visited[MAX];
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int v) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = v;

    for (int i = 0; i < v; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS function to detect cycle
int DFS(struct Graph* graph, int vertex, int parent) {
    graph->visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];

    while (temp) {
        int adj = temp->data;

        if (!graph->visited[adj]) {
            if (DFS(graph, adj, vertex))
                return 1;
        }
        else if (adj != parent) {
            return 1; // Cycle detected
        }

        temp = temp->next;
    }
    return 0;
}

// Function to check cycle in graph
int hasCycle(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        if (!graph->visited[i]) {
            if (DFS(graph, i, -1))
                return 1;
        }
    }
    return 0;
}

// Main
int main() {
    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (hasCycle(graph))
        printf("YES (Cycle exists)\n");
    else
        printf("NO (No cycle)\n");

    return 0;
}
