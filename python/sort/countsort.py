def count_sort(arr:list, max_el = None):
    if max_el == None: max_el = max(arr)
    count = [0 for _ in range(0, max_el+1)]
    for i in arr:
        count[i] += 1;
    j = 0
    for i in range(max_el+1):
        while count[i] > 0:
            arr[j] = i
            j += 1
            count[i] -= 1 
    return arr


print(count_sort([2, 3 ,1 , 1, 0], 3))

