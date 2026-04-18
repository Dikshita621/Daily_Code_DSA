/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int indegree[MAX];   // In-degree array
int queue[MAX];
int front = -1, rear = -1;

// Queue operations
void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Kahn's Algorithm
void topologicalSort(int n) {
    int i, j, count = 0;

    // Calculate indegree
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            if (adj[j][i] == 1)
                indegree[i]++;
        }
    }

    // Add vertices with indegree 0 to queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);
        count++;

        // Reduce indegree of adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Check for cycle
    if (count != n)
        printf("\nGraph has a cycle! Topological sort not possible.\n");
}

// Main function
int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(n);

    return 0;
}
