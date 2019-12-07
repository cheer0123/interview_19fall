import numpy as np
def rec_opt(arr, i):
    if i == 0:
        return arr[0]
    elif i == 1:
        return max(arr[0], arr[1])
    else:
        A = rec_opt(arr, i-2) + arr[i]
        B = rec_opt(arr, i-1)
    return max(A, B)
res = rec_opt([1,2,4,1,7,8,3], 6)
print(res)


def dp_opt(arr):
    opt = np.zeros(len(arr))
    opt[0] = arr[0]
    opt[1] = max(arr[0], arr[1])
    for i in range(2, len(arr)):
        a = opt[i - 2] + arr[i]
        b = opt[i - 1]
        opt[i] = max(a, b)
    return opt[len(arr) - 1]
res = dp_opt([1,2,4,1,7,8,3])
print(res)