def counting_sort(arr):
    max_elm = max(arr)
    count_arr = [0] * (max_elm + 1)
    output = [0] * len(arr)
    for i in arr:
        count_arr[i] += 1

    for i in range(1, len(count_arr)):
        count_arr[i] += count_arr[i - 1]
    
    for i in reversed(arr):
        count_arr[i] -= 1
        output[count_arr[i]] = i
    
    for i in range(len(arr)):
        arr[i] = output[i]
    
