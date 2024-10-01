nums = [100,4,200,1,3,2]

import collections
def function(nums:list):
    hashset = set(nums)
    longest = 0
    for n in nums:
        if n-1 not in hashset:
            lenght = 0
            while n+lenght in hashset:
                lenght += 1
            longest = max(lenght, longest)
    return longest

            


print(function(nums))