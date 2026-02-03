"""
Created by: DeruckPhung
University Of Information Technology - VNUHCM
"""

import os
import time
import random
import sys

rd = random.Random(time.time_ns())

def Rand(l, r):
    return rd.randint(l, r)

# Global như C++
a = []
b = []
n = 0

# =============== QuickSort ===============
def partition_lomuto(l, r):
    # random pivot giúp giảm worst-case trên input đã sort
    pivotIndex = Rand(l, r)
    a[pivotIndex], a[r] = a[r], a[pivotIndex]

    pivot = a[r]
    i = l - 1
    for j in range(l, r):
        if a[j] <= pivot:
            i += 1
            a[i], a[j] = a[j], a[i]

    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

def quickSort(l, r):
    if l >= r:
        return
    p = partition_lomuto(l, r)
    quickSort(l, p - 1)
    quickSort(p + 1, r)

def QuickSort():
    global a
    a = b.copy()

    start = time.perf_counter()
    if n > 0:
        quickSort(0, n - 1)
    end = time.perf_counter()
    ms = (end - start) * 1000.0

    oke = 1
    for i in range(1, n):
        if a[i - 1] > a[i]:
            oke = 0
            break

    print(f"QuickSort: {oke} {int(ms)}")

# =============== HeapSort ===============
def heapify(n_, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n_ and a[left] > a[largest]:
        largest = left
    if right < n_ and a[right] > a[largest]:
        largest = right

    if largest != i:
        a[i], a[largest] = a[largest], a[i]
        heapify(n_, largest)

def heapSort(n_):
    for i in range(n_ // 2 - 1, -1, -1):
        heapify(n_, i)
    for i in range(n_ - 1, 0, -1):
        a[0], a[i] = a[i], a[0]
        heapify(i, 0)

def HeapSort():
    global a
    a = b.copy()

    start = time.perf_counter()
    heapSort(n)
    end = time.perf_counter()
    ms = (end - start) * 1000.0

    oke = 1
    for i in range(1, n):
        if a[i - 1] > a[i]:
            oke = 0
            break

    print(f"HeapSort: {oke} {int(ms)}")

# =============== MergeSort ===============
def merge_arr(l, m, r):
    n1 = m - l + 1
    n2 = r - m

    L = a[l : l + n1]
    R = a[m + 1 : m + 1 + n2]

    i = 0
    j = 0
    k = l
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        a[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        a[k] = R[j]
        j += 1
        k += 1

def mergeSort(l, r):
    if l >= r:
        return
    m = l + (r - l) // 2
    mergeSort(l, m)
    mergeSort(m + 1, r)
    merge_arr(l, m, r)

def MergeSort():
    global a
    a = b.copy()

    start = time.perf_counter()
    if n > 0:
        mergeSort(0, n - 1)
    end = time.perf_counter()
    ms = (end - start) * 1000.0

    oke = 1
    for i in range(1, n):
        if a[i - 1] > a[i]:
            oke = 0
            break

    print(f"MergeSort: {oke} {int(ms)}")

# =============== "PySort"  ===============
def PySort():
    global a
    a = b.copy()

    start = time.perf_counter()
    a.sort()
    end = time.perf_counter()
    ms = (end - start) * 1000.0

    oke = 1
    for i in range(1, n):
        if a[i - 1] > a[i]:
            oke = 0
            break

    print(f"PySort: {oke} {int(ms)}")

def token_stream(path):
    with open(path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            for tok in line.split():
                yield tok

def main():
    dir_path = "TEST"

    for entry in os.scandir(dir_path):
        if not entry.is_file():
            continue

        it = token_stream(entry.path)
        try:
            nn = int(next(it))
        except StopIteration:
            continue

        global n, a, b
        n = nn

        # đọc n số
        arr = []
        for _ in range(n):
            try:
                arr.append(float(next(it)))
            except StopIteration:
                break

        
        if len(arr) != n:
            n = len(arr)

        a = arr
        b = arr[:] 

        print(entry.path)
        QuickSort()
        HeapSort()
        MergeSort()
        PySort()
        print()

if __name__ == "__main__":
    main()

# Mỗi file sẽ có 4 dòng output theo format: 
#     <Thuật toán sort>: <Sort đúng (1) hay sai (0)> <Thời gian sort (đơn vị ms)> 

# OUTPUT:

# TEST\01_integer.inp
# QuickSort: 1 2696
# HeapSort: 1 6167
# MergeSort: 1 3601
# PySort: 1 6

# TEST\02_integer.inp
# QuickSort: 1 3432
# HeapSort: 1 7702
# MergeSort: 1 3495
# PySort: 1 6

# TEST\03_integer.inp
# QuickSort: 1 3565
# HeapSort: 1 8455
# MergeSort: 1 2810
# PySort: 1 7

# TEST\04_integer.inp
# QuickSort: 1 3437
# HeapSort: 1 7512
# MergeSort: 1 3246
# PySort: 1 11

# TEST\05_real.inp
# QuickSort: 1 5128
# HeapSort: 1 10553
# MergeSort: 1 4775
# PySort: 1 233

# TEST\06_real.inp
# QuickSort: 1 4361
# HeapSort: 1 11063
# MergeSort: 1 4852
# PySort: 1 309

# TEST\07_real.inp
# QuickSort: 1 4567
# HeapSort: 1 10227
# MergeSort: 1 4782
# PySort: 1 246

# TEST\08_real.inp
# QuickSort: 1 4675
# HeapSort: 1 10167
# MergeSort: 1 4850
# PySort: 1 435

# TEST\greater_real.inp
# QuickSort: 1 3585
# HeapSort: 1 7321
# MergeSort: 1 3376
# PySort: 1 7

# TEST\smaller_integer.inp
# QuickSort: 1 3702
# HeapSort: 1 8403
# MergeSort: 1 3706
# PySort: 1 8
