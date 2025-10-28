#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX];
int n;

int minDistance(int dist[], int visited[]){
    int min=INF, idx=-1;
    for(int i=0;i<n;i++)
        if(!visited[i] && dist[i]<min){
            min=dist[i];
            idx=i;
        }
    return idx;
}

void dijkstra(int src){
    int dist[MAX], visited[MAX]={0};
    for(int i=0;i<n;i++)
        dist[i]=INF;
    dist[src]=0;

    for(int count=0; count<n-1; count++){
        int u=minDistance(dist, visited);
        if(u==-1) break;
        visited[u]=1;

        for(int v=0;v<n;v++)
            if(!visited[v] && graph[u][v]!=0 && dist[u]!=INF &&
               dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
    }

    printf("Shortest distances from node %d:\n", src);
    for(int i=0;i<n;i++)
        printf("%d -> %d = %s\n", src, i, (dist[i]==INF)?"INF":({ static char buf[10]; sprintf(buf,"%d",dist[i]); buf; }));
}

int main(){
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    int src;
    printf("Enter source node index: ");
    scanf("%d",&src);

    dijkstra(src);
    return 0;
}
