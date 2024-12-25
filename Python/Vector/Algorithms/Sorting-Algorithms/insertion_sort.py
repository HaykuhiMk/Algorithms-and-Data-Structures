"""
This module implements the insertion sort algorithm.
"""

def insertion_sort(arr: list):
    """Insertion sort algorithm"""
    for i in range(len(arr)):
        tmp = arr[i]
        j = i - 1
        while j >= 0 and tmp <= arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = tmp
