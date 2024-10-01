nums = [2, 3 ,6 ,7]
target = 9

def function(nums: list, target: int):
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i]+nums[j] == target:
                return [i, j]
    return []
print(function(nums, target))