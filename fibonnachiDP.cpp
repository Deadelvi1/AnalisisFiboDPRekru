#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class fibonachi {
private:
    deque<long long unsigned int> arr;
    int n;

public:
    fibonachi() {
        arr.push_back(0);
        arr.push_back(1);
        n = 2;
    }

    void generatefibo(int n) {
        if (this->n < n) {
            for (int i = this->n; i <= n; i++) {
                arr.push_back(arr[i - 1] + arr[i - 2]);
            }
            this->n = n;
        }
    }

    long long unsigned int getFibo(int n) {
        generatefibo(n);
        return arr[n];
    }
};

void measureTime(int n, fibonachi& fibo) {
    auto start = high_resolution_clock::now();
    long long unsigned int result = fibo.getFibo(n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Fibonacci(" << n << ") = " << result << " dalam " << duration.count() << " mikrodetik" << endl;
}

int main() {
    fibonachi fibo;

    int n;
    cout << "Masukkan nilai n: ";
    cin >> n;

    measureTime(n, fibo);

    return 0;
}