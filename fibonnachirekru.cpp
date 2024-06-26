#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

void measureTimeRecursive(int n) {
    auto start = high_resolution_clock::now();
    long long result = fibonacciRecursive(n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Fibonacci Rekursif(" << n << "): " << result << " dalam " << duration << " mikrodetik" << endl;
}

int main() {
    int n;
    cout << "Masukkan nilai n: ";
    cin >> n;
    measureTimeRecursive(n);
    return 0;
}