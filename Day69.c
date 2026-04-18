/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <limits.h>

#define MAX 100

// Graph (Adjacency Matrix)
int graph[MAX][MAX];

// Min Heap structure
struct Node {
    int vertex;
    int distance;
};

struct Node heap[MAX];
int size = 0;

// Swap function
void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int index) {
    while (index && heap[(index - 1) / 2].distance > heap[index].distance) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].distance < heap[smallest].distance)
        smallest = left;

    if (right < size && heap[right].distance < heap[smallest].distance)
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int v, int dist) {
    heap[size].vertex = v;
    heap[size].distance = dist;
    heapifyUp(size);
    size++;
}

// Extract min
struct Node pop() {
    struct Node root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

// Dijkstra Algorithm
void dijkstra(int n, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        struct Node curr = pop();
        int u = curr.vertex;

        if (visited[u])
            continue;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    push(v, dist[v]);
                }
            }
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main
int main() {
    int n, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}
