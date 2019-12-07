def insert(arr):
    n = len(arr)
    for i in range(1, n):
        for j in range(i - 1, -1, -1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
            else:
                break
arr = [3, 7, 4, 2, 6, 1]
insert(arr)
print(arr)


def insert_two(arr):
    n = len(arr)
    for i in range(1, n):
        j = i - 1
        while j >= 0 and arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]
            j -= 1

arr = [3, 7, 4, 2, 6, 1]
insert_two(arr)
print(arr)