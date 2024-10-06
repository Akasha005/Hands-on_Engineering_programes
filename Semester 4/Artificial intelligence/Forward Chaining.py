#Implementation of the problem solving using Forward Chaining
def check(str, factsOb):
    facts = []
    flag = True
    while flag == True:
        flag = False
        for txt in str:
            for AI in factsOb:
                if AI[0] == txt:
                    tmp = [txt, AI[1]]
                    if not tmp in facts:
                        facts += [tmp]
                        str += AI[1]
                        flag = True
    return facts

factskw = [["croak", "frog"], ["eats flies", "frog"], ["frog", "green"],
           ["chips", "canary"], ["sing", "canary"], ["canary", "yellow"]]

result = check(["sing", "canary"], factskw)
print(result)
