import timeit
import time
from datetime import timedelta
import numpy as np
import sys
from numpy.matrixlib.defmatrix import matrix


def naive_recursion_fibo(n):
    if n < 2:
        return n
    else:
        return naive_recursion_fibo(n-1)+naive_recursion_fibo(n-2)


def bottom_up_fibo(n):
    fibo1, fibo2 = 1, 1
    if n <= 2:
        return 1
    else:
        for i in range(3, n+1, 1):
            fibon = fibo2+fibo1
            fibo1 = fibo2
            fibo2 = fibon
        return fibon


g = (1 + 5**.5) / 2  # Golden ratio.


def closed_form_fibo(N):
    return int((g**N - (1-g)**N) / 5**.5)


def matrix_fibo(n):
    matrix = np.array([[1, 1], [1, 0]])
    fibo_matrix = matrix.dot(matrix)
    for i in range(2, n):
        fibo_matrix = fibo_matrix.dot(matrix)
    return fibo_matrix[0][1]


def start_time_measure(message=None):
    if message:
        print(message)
    return time.monotonic()


def end_time_measure(start_time, print_prefix=None):
    end_time = time.monotonic()
    if print_prefix:
        print(print_prefix + str(timedelta(seconds=end_time - start_time)))
    return end_time


original_stdout = sys.stdout
with open('naive.txt', 'w') as f:
    sys.stdout = f
    n = 0
    start = timeit.default_timer()
    naive_recursion_fibo(n)
    stop = timeit.default_timer()
    execution_time = stop - start
    print(n, str(execution_time))
    n += 10

    while execution_time < 2:
        print(n, str(execution_time))
        start = timeit.default_timer()
        naive_recursion_fibo(n)
        stop = timeit.default_timer()
        execution_time = stop - start
        # It returns time in seconds
        n += 10
    sys.stdout = original_stdout


with open('bottomup.txt', 'w') as f:
    sys.stdout = f
    n = 0
    start = timeit.default_timer()
    bottom_up_fibo(n)
    stop = timeit.default_timer()
    execution_time = stop - start
    print(n, str(execution_time))
    n += 10

    while execution_time < 2:
        print(n, str(execution_time))
        start = timeit.default_timer()
        bottom_up_fibo(n)
        stop = timeit.default_timer()
        execution_time = stop - start
        # It returns time in seconds
        n += 10
    sys.stdout = original_stdout


with open('closed.txt', 'w') as f:
    sys.stdout = f
    n = 0
    start = timeit.default_timer()
    closed_form_fibo(n)
    stop = timeit.default_timer()
    execution_time = stop - start
    print(n, str(execution_time))
    n += 10

    while execution_time < 2:
        print(n, str(execution_time))
        start = timeit.default_timer()
        closed_form_fibo(n)
        stop = timeit.default_timer()
        execution_time = stop - start
        # It returns time in seconds
        n += 10
    sys.stdout = original_stdout


with open('matrix.txt', 'w') as f:
    sys.stdout = f
    n = 0
    start = timeit.default_timer()
    matrix_fibo(n)
    stop = timeit.default_timer()
    execution_time = stop - start
    print(n, str(execution_time))
    n += 10

    while execution_time < 2:
        print(n, str(execution_time))
        start = timeit.default_timer()
        matrix_fibo(n)
        stop = timeit.default_timer()
        execution_time = stop - start
        # It returns time in seconds
        n += 10
    sys.stdout = original_stdout
