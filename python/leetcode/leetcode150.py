tokens = ["18"]

def function(tokens: list):
    hashtable = {"+", "-", "*", "/"}
    stack = []
    if len(tokens) <= 1:
        return int(tokens[-1])
    while len(tokens) != 0:
        el = tokens.pop()                   
        if el in hashtable:
            stack.append(el)
        else:
            el = int(el)
            if type(el) != type(stack[-1]):
                stack.append(el)
            else:
                while stack and type(el) == type(stack[-1]):
                    num1 = el
                    num2 = stack.pop()
                    sign = stack.pop()
                    if sign == "*":
                        el = num1 * num2
                    elif sign == "+":
                        el = num1 + num2
                    elif sign == "-":
                        el = num1 - num2
                    elif sign == "/" and num2 != 0:
                        el = int(num1 / num2)
                    else: 
                        print('error')
                stack.append(el)
    return stack[-1]
print(function(tokens))