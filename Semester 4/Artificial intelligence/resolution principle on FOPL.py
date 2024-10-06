#Implement resolution principle on FOPL related problems
import re

def dnf(formula):
    if re.fullmatch(r'[A-Z]|~[A-Z]|()""', formula):
        return formula
    if 'and' in formula or 'or' in formula:
        parts = re.split(r'(?<=[^\w])or(?=[^\w])|(?<=[^\w])and(?=[^\w])', formula)
        dnf_parts = [dnf(part) for part in parts]
        if 'or' in formula:
            return " or ".join(parts)
        elif 'and' in formula:
            return " and ".join(parts)

formula = "(A and B) or C"
dnf_formula = dnf(formula)
print(dnf_formula)  # Outputs: "A or C or B"

def cnf(formula):
    if re.fullmatch(r'[A-Z]|~[A-Z]', formula):
        return formula
    if 'and' in formula or 'or' in formula:
        parts = re.split(r'(?<=\()or(?=\))|(?<=\()and(?=\))', formula)
        if 'and' in formula:
            return " and ".join(parts)
        elif 'or' in formula:
            return " or ".join(parts)

# Example usage
formula = "(A and B) and (C and D)"
cnf_formula = cnf(formula)
print(cnf_formula)  # Outputs: "A and B or C and D or"
