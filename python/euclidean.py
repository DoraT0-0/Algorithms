def euclidean(a: int, b: int):
    while b != 0:
        r: int = a % b
        a = b
        b = r
    return a

print(euclidean(4851, 3003))