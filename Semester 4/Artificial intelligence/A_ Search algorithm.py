#Implement A* Search algorithm
def aStarAlgo(start_node, stop_node):
    open_set = set(start_node)
    closed_set = set()
    g = {}  # store distance from starting node
    parents = {}  # parents contains an adjacency map of all nodes

    # Distance of starting node from itself is zero
    g[start_node] = 0
    # Start_node is the root node, so it is set as its own parent
    parents[start_node] = start_node

    while len(open_set) > 0:
        n = None

        # Node with the lowest f() is found
        for v in open_set:
            if n is None or g[v] + heuristic(v) < g[n] + heuristic(n):
                n = v

        if n == stop_node or Graph_nodes[n] is None:
            pass
        else:
            for (m, weight) in get_neighbors(n):
                # Nodes 'm' not in first and last set are added to the first
                # n is set as its parent
                if m not in open_set and m not in closed_set:
                    open_set.add(m)
                    parents[m] = n
                    g[m] = g[n] + weight
                else:
                    # For each node m, compare its distance from start i.e g(m) to
                    # the distance from start through node n
                    if g[m] > g[n] + weight:
                        # Update g(m)
                        g[m] = g[n] + weight
                        # Change parent of m to n
                        parents[m] = n
                        # If m is in closed set, remove it and add to open set
                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)

        if n is None:
            print('Path does not exist!')
            return None

        # If the current node is the stop_node, reconstruct the path
        if n == stop_node:
            path = []
            while parents[n] != n:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            print('Path found: {}'.format(path))
            return path

        # Remove n from the open set, and add it to closed set
        # because all of its neighbors were inspected
        open_set.remove(n)
        closed_set.add(n)

    print('Path does not exist!')
    return None

# Define function to return neighbors and their distances from the passed node
def get_neighbors(v):
    if v in Graph_nodes:
        return Graph_nodes[v]
    else:
        return None

# For simplicity, we will consider heuristic distances given
# and this function returns heuristic distance for all nodes
def heuristic(n):
    H_dist = {
        'A': 1,
        'B': 1,
        'C': 1,
        'D': 1,
    }
    return H_dist[n]

# Describe your graph here
Graph_nodes = {
    'A': [('B', 1), ('C', 3), ('D', 7)],
    'B': [('D', 5)],
    'C': [('D', 12)],
    'D': None,
}

aStarAlgo('A', 'D')
