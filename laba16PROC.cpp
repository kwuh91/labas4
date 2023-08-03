/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>

double sum = 0;

void recursive_sum(double *a, int size) {
    if (size > 0) {
        sum += *(a + size);
        std::cout << "a[" << size << "] = " << *(a + size) << std::endl;
        std::cout << "current sum = " << sum << std::endl;
        recursive_sum(a, --size);
    }
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
    recursive_sum(a, size - 1);
    std::cout << "\nSum:\n" << sum;
    return 0;
}
*/
