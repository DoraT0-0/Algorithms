# class Tree():
#     def __init__(self, data) -> None:
#         self.data = data
#         self.left = None
#         self.right = None
    
#     def insert(self, data):
#         if self.data:
#             if data < self.data:
#                 if self.left is None:
#                     self.left = Tree(data)
#                 else:
#                     self.left.insert(data)
#             elif data > self.data:
#                 if self.right is None:
#                     self.right = Tree(data)
#                 else:
#                     self.right.insert(data)
#         else:
#             self.data = data
    
#     def PrintTree(self):
#         if self.left:
#             self.left.PrintTree()
#         print(self.data)
#         if self.right:
#             self.right.PrintTree()

#     def search(self, value):
#         if value == self.data:
#             print(self.data)
#         elif value < self.data:
#             if self.left is None:
#                 print('Такого элемента нет')
#             else:
#                 self.left.search(value)
#         else:
#             if self.right is None:
#                 print('Такого элемента нет')
#             else:
#                 self.right.search(value)

# root = Tree(52)

# root.insert(42)
# root.insert(62)
# root.insert(32)
# root.PrintTree()
# root.search(32)

# class Funtion():
#     def __init__(self) -> None:
#         pass
#     def Duplicate(self, m: list):
#         for i in range(len(m)):
#             for j in range(len(m)):
#                 if i != j:
#                     if(m[i] == m[j]):
#                         return True
#         return False
    
#     def FindLargest(self, m:list):
#         largest = m[0]
#         for i in range(1, len(m)):
#             if(m[i] > largest):
#                 largest = m[i]
#         return largest
    


# m = [1, 2, 3, 4, 2, 1]

# f = Funtion()

#print(f.Duplicate(m), '\n', f.FindLargest(m))

# def fact(n):
#     if n == 1:
#         return n
#     return n * fact(n-1)

# i = 220752000000000

# for j in range(1, i):
#     h = fact(j)
#     if h >= i:
#         print(h, j)
#         break 

# import math

# def FindFactors(num: int):
#     factors = []
#     while(num % 2 == 0):
#         factors.append(2)
#         num = num/2
#     i = 3
#     max_factor = math.sqrt(num)
#     while(i <= max_factor):
#         while(num % i == 0):
#             factors.append(i)
#             num = num / i
#             max_factor = math.sqrt(num)
#         i += 2
#     if(num>1):
#         factors.append(num)
#     return factors

# def FindPrimes(num: int):
#     is_composite = []

#     for i in range(num):
#         is_composite.insert(i, False)

#     for i in range(4, num, 2):
#         is_composite[i] = True
    
#     next_prime = 3
#     stop_at = math.sqrt(num)
#     while(next_prime <= stop_at):
#         for i in range(next_prime*2, num, next_prime):
#             is_composite[i] = True
        
#         next_prime = next_prime+2
#         while(next_prime<=num and is_composite[next_prime]):
#             next_prime += 2 

#     primes = []
#     for i in range(num):
#         if(is_composite[i] == False):
#             primes.append(i)
#     return primes


# def CheckPrimes(num: int):
#     if (2^(num-1)) % num == 1:
#         return True
#     else:
#         return False

# def CoinBone(a : int, b: int, m: int):
#     _min = 1
#     _max = 6
#     x = 0
#     x = (a*x+b)%m
#     while x != 0:
#         x = (a*x+b)%m
#         res = _min+x%(_max-_min+1)
#         if res <= 3:
#             print("орёл")
#         else:
#             print("решка")

# def PickM(array: list, m: int):
#     max_i = len(array)-1
#     for i in range(m):
#         j = i+i%(max_i-i+1)
#         array[i] = array[j]
#     return array

# print(PickM([1, 2, 3, 4, 5], 3)) 


