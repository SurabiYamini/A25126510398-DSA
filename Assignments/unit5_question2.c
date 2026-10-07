/*
A transportation network contains cities connected by roads with different costs.
Write a C program implementing Dijkstra's Shortest Path Algorithm that accepts the
number of vertices, weighted adjacency matrix and source vertex, computes the minimum
distance from the source to every other vertex, and displays each destination with
its shortest distance.
*/

#include <stdio.h>
#define MAX 20
#define INF 9999
int main()
{
    int n,graph[MAX][MAX];
    int distance[MAX],visited[MAX];
    int i,j,source,min,u;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter weighted adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
            if(i!=j&&graph[i][j]==0)
                graph[i][j]=INF;
        }
    }
    printf("Enter source vertex (0 to %d): ",n-1);
    scanf("%d",&source);
    for(i=0;i<n;i++)
    {
        distance[i]=graph[source][i];
        visited[i]=0;
    }
    distance[source]=0;
    for(i=0;i<n-1;i++)
    {
        min=INF;
        u=-1;
        for(j=0;j<n;j++)
        {
            if(visited[j]==0&&distance[j]<min)
            {
                min=distance[j];
                u=j;
            }
        }
        if(u==-1)
            break;
        visited[u]=1;
        for(j=0;j<n;j++)
        {
            if(visited[j]==0&&graph[u][j]!=INF&&distance[u]+graph[u][j]<distance[j])
                distance[j]=distance[u]+graph[u][j];
        }
    }
    printf("\nShortest distances from vertex %d:\n",source);
    for(i=0;i<n;i++)
    {
        if(distance[i]==INF)
            printf("Vertex %d: Not reachable\n",i);
        else
            printf("Vertex %d: %d\n",i,distance[i]);
    }
    return 0;
}