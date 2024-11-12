def radix_sort(arr: list):
    max_d = max([len(str(x)) for x in arr])
    b = 10
    bins = [[] for _ in range(b)]

    for i in range(max_d):
        for num in arr:
            di = (num//10**i)%10
            bins[di].append(num)
        arr = [x for q in bins for x in q]
        bins = [[] for _ in range(b)]
    return arr

arr = [76, 213, 33, 8, 324, 34]

print(radix_sort(arr))
