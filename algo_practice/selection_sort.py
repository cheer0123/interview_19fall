def selection(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
arr = [3, 7, 4, 2, 6, 1]
selection(arr)
print(arr)

def selection_two(arr):
    n = len(arr)
    for i in range(n):
        max_index = i
        for j in range(i + 1, n):
            if arr[j] > arr[max_index]:
                max_index = j
        arr[max_index], arr[i] = arr[i], arr[max_index]
arr = [3, 7, 4, 2, 6, 1]
selection_two(arr)
print(arr)