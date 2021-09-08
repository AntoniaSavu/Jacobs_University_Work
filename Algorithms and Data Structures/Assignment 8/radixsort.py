import numpy as np


def bucketSort(array, pow):
    if(pow == 0):
        return
    else:
        bucket = []
        for i in range(0, 10):
            bucket.append([])
        for j in range(0, len(array)):
            aux = int(array[j]/pow)
            index_b = int(aux % 10)
            bucket[index_b].append(array[j])
        for i in range(0, 10):
            if(len(bucket[i]) > 1):
                bucketSort(bucket[i], pow/10)
        for i in range(len(array)):
            bucket[i] = sorted(bucket[i])

        k = 0
        for i in range(len(array)):
            for j in range(len(bucket[i])):
                array[k] = bucket[i][j]
                k += 1


def radixSort(array):
    max_value = np.amax(array)
    pow = 1
    while(max_value/pow > 10):
        pow *= 10
    bucketSort(array, pow)


array = [9, 1, 6, 7, 6, 2, 1]
radixSort(array)
print(array)
