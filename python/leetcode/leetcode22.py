def function(n :int):
    stack = []
    res = []

    def backtraking(openN: int, closedN: int):
        if openN == closedN == n:
            res.append("".join(stack))
            return
        
        if openN < n:
            stack.append("(")
            backtraking(openN+1, closedN)
            stack.pop()
        
        if closedN < openN:
            stack.append(")")
            backtraking(openN, closedN+1)
            stack.pop()
    backtraking(0,0)
    return res

print(function(3))