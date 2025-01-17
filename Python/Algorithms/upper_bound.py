def  upper_bound(arr, value):
    start, end = 0, len(arr) - 1
    while start < end:
        mid = start + (end - start) // 2
        if arr[mid] <= value:
            start = mid + 1
        else:
            end = mid
    return start

arr = [1, 3, 3, 5, 7, 9]
value = 3
result = upper_bound(arr, value)
print(f"Lower bound of {value} in {arr} is at index {result}")