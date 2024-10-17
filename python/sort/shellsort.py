def shellsort(arr:list):
    step = len(arr)//2
    while step > 0:
        for i in range(step, len(arr)):
            x = arr[i]
            j = i
            while j >= step and x < arr[j-step]:
                arr[j] = arr[j-step]
                j -= step
            arr[j] = x
        step //= 2
    return arr
l = [1, 6, 0, -4, 3]
print(shellsort(l))


