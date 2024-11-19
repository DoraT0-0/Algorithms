def merge(nums1: list, nums2: list):
    i, j, res = 0, 0, []
    while i < len(nums1) and j < len(nums2):
        if nums1[i] <= nums2[j]:
            res.append(nums1[i])
            i += 1
        else:
            res.append(nums2[j])
            j += 1
    res += nums1[i:] + nums2[j:]
    return res
nums1 = [234, 4]
nums2 = []

def fun(nums1, nums2):
    if len(nums1) == 0 and len(nums2) == 0:
        return 0
    res = merge(nums1, nums2)

    if len(res)%2 != 0:
        return res[len(res)//2]
    else:
        return (res[len(res)//2-1] + res[(len(res)//2)])/2

print(fun(nums1, nums2))