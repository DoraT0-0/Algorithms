import time
from sort.insertsort import insert_sort
from sort.mergeSort import merge_sort
from sort.heapsort import heap_sort
from sort.quicksort import quicksort

arr = []
path = r'C:\VisualStudioCode\CodeGitHub\python\txt\el100_000_otsr_ob.txt'
l = 100_000
with open(path, 'r') as file:
    for i in range(l):
        arr.append(int(file.readline()))

start = time.time()
insert_sort(arr)
end = time.time()
print("Result: " + str((end-start)*1000))

