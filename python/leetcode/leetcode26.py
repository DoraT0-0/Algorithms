nums = [1,1]

num = nums[0]
counter = 0
for i in range(1, len(nums)):
    if num == nums[i]:
        counter += 1
        nums[i] = None
    else:
        num = nums[i]

for i in range(counter):
    nums.remove(None)

l = len(nums)

for i in range(counter):
    nums.append('_')

print(l,', nums = ', nums)
