# Worst : O(n^2)
# Average: θ(nlogn)
# Best: Ω(nlogn)
# Last element as pivot
def partition_last(arr, low, high):
    i = (low-1)
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] <= pivot:
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)


'''def partition_first(arr, low, high):
    pivot = arr[low]
    i = low
    j = high

    while(i <= j):
        while arr[i] <= pivot:
            i = i+1
        while arr[j] > pivot:
            j -= 1
        if(i <= j):
            i, j = j, i
            i += 1
            j -= 1
    # arr[low], arr[j] = arr[j], arr[low]
    return j'''


def first_partition(a,  left,  right):
    pivot_index = left
    pivot = a[pivot_index]
    start = left
    end = right
    while start <= end:
        while start < len(a) and a[start] <= pivot:
            start += 1
        while a[end] > pivot:
            end -= 1
        if(start <= end):
            a[start], a[end] = a[end], a[start]

    a[end], a[pivot_index] = a[pivot_index], a[end]
    return end


def quick_sort(a, low, high):
    if len(a) == 1:
        return a
    if low < high:
        p = first_partition(a, low, high)
        quick_sort(a, low, p-1)
        quick_sort(a, p+1, high)


def recursiveQuickSort(a,  i, j):
    idx = first_partition(a, i, j)
    if(i < idx-1):
        recursiveQuickSort(a, i, idx-1)
    if(j > idx):
        recursiveQuickSort(a, idx, j)


A = [3, 1, 2, 4, 1, 7, 5]
print(A)
quick_sort(A, 0, 6)
print(A)
