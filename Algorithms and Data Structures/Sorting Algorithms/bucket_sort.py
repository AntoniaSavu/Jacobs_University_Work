# Worst : O(n^2)
# Average: θ(n+k)
# Best: Ω(n+k)
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while(j >= 0 and arr[j] > key):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr


def bucket_sort(a):
    bucket = []
    n = len(a)
    for i in range(n):
        bucket.append([])
    for j in a:
        index = int(n*j)
        bucket[index].append(j)
    for i in range(n):
        bucket[i] = insertion_sort(bucket[i])
    k = 0
    for i in range(n):
        for j in range(len(bucket[i])):
            a[k] = bucket[i][j]
            k += 1
    return a


A = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]
B = [3, 4, 1, 2, 7, 6, 5]
# print(A)
print(bucket_sort(A))
# print(A)
