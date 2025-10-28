#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int n;
int graph[MAX][MAX];

void floydWarshall(){
    int dist[MAX][MAX];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j]=graph[i][j];

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];

    printf("\nAll pairs shortest path:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==INF) printf("INF ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int w;
            scanf("%d",&w);
            if(w==0 && i!=j) graph[i][j]=INF;
            else graph[i][j]=w;
        }

    floydWarshall();
    return 0;
}
