#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int graph[MAX][MAX];
int n = 0;
char nodes[MAX][10];

// Find node index
int getIndex(char name[]) {
    for(int i=0;i<n;i++)
        if(strcmp(nodes[i], name)==0) return i;
    return -1;
}

// Add node if not exists
int addNode(char name[]) {
    int idx = getIndex(name);
    if(idx==-1){
        strcpy(nodes[n], name);
        n++;
        return n-1;
    }
    return idx;
}

// Initialize graph
void initGraph() {
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            graph[i][j]=0;
}

// Read SIF file
void readSIF(char filename[]) {
    FILE *fp=fopen(filename,"r");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(1);
    }
    char u[10], v[10], edge[10];
    initGraph();
    while(fscanf(fp,"%s %s %s", u, edge, v)!=EOF){
        int i=addNode(u);
        int j=addNode(v);
        graph[i][j]=1;
        graph[j][i]=1; // undirected
    }
    fclose(fp);
}

// Display adjacency matrix
void displayGraph() {
    printf("\nAdjacency Matrix:\n   ");
    for(int i=0;i<n;i++)
        printf("%s ", nodes[i]);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%s ", nodes[i]);
        for(int j=0;j<n;j++)
            printf(" %d", graph[i][j]);
        printf("\n");
    }
}

int main() {
    char filename[50];
    printf("Enter SIF filename: ");
    scanf("%s", filename);

    readSIF(filename);
    printf("Graph nodes:\n");
    for(int i=0;i<n;i++)
        printf("%s ", nodes[i]);
    printf("\n");
    displayGraph();

    return 0;
}
