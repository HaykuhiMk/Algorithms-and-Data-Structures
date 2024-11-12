#include <iostream>

int largestValue(int*, int);

int main()
{
    const int size = 6;
    int arr[size];
    std::cout << "Input data: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    int maxVal = largestValue(arr, size);
    std::cout << "Max value = " << maxVal << std::endl;
}

int largestValue(int* arr, int size)
{
    if (size == 1)
    {
        return arr[0];
    }
    int max = largestValue(arr + 1, size - 1);
    return (arr[0] > max) ? arr[0] : max;
}
