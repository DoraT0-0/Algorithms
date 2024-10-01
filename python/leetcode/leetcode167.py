numbers = [-1,-1,1,1,1,1]
target = -2

def function(numbers: list, target: int):
    num = numbers[0]
    i = 0
    while num <= target or num < 0:
        num2 = target - num
        numbers[i] = ''
        if num2 in numbers:
            return [i+1, numbers.index(num2)+1]
        i += 1
        num = numbers[i]

print(function(numbers, target))


