from insertsort import insert_sort

def bucket_sort(arr: list):
    n = len(arr)
    buckets = [[] for _ in range(n)]

    for num in arr:
        b = int(num // n)
        if b < len(arr):
            buckets[b].append(num)
        else:
            buckets[n-1].append(num)
    print(buckets)
    for bucket in buckets:
        insert_sort(bucket)
    i = 0
    for bucket in buckets:
        for num in bucket:
            arr[i] = num
            i += 1
    return arr

arr = [15, 9, 2, 3, 67]

print(bucket_sort(arr))