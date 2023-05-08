#include <iostream>

void bubbleSort(int*, int);

int main()
{
    const int size = 7;
    int arr[size];
    std::cout << "Input data: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    bubbleSort(arr, size);
    std::cout << "Output data: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}