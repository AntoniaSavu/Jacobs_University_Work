# Worst : O(n logn)
# Average: θ(n logn)
# Best: Ω(n log n)

def merge_sort(a):
    if(len(a) > 1):
        middle = len(a)//2
        left = a[:middle]
        right = a[middle:]
        merge_sort(left)
        merge_sort(right)
        i = j = k = 0
        while(i < len(left) and j < len(right)):
            if(left[i] < right[j]):
                a[k] = left[i]
                i += 1
                k += 1
            else:
                a[k] = right[j]
                j += 1
                k += 1
        while i < len(left):
            a[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            a[k] = right[j]
            j += 1
            k += 1


A = [3, 1, 2, 4, 1, 7, 5]
print(A)
merge_sort(A)
print(A)
