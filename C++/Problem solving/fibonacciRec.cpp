#include <iostream>

int fibonacciRec(int ind);

int main() {
    int ind = 5;
    std::cout << "Fibonacci(" << ind << ") = " << fibonacciRec(ind) << std::endl;
}

int fibonacciRec(int ind) {
    if (ind <= 1) {
        return ind;
    }
    return fibonacciRec(ind - 1) + fibonacciRec(ind - 2);
}
