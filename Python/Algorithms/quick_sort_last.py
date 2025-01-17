def quick_sort_last(arr, low, high):
    if low < high:
        pi = partition_last(arr, low, high)
        quick_sort_last(arr, low, pi - 1)
        quick_sort_last(arr, pi + 1, high)

def partition_last(arr, low, high):
    pi = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pi:
            i += 1
            arr[i], arr[high] = arr[high], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1