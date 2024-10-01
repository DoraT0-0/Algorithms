nums = [1,1,1,2,2,4,4,4,4]
k = 2


def function(nums: list, k: int):
    res = []
    counter = 0
    counters = []
    nums_ = []
    nums.sort()
    nums.append('!')

    for i in range(len(nums)-1):
        counter += 1
        if i == len(nums):
            nums_.append(nums[i])
            counters.append(counter)
            counter = 0
        elif nums[i] != nums[i+1]:
            nums_.append(nums[i])
            counters.append(counter)
            counter = 0

    while k != 0:
        k -= 1
        index_max = counters.index(max(counters))
        res.append(nums_[index_max])
        nums_.remove(nums_[index_max])
        counters.remove(counters[index_max])
    return res