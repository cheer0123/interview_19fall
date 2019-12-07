def partition(arr, low, high):
    i = low - 1
    print("i: ", i)
    pivot = arr[high]
    print("pivot: ", pivot)
    
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1 
            arr[i],arr[j] = arr[j],arr[i] 
    arr[i+1],arr[high] = arr[high],arr[i+1] 
    return i+1 

def quickSort(arr,low,high): 
    print("start: ", arr)
    if low < high: 
        pi = partition(arr,low,high)
        print("pi", pi)
  
        quickSort(arr, low, pi-1) 
        print("1: ", arr)
        quickSort(arr, pi+1, high)
        print("2: ", arr) 
    
arr = [3,5,2,4,6] 
n = len(arr) 
quickSort(arr, 0, n-1)  
print(arr)


    