def radix_sort(arr: list):
    max_d = max([len(str(x)) for x in arr])
    b = 10
    bins = [[] for _ in range(b)]

    for i in range(0, max_d):
        for x in arr:
            digit = (x // b**i)%b
            bins[digit].append(x)
        arr = [x for q in bins for x in q]
        bins = [[] for _ in range(b)]
    
    return arr

arr = [76, 213, 33, 8, 324, 34]

print(radix_sort(arr))