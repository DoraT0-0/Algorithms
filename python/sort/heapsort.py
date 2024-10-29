def heapfy(arr:list, n: int, i: int):
    langest = i
    l, r = 2*i+1, 2*i+2
    if l < n and arr[langest] < arr[l]:
        langest = l
    if r < n and arr[langest] < arr[r]:
        langest = r
    if langest != i:
        arr[i], arr[langest] = arr[langest], arr[i]
        heapfy(arr, n, langest)

def build_max_heap(arr:list):
    n = int((len(arr)//2)-1)
    for i in range(n, -1, -1):
        heapfy(arr, len(arr), i)

def heap_sort(arr:list):
    n = len(arr)
    build_max_heap(arr)
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapfy(arr, i, 0)

def delete_max_heap(arr:list, i:int):
    langest, n = i, len(arr)
    l, r = 2*i+1, 2*i+2
    if l < n and r < n and arr[l] < arr[r]:
        langest = r
    if l < n and r < n and arr[l] > arr[r]:
        langest = l
    if langest != i:
        arr[i] = arr[langest]
        delete_max_heap(arr, langest)
    else:
        arr[i] = 0

