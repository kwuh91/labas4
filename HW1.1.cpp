/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>
#include "MODULEHW1.1.h"

void display(int n, int m, double** arr) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            printf("%10lf ", *(*(arr + i) + j));
        }
        std::cout << std::endl;
    }
}

void init(int n, int m, double** arr) {
    for (size_t i = 0; i < n; ++i) {
        *(arr + i) = new double[m];
    }
}

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-25, 100);

    int n, m;

    std::cout << "Enter the size of a matrix (n*m):\n";
    std::cout << "n:\n";
    std::cin >> n;
    std::cout << "m:\n";
    std::cin >> m;
    if (n < 0 || m < 0) {
        std::cout << "n or m < 0;\n";
        return 0;
    }

    int* task_a = new int[n];
    int* amount_of_neg_el = new int[n];
    int len = 0;

    //initializing
    double** a = new double* [n];
    init(n, m, a);

    //filling
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            *(*(a + i) + j) = dist(mt);
        }
    }

    //displaying
    std::cout << "\nInitial matrix:\n";
    display(n, m, a);

    MODULE(a, task_a, &len, amount_of_neg_el, n, m);

    int new_size = n - len;

    //initializing new matrix
    double **b = new double *[n];
    init(n, m, b);

    //filling new matrix
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            *(*(b + i) + j) = *(*(a + i) + j);
        }
    }

    //deleting
    for (size_t i = 0; i < n; ++i) {
        delete[] *(a + i);
    }
    delete[] a;

    //reforming
    a = new double *[new_size];
    for (size_t i = 0; i < new_size; ++i) {
        *(a + i) = new double[m];
    }

    int ind_a = 0;
    for (size_t i = 0; i < n; ++i) {
        bool flag = false;
        for (size_t k = 0; k < len; ++k) {
            if (i == *(task_a + k)) {
                flag = true;
            }
        }
        if (!flag) {
            for (size_t j = 0; j < m; ++j) {
                *(*(a + ind_a) + j) = *(*(b + i) + j);
            }
            ++ind_a;
        }
    }

    //displaying
    std::cout << "\nReformed matrix:\n";
    display(new_size, m, a);

    if (len > 0) {
        int ind_b = 0;
        std::cout << "\nDeleted rows:\n";
        for (size_t i = 0; i < n; ++i) {
            bool flag = false;
            int row;
            for (size_t k = 0; k < len; ++k) {
                if (i == *(task_a + k)) {
                    flag = true;
                    row = (int) i;
                }
            }
            if (flag) {
                std::cout << row + 1 << ": ";
                for (size_t j = 0; j < m; ++j) {
                    printf("%10lf ", *(*(b + i) + j));
                }
                std::cout << "(" << amount_of_neg_el[ind_b] << ") negative elements" << std::endl;
                ++ind_b;
            }
        }
    } else {
        std::cout << "There are no deleted rows\n";
    }

    //deleting
    */
    /*
    for (size_t i = 0; i < n; ++i) {
        delete[] *(a + i);
    }
    delete[] a;

    for (int i = 0; i < m; ++i) {
        delete[] *(b + i);
    }
    delete[] b;

    delete[] task_a;
    delete[] amount_of_neg_el;
    */
    /*
    return 0;
}
*/
