#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base cases: Fibonacci(0) = 0, Fibonacci(1) = 1
    } else {
        // Recursive case: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void generateFibonacciSeries(int limit, int n) {
    if (n < limit) {
        int fib = fibonacci(n);
        if (fib <= limit) {
            std::cout << fib << " ";
            generateFibonacciSeries(limit, n + 1);
        }
    }
}

int main() {
    int limit;
    std::cout << "Enter the limit for the Fibonacci series: ";
    std::cin >> limit;

    std::cout << "Fibonacci series up to " << limit << ":\n";
    generateFibonacciSeries(limit, 0);

    return 0;
}

