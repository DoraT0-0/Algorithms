a_con = [[7, 9, 3, 4, 8, 4], [8, 5, 6, 4, 5, 7]]
t_con = [[2, 3, 1, 3, 4], [2, 1, 2, 2, 1]]
e = [2, 4]
x = [3, 2]
l1, l2 = [], []

def f(j: int, f1: int, f2: int):
    if j == 0:
        f1 = e[0] + a_con[0][0]
        f2 = e[1] + a_con[1][0]
        return f(j+1, f1, f2)
    elif j == len(a_con[0]):
        f1 = f1 + x[0]
        f2 = f2 + x[1]
        if f1 <= f2:
            return 1
        else:
            return 2
    else:
        if f1 + a_con[0][j] <= f2 + t_con[1][j-1] + a_con[0][j]:
            _f1 = f1 + a_con[0][j]
            l1.append(1)
        else:
            _f1 = f2 + t_con[1][j-1] + a_con[0][j]
            l1.append(2)
        if f2 + a_con[1][j] <= f1 + t_con[0][j-1] + a_con[1][j]:
            _f2 = f2 + a_con[1][j]
            l2.append(2)
        else:
            _f2 = f1 + t_con[0][j-1] + a_con[1][j]
            l2.append(1)
        return f(j+1, _f1, _f2)


def print_station(l_last: int):
    l = []
    print(f"Конвейер {l_last}, рабочее место {len(l1)+1}")
    for i in range(len(l1)-1, -1, -1):
        if l_last == 1:
            l.append(l1[i])
            l_last = l1[i]
        l.append(l2[i])
        l_last = l2[i]
        print(f"Конвейер {l_last}, рабочее место {i+1}")

print_station(f(0, 0, 0))
