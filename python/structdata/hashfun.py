
class Node:
    def __init__(self):
        self.data = None
        self.next = None


m = 11
_hash_table = [Node() for _ in range(m)]

def doubleHashCode(k : int, num_test: int):
    def hashCode1(k : int):
        return k % 23
    def hashCode2(k : int):
        return 1+(k % 19)
    return (hashCode1(k) + num_test*hashCode2(k)) % 23

def hashCode(k: int):
    return ((3*k + 42)% 101) % 11
    # return (7*k + 3) % 4 

def countElemetHT(hash_table: list):
    count = 0
    for i in hash_table:
        if i.data is None: continue
        cur = i
        while cur:
            count += 1
            cur = cur.next
    return count

def newHashTable():
    global m, _hash_table
    m = m*2
    hash_table_new = [Node() for _ in range(m)]
    for i, node  in enumerate(_hash_table):
        cur = node
        while cur:
            addInHT(key = i, value = cur.data, hash_table = hash_table_new)
            cur = cur.next
    _hash_table = hash_table_new

def addInHT(value, hash_table: list, key = None , hashcode = None):
    global m
    if countElemetHT(hash_table) > m:
        newHashTable()
    hash_code: int
    if hashcode is None: hash_code = hashCode(key)%m
    elif hashcode is not None: hash_code = hashcode%m

    if hash_table[hash_code].data == None:
        hash_table[hash_code].data = value
    else:
        cur = hash_table[hash_code]
        while cur.next:
            cur = cur.next
        new_node = Node()
        new_node.data = value
        cur.next = new_node

def printHT(hash_table: list):
    info = ''
    for i in hash_table:
        if i.data is None:
            info += f'None\n'
            continue
        cur = i
        while cur:
            info += str(cur.data) + '-> '
            cur = cur.next
        info += 'None\n'
    return info
# Task 1

# addInHT(key = 9, value = "k1", hash_table= _hash_table)
# addInHT(key = 282, value = "k2", hash_table=_hash_table)
# addInHT(key = 270,value =  "k3", hash_table= _hash_table)
# addInHT(key = 122,value =  "k4", hash_table= _hash_table)
# addInHT(key = 263,value =  "k5", hash_table= _hash_table)


# print(printHT(_hash_table))

# Task 2

# print(doubleHashCode(53, 1))

# Task 3

# addInHT(key = 9, value = "k1", hash_table= _hash_table)
# addInHT(key = 282, value = "k2", hash_table=_hash_table)
# addInHT(key = 270,value =  "k3", hash_table= _hash_table)
# addInHT(key = 122,value =  "k4", hash_table= _hash_table)
# addInHT(key = 263,value =  "k5", hash_table= _hash_table)
# addInHT(key = 53,value =  "k6", hash_table= _hash_table)
# addInHT(key = 185,value =  "k7", hash_table= _hash_table)

# print(printHT(_hash_table))

# Task 4

addInHT(key = 9, value = "k1", hash_table= _hash_table)
addInHT(key = 282, value = "k2", hash_table=_hash_table)
addInHT(key = 270,value =  "k3", hash_table= _hash_table)
addInHT(key = 122,value =  "k4", hash_table= _hash_table)
addInHT(key = 263,value =  "k5", hash_table= _hash_table)
addInHT(key = 53,value =  "k6", hash_table= _hash_table)
addInHT(key = 185,value =  "k7", hash_table= _hash_table)
addInHT(key = 158,value =  "k8", hash_table= _hash_table)
addInHT(key = 206,value =  "k9", hash_table= _hash_table)
addInHT(key = 257,value =  "k10", hash_table= _hash_table)
addInHT(key = 179,value =  "k11", hash_table= _hash_table)


# def DHashFun(k: int, a: int, b: int):
#     global m
#     return ((a*k + b)%101)%m

# print(DHashFun(101, 1, 9))
print(printHT(_hash_table))

# Task 5

# def generate_hash_fun(x: int, a: int, b: int):
#     return ((a*x+b)%5)%3

# _hash_tables = [[Node() for _ in range(m)] for _ in range(20)]
# arr = [(9, "k1"), (282, "k2"), (270, "k3"), (112, "k4"), (263, "k5")]

# for value in arr:
#     arr_hash_fun = []
#     for a in range(1, 5):
#         for b in range(5):
#             arr_hash_fun.append(generate_hash_fun(value[0], a,b))
#     for j in range(len(arr_hash_fun)):
#         addInHT(value = value[1], hash_table=_hash_tables[j], hashcode=arr_hash_fun[j])

# arr_hash_fun = []

# for a in range(1, 5):
#     for b in range(5):
#         arr_hash_fun.append(f'(({a}*x + {b})mod 5)mod 3')

# for i, hash_table  in enumerate(_hash_tables):
#     print(f'HashFun: {arr_hash_fun[i]}\n')
#     print(printHT(hash_table))
#     print('')

# with open('task4.txt', 'w') as file:
#     info_k = ''
#     for i in arr:
#         info_k += f'{i[1]}={i[0]} |'
#     file.write(info_k)
#     info_hash_tables = f'\n'
#     for i, hash_table  in enumerate(_hash_tables):
#         info_hash_tables += f'\nHashFun: {arr_hash_fun[i]}\n'
#         info_hash_tables += printHT(hash_table)
#         file.write(info_hash_tables)



