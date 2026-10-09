#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int adj[MAX][MAX];
int visited[MAX];
int n;
/* DFS Traversal */
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
/* BFS Traversal */
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i, v;
    /* Reset visited array */
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
    int choice, start, i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix of the graph:\n");
    printf("(Enter 1 if there is a directed edge, otherwise 0)\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    while (1)
    {
        printf("\n\n----- GRAPH MENU -----\n");
        printf("1. Display Adjacency Matrix\n");
        printf("2. DFS Traversal\n");
        printf("3. BFS Traversal\n");
        printf("4. Exit\n");
        printf("----------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nAdjacency Matrix:\n");
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                        printf("%d ", adj[i][j]);

                    printf("\n");
                }
                break;
            case 2:
                printf("\nEnter the starting city (0 to %d): ", n - 1);
                scanf("%d", &start);
                if (start < 0 || start >= n)
                {
                    printf("Invalid starting city!\n");
                    break;
                }
                for (i = 0; i < n; i++)
                    visited[i] = 0;
                printf("Cities reachable using DFS: ");
                DFS(start);
                printf("\n");
                break;
            case 3:
                printf("\nEnter the starting city (0 to %d): ", n - 1);
                scanf("%d", &start);
                if (start < 0 || start >= n)
                {
                    printf("Invalid starting city!\n");
                    break;
                }
                printf("Cities reachable using BFS: ");
                BFS(start);
                printf("\n");
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}