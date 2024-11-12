#include <iostream>

int rangeSum(int end, int* arr);
int getMaxPrefixSum(int* arr, int size);

int main() {
    const int size = 7;
    int arr[size] = {3, 4, -1, 2, 1, -5, 4}; 
    int maxPrefixSum = getMaxPrefixSum(arr, size);
    std::cout << "Maximum prefix sum is " << maxPrefixSum << std::endl;
    return 0;
}

int rangeSum(int end, int* arr) {
    int sum = 0;
    for (int i = 0; i < end; ++i) {
        sum += arr[i];
    }
    return sum;
}

int getMaxPrefixSum(int* arr, int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        int currSum = rangeSum(i, arr);
        if (result < currSum) {
            result = currSum;
        }
    }
    return result;
}
