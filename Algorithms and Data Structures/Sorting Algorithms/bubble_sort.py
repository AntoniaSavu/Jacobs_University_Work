# Worst : O(n^2)
# Average: θ(n^2)
# Best: Ω(n)

def bubble_sort(a):
    changed = 1
    while(changed):
        changed = 0
        for i in range(1, len(a)):
            if(a[i] < a[i-1]):
                changed = 1
                temp = a[i]
                a[i] = a[i-1]
                a[i-1] = temp


A = [3, 1, 2, 4, 1, 7, 5]
print(A)
bubble_sort(A)
print(A)
