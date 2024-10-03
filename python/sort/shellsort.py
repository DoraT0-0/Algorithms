def shellsort(arr:list):
    step = len(arr)//2
    while step > 0:
        for i in range(step, len(arr)):
            curr = arr[i]
            j = i
            while j >= step and curr < arr[j-step]:
                arr[j] = arr[j-step]
                j -= step
            arr[j] = curr
        step //= 2
    return arr

l = [1, 6, 0, -4, 3]
print(shellsort(l))