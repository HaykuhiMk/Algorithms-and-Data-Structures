#include <iostream>

int binSearchRec(int* arr, int first, int last, int key);

int main()
{
    const int size = 6;
    int arr[size] = {2, 5, 13, 22, 36, 55};
    int first = 0;
    int key = 13;
    int res = binSearchRec(arr, first, size, key);
    std::cout << "Result = " << res << std::endl;
}

int binSearchRec(int* arr, int first, int last, int key)
{
    if (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binSearchRec(arr, first, mid - 1, key);
        }
        else if (arr[mid] < key)
        {
            return binSearchRec(arr, mid + 1, last, key);
        }
    }
    return -1;
}
