import random
r = random

a = 100_000
with open(r'python\txt\el100_000_otsr.txt', 'w') as file:
    # while a > 0:
    #     file.write( str(r.randint(1, 1000)) + '\n')
    #     a -= 1
    for i in range(1, a+1):
        file.write(str(i) + '\n')


