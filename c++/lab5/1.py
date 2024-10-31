def Count_El_del_5_and_2(arr):
    count = 0
    for num in arr:
        if num % 2 == 0 and num % 5 == 0:
            count += 1
    return count

arr = []
while True:
    n = int(input("Введите целое число: "))
    if n == 0: break
    arr.append(n)
print("Кол-во чётных элементов кратных 5: ", Count_El_del_5_and_2(arr))