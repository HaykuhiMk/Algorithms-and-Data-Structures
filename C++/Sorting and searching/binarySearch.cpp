#include <iostream>

int binarySearch(int*, int, int, int);

int main()
{
    const int size = 6;
    int arr[size] = {2, 5, 13, 22, 36, 55};
    int first = 0;
    int key = 5;
    int res = binarySearch(arr, first, size, key);
    std::cout << "Result = " << res << std::endl;
}

int binarySearch(int* arr, int first, int last, int key)
{
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            last = mid - 1;
        }
        else if (key > arr[mid])
        {
            first = mid + 1;
        }
    }
    return -1;
}