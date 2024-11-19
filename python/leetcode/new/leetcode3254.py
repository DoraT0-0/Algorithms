nums = [1, 3, 4]
k = 2
res = []
for i in range(len(nums)+1-k):
    arr = []
    for j in range(i, i+k):
        arr.append(nums[j])
    for j in range(k-1):
        if arr[j] < arr[j+1] and arr[j+1] - arr[j] == 1:
            if j == k-2:
                res.append(arr[j+1])
            continue
        else:
            res.append(-1)
            break
print(res)