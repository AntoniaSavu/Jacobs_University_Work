# Worst : O(n+k)
# Average: θ(n+k)
# Best: Ω(n+k)

def counting_sort(a):
    max_value = max(a)

    count_vector = []
    n = len(a)
    output = [0]*n
    for i in range(max_value+1):
        count_vector.append(0)
    for i in range(0, n):
        count_vector[a[i]] += 1
    for i in range(1, max_value+1):
        count_vector[i] += count_vector[i-1]
    i = n-1
    while(i >= 0):
        output[count_vector[a[i]]-1] = a[i]
        count_vector[a[i]] -= 1
        i -= 1
    for i in range(0, n):
        a[i] = output[i]
    return a


A = [1, 4, 1, 2, 7, 5, 2]
print(A)
print(counting_sort(A))
