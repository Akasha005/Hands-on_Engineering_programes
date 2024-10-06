#include <stdio.h>
#define INF 99999 // Infinity
// Function to implement Floyd's algorithm
void floydWarshall(int graph[][4], int V) {
int dist[V][V], i, j, k;
// Initialize the distance matrix same as input graph matrix
for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
dist[i][j] = graph[i][j];
// Calculate shortest paths using Floyd-Warshall algorithm
for (k = 0; k < V; k++) {
// Pick all vertices as source one by one
for (i = 0; i < V; i++) {
// Pick all vertices as destination for the
// above picked source
for (j = 0; j < V; j++) {
// If vertex k is on the shortest path from
// i to j, then update the value of dist[i][j]
if (dist[i][k] + dist[k][j] < dist[i][j])
dist[i][j] = dist[i][k] + dist[k][j];
}
}
}
// Print the shortest distance matrix
printf("The following matrix shows the shortest distances"
" between every pair of vertices:\n");
for (i = 0; i < V; i++) {
for (j = 0; j < V; j++) {
if (dist[i][j] == INF)
printf("%7s", "INF");
else
printf("%7d", dist[i][j]);
}
printf("\n");
}
}
int main() {
// Number of vertices in the graph
int V = 4;
// Graph representation as an adjacency matrix
int graph[4][4] = {{0, 5, INF, 10},
{INF, 0, 3, INF},
{INF, INF, 0, 1},
{INF, INF, INF, 0}};
// Call the function
floydWarshall(graph, V);
return 0;
}
