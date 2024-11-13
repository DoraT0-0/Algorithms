nums = [0,1,7,4,4,5]
nums.sort()
lower = 3
upper = 6

def binary_search(l, r, target):
    while l <= r:
        m = (l+r) // 2
        if nums[m] >= target:
            r = m - 1
        else:
            l = m + 1
    return r
res = 0
for i in range(len(nums)):
    el_low = lower - nums[i]
    el_up = upper - nums[i]
    res += (binary_search(i+1, len(nums)-1,el_up+1) - binary_search(i+1, len(nums)-1,el_low))
print(res)