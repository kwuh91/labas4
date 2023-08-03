/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>

double recursive_sum(double *a, int size, double sum) {
    if (size < 0) {
        return sum;
    }
    sum += *(a + size);
    std::cout << "a[" << size << "] = " << *(a + size) << std::endl;
    std::cout << "current sum = " << sum << std::endl;
    return recursive_sum(a, --size, sum);
}

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-200, 200);
    int size = abs((int) (floor(dist(mt)))) + 10;
    double *a = new double[size];
    for (size_t i = 0; i < size; ++i) {
        *(a + i) = (dist(mt));
    }

    std::cout << "Array of size(" << size << "):\n";
    for (size_t i = 0; i < size; ++i) {
        printf("%14lf ", *(a + i));
    }
    std::cout << std::endl;
    std::cout << std::endl;
    double sum = 0;
    double real_sum = recursive_sum(a, size - 1, sum);
    std::cout << "\nSum:\n" << real_sum;
    return 0;
}
*/
