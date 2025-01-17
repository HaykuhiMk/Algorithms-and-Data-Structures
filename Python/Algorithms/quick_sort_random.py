import random

def quick_sort_random(arr, low, high):
    if low < high:
        pi = partition_random(arr, low, high)
        quick_sort_random(arr, low, pi - 1)
        quick_sort_random(arr, pi + 1, high)

def partition_random(arr, low, high):
    random_index = random.randint(low, high)
    arr[random_index], arr[high] = arr[high], arr[random_index]
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