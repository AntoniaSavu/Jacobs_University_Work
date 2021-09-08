import array as arr
import numpy as np


def counting_sort(array):
    rangee = np.amax(array)
    rangee += 1
    size = len(array)
    aux = [0] * rangee
    output = [0] * size
    for i in range(0, size):
        aux[array[i]] += 1
    for i in range(1, len(aux)):
        aux[i] += aux[i-1]

    i = size-1
    while i >= 0:
        output[aux[array[i]] - 1] = array[i]
        aux[array[i]] -= 1
        i -= 1
    for i in range(0, len(output)):
        array[i] = output[i]
    print(array)


vector = [9, 1, 6, 7, 6, 2, 1]
counting_sort(vector)
