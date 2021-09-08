# Worst : O(nk)
# Average: θ(nk)
# Best: Ω(nk)
def counting_sort(a, digits):
    max_value = max(a)

    count_vector = []
    n = len(a)
    output = [0]*n
    for i in range(max_value+1):
        count_vector.append(0)

    for i in range(0, n):
        index = a[i]//digits
        count_vector[index % 10] += 1
    for i in range(1, max_value):
        count_vector[i] += count_vector[i-1]
    i = n-1
    while(i >= 0):
        index = a[i]//digits
        output[count_vector[index % 10]-1] = a[i]
        count_vector[index % 10] -= 1
        i -= 1
    for i in range(n):
        a[i] = output[i]
    return a


def radix_sort(a):
    max_value = max(a)
    digits = 1
    while(max_value // digits > 0):
        counting_sort(a, digits)
        digits *= 10
    return a


A = [121, 432, 564, 23, 1, 45, 788]
print(radix_sort(A))

