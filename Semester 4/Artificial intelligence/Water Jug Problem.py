#Implement and Demonstrate Depth First Search Algorithm on Water Jug Problem
class State:
    def __init__(self, jug1, jug2):
        self.jug1 = jug1
        self.jug2 = jug2

    def __eq__(self, other):
        return self.jug1 == other.jug1 and self.jug2 == other.jug2

    def __hash__(self):
        return hash((self.jug1, self.jug2))

def dfs(curr_state, visited, jug1_capacity, jug2_capacity, target):
    if curr_state.jug1 == target or curr_state.jug2 == target:
        return True
    visited.add(curr_state)
    
    # Fill jug1
    if curr_state.jug1 < jug1_capacity:
        new_state = State(jug1_capacity, curr_state.jug2)
        if new_state not in visited and dfs(new_state, visited, jug1_capacity, jug2_capacity, target):
            print("Fill jug1")
            return True

    # Fill jug2
    if curr_state.jug2 < jug2_capacity:
        new_state = State(curr_state.jug1, jug2_capacity)
        if new_state not in visited and dfs(new_state, visited, jug1_capacity, jug2_capacity, target):
            print("Fill jug2")
            return True

    # Empty jug1
    if curr_state.jug1 > 0:
        new_state = State(0, curr_state.jug2)
        if new_state not in visited and dfs(new_state, visited, jug1_capacity, jug2_capacity, target):
            print("Empty jug1")
            return True

    # Empty jug2
    if curr_state.jug2 > 0:
        new_state = State(curr_state.jug1, 0)
        if new_state not in visited and dfs(new_state, visited, jug1_capacity, jug2_capacity, target):
            print("Empty jug2")
            return True

    # Pour jug1 to jug2
    if curr_state.jug1 > 0 and curr_state.jug2 < jug2_capacity:
        transfer_amount = min(curr_state.jug1, jug2_capacity - curr_state.jug2)
        new_state = State(curr_state.jug1 - transfer_amount, curr_state.jug2 + transfer_amount)
        if new_state not in visited and dfs(new_state, visited, jug1_capacity, jug2_capacity, target):
            print("Pour jug1 to jug2")
            return True

    # Pour jug2 to jug1
    if curr_state.jug2 > 0 and curr_state.jug1 < jug1_capacity:
        transfer_amount = min(curr_state.jug2, jug1_capacity - curr_state.jug1)
        new_state = State(curr_state.jug1 + transfer_amount, curr_state.jug2 - transfer_amount)
        if new_state not in visited and dfs(new_state, visited, jug1_capacity, jug2_capacity, target):
            print("Pour jug2 to jug1")
            return True

    return False

def water_jug_problem(jug1_capacity, jug2_capacity, target):
    initial_state = State(0, 0)
    visited = set()
    
    if dfs(initial_state, visited, jug1_capacity, jug2_capacity, target):
        print("Target volume reached!")
    else:
        print("Target volume cannot be reached.")

# Example usage
water_jug_problem(4, 3, 2)  # Jug capacities: (4, 3), Target: 2
