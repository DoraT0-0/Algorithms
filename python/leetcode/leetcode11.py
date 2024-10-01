height = [1,8,6,2,5,4,8,3,7]


def function(height: list):
    l = 0
    r = len(height)-1
    res = 0
    widht = len(height)-1
    while l < r:
        el = widht * min(height[l], height[r])
        if el > res:
            res = el
        if height[l] <= height[r]:
            l += 1
        else:
            r -= 1
        widht -= 1
    return res
print(function(height))
