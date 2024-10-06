#Implementation of TSP using heuristic approach
from sys import maxsize
from itertools import permutations

# Number of vertices in the graph
v = 4

def tsp(graph, s):
    # Store all vertices except the source vertex
    vertex = []
    for i in range(v):
        if i != s:
            vertex.append(i)

    # Store the minimum weight of a Hamiltonian Cycle
    min_path = maxsize
    next_permutation = permutations(vertex)

    # Generate all permutations of vertices and calculate the path cost
    for i in next_permutation:
        current_pathweight = 0

        # Starting point
        k = s

        # Add edge weights between consecutive vertices
        for j in i:
            current_pathweight += graph[k][j]
            k = j
        
        # Add the weight for the edge returning to the start
        current_pathweight += graph[k][s]

        # Update minimum path weight
        min_path = min(min_path, current_pathweight)

    return min_path

if __name__ == '__main__':
    # Example graph with distances
    graph = [[0, 10, 15, 20],
             [10, 0, 35, 25],
             [15, 35, 0, 30],
             [20, 25, 30, 0]]

    # Starting point is vertex 0
    print(tsp(graph, 0))
