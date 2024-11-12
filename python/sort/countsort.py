def count_sort(arr:list, max_el = None):
    count_arr = [0 for i in range(max_el+1)]
    for el in arr:
        count_arr[el] += 1
    j = 0
    for i in range(max_el+1):
        while count_arr[i] > 0:
            arr[j] = i
            count_arr[i] -= 1
            j += 1
    return arr
print(count_sort([2, 3 ,1 , 1, 0], 3))

