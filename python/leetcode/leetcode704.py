nums = [-1,0,3,5,9,12]
target = 13

def binary_search(arr, low, high, x):
    if high >= low and x in arr:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)
    else:
        return -1

print(binary_search(nums, 0, len(nums), target))
