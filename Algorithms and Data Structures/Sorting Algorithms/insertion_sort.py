# Worst : O(n^2)
# Average: θ(n^2)
# Best: Ω(n)

def insertion_sort(arr, n):
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while(j >= 0 and arr[j] > key):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    print(arr)


A = [3, 1, 2, 4, 1, 7, 5]
print(A)
insertion_sort(A, 7)
