#Implementation of the problem solving Backward Chaining
class Rule:
    def __init__(self, conclusion, *premises):
        self.conclusion = conclusion
        self.premises = premises

def backward_chaining(goal, rules):
    agenda = [goal]
    
    while agenda:
        goal = agenda.pop(0)
        print("Processing goal:", goal)
        found = False
        
        for rule in rules:
            if goal in rule.premises:
                print("Found a rule with goal in its premises:")
                print(rule.conclusion, "->", rule.premises)
                found = True
                
                for premise in rule.premises:
                    if premise not in agenda:
                        agenda.append(premise)
        
        if not found:
            print("No rules found for:", goal)
            return False
    
    return True

# Example usage
rules = [Rule("A", "C"), Rule("B", "C"), Rule("C", "D")]
backward_chaining("C", rules)
