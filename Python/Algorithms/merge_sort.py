def merge_sort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

def merge(arr, left, mid, right):
    i, j = left, mid + 1
    res = []
    while i <= mid and j <= right:
        if arr[i] < arr[j]:
            res.append(arr[i])
            i += 1
        else: 
            res.append(arr[j])
            j += 1
    res.extend(arr[i : mid + 1])
    res.extend(arr[j : right + 1])
    for k in range(len(res)):
        arr[left + k] = res[k] 
