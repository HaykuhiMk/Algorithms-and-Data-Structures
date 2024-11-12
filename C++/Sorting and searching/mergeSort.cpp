#include <iostream>

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int main()
{
    const int size = 7;
    int arr[size];
    std::cout << "Input data: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    mergeSort(arr, 0, size);
    std::cout << "Output data: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int* arr, int start, int mid, int end)
{
    int first1 = start;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = end;
    int index = 0;
    int tmpArr[end]; 
    while (first1 <= last1 && first2 <= last2)
    {
        if (arr[first1] <= arr[first2])
        {
            tmpArr[index++] = arr[first1++];
        }
        else
        {
            tmpArr[index++] = arr[first2++];
        }
    }
    while (first1 <= last1)
    {
        tmpArr[index++] = arr[first1++];
    }
    while (first2 <= last2)
    {
        tmpArr[index++] = arr[first2++];
    }
    for (int i = start; i <= end; ++i)
    {
        arr[i] = tmpArr[i - start];
    }
}

void mergeSort(int* arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}