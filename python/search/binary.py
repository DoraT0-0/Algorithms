def binary_search(arr, low, high, target):
    if low <= high:
        mid = (high+low)//2
        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            return binary_search(arr, mid+1, high, target)
        else:
            return binary_search(arr, low, mid-1, target)
    else:
        return -1

nums = [-1,0,3,5,9,12]
target = 9

print(binary_search(nums, 0, len(nums), target))