def bubblesort(arr:list):
    for i in range(len(arr)):
        for j in range(len(arr)-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
l = [1, 20, 4, -3, 0]

print(bubblesort(l))