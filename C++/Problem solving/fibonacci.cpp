#include <iostream>

int fibonacci(int ind);

int main() {
    int ind = 5;
    std::cout << "Fibonacci(" << ind << ") = " << fibonacci(ind) << std::endl;
}

int fibonacci(int ind) {
    if (ind <= 1) {
        return ind;
    }
    int num1 = 0;
    int num2 = 1;
    for (int i = 1; i < ind; ++i) {
        int tmp = num1 + num2;
        num1 = num2;
        num2 = tmp;
    }
    return num2;
}
