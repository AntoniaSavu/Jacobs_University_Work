def bucketSort(array):
    bucket = []
    for i in range(0, len(array)):
        bucket.append([])
    for j in range(0, len(array)):
        index_b = int(len(array) * array[j])
        bucket[index_b].append(array[j])

    for i in range(len(array)):
        bucket[i] = sorted(bucket[i])

    k = 0
    for i in range(len(array)):
        for j in range(len(bucket[i])):
            array[k] = bucket[i][j]
            k += 1


array = [0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1]
bucketSort(array)
print(array)
