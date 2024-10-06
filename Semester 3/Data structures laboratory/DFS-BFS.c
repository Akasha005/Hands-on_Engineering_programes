/*
Design, Develop and implement a program in C for the following operations on Graph (G) of cities:
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a diagraph using DFS/BFS method.
*/

#include <stdio.h>
#include <stdlib.h>

int a[10][10], n, m, i, j, source, s[10], b[10];
int visited[10];

// Function to create the adjacency matrix of the graph
void create() {
    printf("\nEnter the number of vertices of the digraph: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to perform BFS on the graph
void bfs() {
    int q[10], u, front = 0, rear = -1;
    for (i = 0; i <= n; i++)
        visited[i] = 0;

    printf("\nEnter the source vertex to find other nodes reachable or not: ");
    scanf("%d", &source);
    q[++rear] = source;
    visited[source] = 1;

    printf("\nThe reachable vertices are: ");
    while (front <= rear) {
        u = q[front++];
        for (i = 1; i <= n; i++) {
            if (a[u][i] == 1 && visited[i] == 0) {
                q[++rear] = i;
                visited[i] = 1;
                printf("\n%d", i);
            }
        }
    }
}

// Recursive function to perform DFS on the graph
void dfs(int source) {
    int v;
    s[source] = 1; // Mark the source as visited
    printf("\nVisited: %d", source);
    for (v = 1; v <= n; v++) {
        if (a[source][v] == 1 && s[v] == 0) {
            dfs(v);
        }
    }
}

// Main function with a menu-driven interface
void main() {
    int ch;
    while (1) {
        printf("\n1. Create Graph\n2. BFS\n3. Check graph connected or not (DFS)\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: bfs();
                for (i = 1; i <= n; i++) {
                    if (visited[i] == 0) {
                        printf("\nThe vertex that is not reachable: %d", i);
                    }
                }
                break;
            case 3: 
                for (i = 0; i <= n; i++)
                    s[i] = 0;
                printf("\nEnter the source vertex to find the connectivity: ");
                scanf("%d", &source);
                dfs(source);
                m = 1; // Assume connected
                for (i = 1; i <= n; i++) {
                    if (s[i] == 0) {
                        m = 0; // Found a vertex not visited
                    }
                }
                if (m == 1) {
                    printf("\nGraph is Connected");
                } else {
                    printf("\nGraph is not Connected");
                }
                break;
            default: exit(0);
        }
    }
}
