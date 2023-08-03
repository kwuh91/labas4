/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>
#include "MODULE14.h"

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-25, 100);
    int n, m;
    std::cout << "Enter the size of a matrix (n*m)(n>=m):\n";
    std::cout << "n:\n";
    std::cin >> n;
    std::cout << "m:\n";
    std::cin >> m;
    if (n < 0 || m < 0) {
        std::cout << "n or m < 0;\n";
        return 0;
    } else if (n < m) {
        std::cout << "n < m\n";
        return 0;
    }
    //initializing
    int **a = new int *[n];
    for (size_t i = 0; i < n; ++i) {
        *(a + i) = new int[m];
    }
    //creating
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            *(*(a + i) + j) = floor(dist(mt));
        }
    }

    std::cout << "Initial matrix:\n";
    //displaying
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            printf("%3d ", *(*(a + i) + j));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int j = 0; j < m; ++j) {
        MODULE(a, &j, n);
    }

    std::cout << "\nReformed matrix: (One element in each column is replaced with an amount of divisible by 3 elements in each column)\n";
    //displaying
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            printf("%3d ", *(*(a + i) + j));
        }
        std::cout << std::endl;
    }

    //displaying pointers
    std::cout << "\n Pointers to each element in a reformed matrix:\n";
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            printf("%p(%3d) ", ((a + i) + j), *(*(a + i) + j));
        }
        std::cout << std::endl;
    }

    //deleting
    for (size_t i = 0; i < n; ++i) {
        delete[] *(a + i);
    }
    delete[] a;

    return 0;
}
*/
