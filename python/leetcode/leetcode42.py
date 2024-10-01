height = [0,1,0,2,1,0,1,3,2,1,2,1]


def function(height:list):
    l, r =0,  len(height)-1
    maxLeft, maxRight = height[l], height[r]
    res = 0
    while l < r:
        if maxLeft <= maxRight:
            l += 1
            if maxLeft-height[l] > 0:
                res += maxLeft-height[l]
            else:
                maxLeft = height[l]
        else:
            r -= 1
            if maxRight-height[r] > 0:
                res += maxRight-height[r]
            else:
                maxRight = height[r]
    return res

print(function(height))