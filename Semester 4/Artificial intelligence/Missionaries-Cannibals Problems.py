#Implement and Demonstrate Best First Search Algorithm on Missionaries-Cannibals Problems using Python
from queue import PriorityQueue

# Define the state class
class State:
    def __init__(self, missionaries, cannibals, boat, parent=None):
        self.missionaries = missionaries
        self.cannibals = cannibals
        self.boat = boat
        self.parent = parent

    def __lt__(self, other):
        # Define comparison for PriorityQueue
        return False

    def __eq__(self, other):
        return (self.missionaries, self.cannibals, self.boat) == (other.missionaries, other.cannibals, other.boat)

    def __hash__(self):
        return hash((self.missionaries, self.cannibals, self.boat))

    def is_valid(self):
        # Check for valid state
        if self.missionaries < 0 or self.cannibals < 0 or self.missionaries > 3 or self.cannibals > 3:
            return False
        if self.missionaries > 0 and self.missionaries < self.cannibals:
            return False
        if 3 - self.missionaries > 0 and 3 - self.missionaries < 3 - self.cannibals:
            return False
        return True

    def is_goal(self):
        return self.missionaries == 0 and self.cannibals == 0 and self.boat == 0

    def successors(self):
        successors = []
        if self.boat == 1:
            # Boat is on the starting side
            for m in range(3):
                for c in range(3):
                    if 1 <= m + c <= 2:
                        new_state = State(self.missionaries - m, self.cannibals - c, 0, self)
                        if new_state.is_valid():
                            successors.append(new_state)
        else:
            # Boat is on the ending side
            for m in range(3):
                for c in range(3):
                    if 1 <= m + c <= 2:
                        new_state = State(self.missionaries + m, self.cannibals + c, 1, self)
                        if new_state.is_valid():
                            successors.append(new_state)
        return successors

    def path(self):
        path = []
        current = self
        while current:
            path.append((current.missionaries, current.cannibals, current.boat))
            current = current.parent
        return path[::-1]

def best_first_search(initial_state):
    frontier = PriorityQueue()
    explored = set()
    frontier.put((0, initial_state))
    
    while not frontier.empty():
        _, current_state = frontier.get()
        
        if current_state.is_goal():
            return current_state.path()
        
        explored.add(current_state)
        
        for successor in current_state.successors():
            if successor not in explored:
                frontier.put((heuristic(successor), successor))

def heuristic(state):
    # A simple heuristic: number of missionaries and cannibals on the starting side
    return state.missionaries + state.cannibals

# Initial state: 3 missionaries and 3 cannibals are on the starting side
initial_state = State(3, 3, 1)

# Solve the problem using Best-First Search
solution = best_first_search(initial_state)

# Print the solution
print("Solution:")
for i, step in enumerate(solution):
    print("Step {}: {} Missionaries, {} Cannibals, Boat on side {}".format(i + 1, step[0], step[1], "Starting" if step[2] == 1 else "Ending"))
