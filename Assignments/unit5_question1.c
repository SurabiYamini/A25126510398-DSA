/* A network of n locations is represented as a graph. Write a C program that accepts the graph 
using an Adjacency Matrix, accepts a starting vertex, performs a graph traversal, displays the visit 
order, and ensures that a vertex is not processed repeatedly. Test it with connected and partially 
connected graphs. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int start, i, j;

    printf("Enter the number of locations: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nEnter the starting location: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting location!\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);
    printf("\nBFS Traversal: ");
    BFS(start);

    printf("\n");

    return 0;
}