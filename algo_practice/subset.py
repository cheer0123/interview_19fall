def rec_subset(arr, i, s):
    if s == 0:
        return True
    elif i == 0:
        return arr[0] == s
    elif arr[i] > s:
        return rec_subset(arr, i-1, s)
    else:
        a = rec_subset(arr, i-1 , s-arr[i])
        b = rec_subset(arr, i-1, s)
        return a or b
arr = [3, 34, 4, 12, 5, 2]
i = len(arr) - 1
res = rec_subset(arr,i, 9)
print(res)