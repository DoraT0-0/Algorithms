s = "))"


def function(s: str):
    stack1 = list(s)
    stack2 = []
    while len(stack1) != 0:
        elm1 = stack1.pop()
        if len(stack2) == 0:
            stack2.append(elm1)
            continue
        elm2 = stack2[-1]
        if elm1 == '(' and elm2 == ')':
            stack2.pop()
        elif elm1 == '[' and elm2 == ']':
            stack2.pop()
        elif elm1 == '{' and elm2 == '}':
            stack2.pop()
        else:
            stack2.append(elm1)
    if len(stack2) == 0:
        return True
    return False
print(function(s))
    