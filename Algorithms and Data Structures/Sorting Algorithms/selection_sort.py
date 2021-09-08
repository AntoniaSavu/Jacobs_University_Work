# Worst : O(n^2)
# Average: θ(n^2)
# Best: Ω(n^2)

def selection_sort(a):
    n = len(a)
    for i in range(0, n):
        for j in range(i+1, n):
            if(a[i] > a[j]):
                temp = a[i]
                a[i] = a[j]
                a[j] = temp


A = [3, 1, 2, 4, 1, 7, 5]
print(A)
selection_sort(A)
print(A)
