def quicksort(arr:list):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    left, mid, right = [], [], []
    for i in arr:
        if i < pivot: left.append(i)
        elif i > pivot: right.append(i)
        else: mid.append(i)
    return quicksort(left) + mid + quicksort(right)

arr = [324, 654, 1, 3 ,0, 4]

print(quicksort(arr))

