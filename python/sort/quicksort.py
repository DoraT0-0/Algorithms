def quicksort(arr:list):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    left = []
    mid = []
    right = []
    for i in range(len(arr)):
        if arr[i] < pivot:
            left.append(arr[i])
        elif arr[i] > pivot:
            right.append(arr[i])
        else:
            mid.append(arr[i])
    return quicksort(left) + mid + quicksort(right)

