def insert_sort(arr:list):
    for i in range(1, len(arr)):
        x = arr[i]
        j = i
        while j > 0 and x < arr[j-1]:
            arr[j] = arr[j-1]
            j -= 1
        arr[j] = x
    return arr 
# arr = [1, 4, 5, 3 ,2]
# print(insert_sort(arr))