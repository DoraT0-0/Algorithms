def euclidean(a: int, b: int):
    while b != 0:
        r = a % b
        print(r)
        a = b
        b = r
    return a

print(euclidean(4851, 3003))