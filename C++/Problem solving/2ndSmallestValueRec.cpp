#include <iostream>
#include <climits>

int secSmallVal(int*, int, int, int);

int main()
{
    const int size = 6;
    int arr[size];
    std::cout << "Input data: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    int sml1 = INT_MAX;  
    int sml2 = INT_MAX; 
    int res = secSmallVal(arr, size, sml1, sml2);
    std::cout << "Result = " << res << std::endl;
}

int secSmallVal(int* arr, int size, int sml1, int sml2)
{
    if (size == 0)
    {
        return sml2;
    }
    if (arr[0] < sml1)
    {
        sml2 = sml1;
        sml1 = arr[0];
    }
    else if (arr[0] < sml2 && arr[0] != sml1)
    {
        sml2 = arr[0];
    }
    return secSmallVal(arr + 1, size - 1, sml1, sml2);
}
