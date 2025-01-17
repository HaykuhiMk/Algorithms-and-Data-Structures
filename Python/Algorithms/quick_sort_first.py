def quick_sort_first(arr, low, high):
    if low < high:
        pi = partition_first(arr, low, high)
        quick_sort_first(arr, low, pi - 1)
        quick_sort_first(arr, pi + 1, high)

def partition_first(arr, low, high):
    i = low + 1
    j = high
    while i <= j:
        if arr[i] <= arr[low]:
            i += 1
        elif arr[j] > arr[low]:
            j -= 1
        else:
            arr[i], arr[j] = arr[j], arr[i]
            j -= 1
            i += 1
    arr[low], arr[j]= arr[j], arr[low]
    return j
    
arr =[10, 7, 8, 9, 1, 5]
quick_sort_first(arr, 0, len(arr) - 1) 
print(arr)