
def merge_sort(arr):
    print("**")
    print(arr)
    if len(arr) > 1:
        middle = len(arr)// 2
        l = arr[: middle]
        r = arr[middle:]
    
        merge_sort(l)
        merge_sort(r)

        i = j = k = 0
        while i < len(l) and j < len(r):
            print("#")
            print(arr)
            if l[i] < r[j]:
                arr[k] = l[i] 
                i += 1
            else:
                arr[k] = r[j]
                j += 1
            k += 1
        
        while i < len(l):
            arr[k] = l[i] 
            i += 1
            k += 1
        while j < len(r):
            arr[k] = r[j] 
            j += 1
            k += 1
            
# arr = [3, 6, 4, 32, 99, 1, 2, 7]
arr = [2, 3, 1, 4, 5, 6, 10, 9, 8, 7]
merge_sort(arr)
print(arr)
