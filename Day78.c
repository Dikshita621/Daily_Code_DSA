/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];

int minKey(int key[], int mst[]) {
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++) {
        if (!mst[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST() {
    int key[MAX];
    int mst[MAX];
    
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[1] = 0;  // start from node 1
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, mst);
        mst[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // Input edges
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  // undirected
    }

    printf("%d\n", primMST());

    return 0;
}
