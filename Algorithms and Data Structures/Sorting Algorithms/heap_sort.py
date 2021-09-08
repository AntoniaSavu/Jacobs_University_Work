# Worst : O(nlogn)
# Average: θ(nlogn)
# Best: Ω(nlogn)
# Heap Sort in python

def heapify(arr, n, i):
    # Find largest among root and children
    largest = i  # i is root
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    # If root is not largest, swap with largest and continue heapifying
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heapSort(arr):
    n = len(arr)

    # Build max heap
    for i in range(n//2-1, -1, -1):
        # n//2-1 sort of like the last non-leaf, to build maxheap from bottom up

        heapify(arr, n, i)

    for i in range(n-1, 0, -1):
        # Swap
        arr[i], arr[0] = arr[0], arr[i]

        # Heapify root element
        heapify(arr, i, 0)
        # prin chemarea lui de la i se omite ultimul element , care e deja sortat


arr = [4, 10, 3, 5, 1]
heapSort(arr)
n = len(arr)
print("Sorted array is")
for i in range(n):
    print("%d " % arr[i], end='')
