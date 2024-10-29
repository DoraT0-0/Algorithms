def merge(a:list, b:list):
    i, j, res = 0, 0, []
    while i < len(a) and j < len(a):
        if a[i] <= b[j]:
            res.append(a[i])
            i += 1
        else:
            res.append(b[j])
            j += 1
    res += a[i:] + b[j:]
    return res

def merge_sort(arr:list):
    n = len(arr)//2
    l,r = arr[:n], arr[n:]
    if len(l) > 1:
        l = merge_sort(l)
    if len(r) > 1:
        r= merge_sort(r)
    return merge(l, r)
