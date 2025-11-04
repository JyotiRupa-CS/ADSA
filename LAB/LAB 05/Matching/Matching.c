#include <stdio.h>
#include <string.h>

#define MAX 100

int n1, n2, edges;
int adj[MAX][MAX];   // Adjacency matrix for bipartite graph
int matchR[MAX];     // matchR[v] = The u assigned to vertex v in right set
int visited[MAX];

// DFS to find if a matching for vertex u is possible
int bpm(int u) {
    for (int v = 1; v <= n2; v++) {
        // If there is an edge and v is not visited
        if (adj[u][v] && !visited[v]) {
            visited[v] = 1;  // Mark v as visited

            // If v is not matched OR previously matched vertex can find alternate
            if (matchR[v] == -1 || bpm(matchR[v])) {
                matchR[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices in left set (U): ");
    scanf("%d", &n1);
    printf("Enter number of vertices in right set (V): ");
    scanf("%d", &n2);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    memset(adj, 0, sizeof(adj));
    memset(matchR, -1, sizeof(matchR));

    printf("Enter edges (u v) where u ∈ U and v ∈ V:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u < 1 || u > n1 || v < 1 || v > n2) {
            printf("Invalid edge! Try again.\n");
            i--;
            continue;
        }
        adj[u][v] = 1;
    }

    int result = 0; // Count of matches

    // Try to find a matching for every vertex u in U
    for (int u = 1; u <= n1; u++) {
        memset(visited, 0, sizeof(visited));

        if (bpm(u))
            result++;
    }

    printf("\nMaximum number of matches possible: %d\n", result);
    printf("Matched pairs (U -> V):\n");

    for (int v = 1; v <= n2; v++) {
        if (matchR[v] != -1)
            printf("U%d -> V%d\n", matchR[v], v);
    }

    return 0;
}
