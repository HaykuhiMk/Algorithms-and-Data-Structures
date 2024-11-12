#include <iostream>

void insertionSort(int*, int);

int main()
{
    const int size = 6;
    int arr[size];
    std::cout << "Input data: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    insertionSort(arr, size);
    std::cout << "Output data: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSort(int* arr, int size)
{
    int j;
    int key;
    for (int i = 1; i < size; ++i)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1; 
        }
        arr[j + 1] = key;
    }
}
