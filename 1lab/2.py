def matrix_chain_order(p):
    n = len(p) - 1
    m = [[0] * n for _ in range(n)]
    s = [[0] * n for _ in range(n)]

    for length in range(2, n + 1): 
        for i in range(n - length + 1):
            j = i + length - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

    return m, s

def print_optimal_parens(s, i, j):
    if i == j:
        print(f"A{i + 1}", end="")
    else:
        print("(", end="")
        print_optimal_parens(s, i, s[i][j])
        print_optimal_parens(s, s[i][j] + 1, j)
        print(")", end="")


n = 3
s = 5
p = []

for i in range(n):
    p.append(s)
    if i > 0:
        p[i] = p[i - 1] 

p.append(p[-1]) 

m, s = matrix_chain_order(p)

print("Минимальные затраты на умножение:", m[0][n - 1])
print("Оптимальная расстановка скобок: ", end="")
print_optimal_parens(s, 0, n - 1)
print()