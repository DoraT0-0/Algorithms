import random

class Matrix:
    def __init__(self, n: int, m: int):
        self.n = n
        self.m = m
        self.matrix = []

    def initMatrix(self):
        self.matrix = [[round(random.uniform(-3.3, 3.3), 2) for _ in range(self.n)] for _ in range(self.m)]

    def printMatrix(self):
        print('\t Matrix:')
        for i in range(self.m):
            for j in range(self.n):
                print(self.matrix[i][j], end= ' | ')
            print('')

    def summRows(self):
        arr = []
        for i in range(self.m):
            arr.append(round(sum(self.matrix[i]), 2))
        return arr

def main():
    n : int
    m : int
    while True:
        n = int(input("n : "))
        m = int(input("m : "))
        if n <= 10 and n >= 3 and m <= 10 and m >= 3:
            break
        elif n == 0 or m == 0:
            return
    A = Matrix(n, m)
    A.initMatrix()
    B = A.summRows()
    A.printMatrix()
    print(B)
main()

