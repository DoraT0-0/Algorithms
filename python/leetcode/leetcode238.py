nums = [1,2,3,4]
def function(nums: list):
    product = []
    prefix = []
    postfix = []
    for i in range(len(nums)):
        if i == 0:
            prefix.append(nums[i]*1)
        else:
            prefix.append(nums[i]*prefix[i-1])
    for i in range(len(nums)-1, -1, -1):
        if i == len(nums)-1:
            postfix.append(nums[i]*1)
        else:
            postfix.append(nums[i]*postfix[-1])
    postfix.reverse()
    
    for i in range(len(nums)):
        if i == 0:
            product.append(postfix[i+1])
        elif i == len(nums)-1:
            product.append(prefix[i-1])
        else:
            product.append(postfix[i+1]*prefix[i-1])
    return product


print(function(nums))