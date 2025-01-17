def quick_sort_middle(arr, low, high):
    if low < high:
        pi = partition_middle(arr, low, high)
        quick_sort_middle(arr, low, pi - 1)
        quick_sort_middle(arr, pi + 1, high)

def partition_middle(arr, low, high):
    mid = low + (high - low) // 2
    arr[mid], arr[high] = arr[high], arr[mid]
    return partition_last(arr, low, high)


def partition_last(arr, low, high):
    pi = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pi:
            i += 1
            arr[i], arr[high] = arr[high], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1