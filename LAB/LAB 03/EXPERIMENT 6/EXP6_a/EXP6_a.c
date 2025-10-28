#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, e;
    int graph[MAX][MAX];
    int i, j;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // Initialize adjacency matrix with INF (no edge)
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = INT_MAX;

    printf("Enter each edge as: vertex1 vertex2 weight\n");
    for (i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }

    int selected[MAX];
    int key[MAX];
    int parent[MAX];

    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        selected[i] = 0;
    }

    key[0] = 0;       // Start from vertex 0
    parent[0] = -1;   // Root has no parent

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u = -1;

        // Pick vertex with minimum key value
        for (i = 0; i < n; i++)
            if (!selected[i] && key[i] < min) {
                min = key[i];
                u = i;
            }

        selected[u] = 1;

        // Update key and parent for adjacent vertices
        for (j = 0; j < n; j++) {
            if (graph[u][j] && graph[u][j] != INT_MAX && !selected[j] && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    int totalWeight = 0;
    printf("\nMinimum Spanning Tree edges:\n");
    for (i = 1; i < n; i++) {
        printf("%d -- %d == %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }

    printf("\nTotal weight of MST: %d\n", totalWeight);

    return 0;
}

