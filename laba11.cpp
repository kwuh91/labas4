/*
#include <iostream>

void creation(int* a, int n) {
    int value;
    std::cout << "Enter values:\n";
    for (size_t i = 0; i < n; ++i) {
        std::cin >> value;
        *(a + i) = value;
    }
}

void display(int* a, int n) {
    for (int* it = a; it != a + n; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int task(int* a, int n) {
    int sum = 0;
    for (int* it = a; it != a + n; ++it) {
        if (*it < 0) {
            sum += *it;
            std::cout << "Address of a negative element: " << it << " (" << *it << ")" << std::endl;
        }
    }
    *(a + n - 1) = sum;
    return sum;
}

int main() {
    int n;
    std::cout << "Enter the size of an array:\n";
    std::cin >> n;
    if (n < 0) {
        std::cout << "n < 0\n";
        return 0;
    }
    int* a = new int[n];
    creation(a,n);
    std::cout << "Entered array:\n";
    display(a,n);
    int sum = task(a,n);
    std::cout << "sum of negative elements = " << sum << std::endl;
    std::cout << "Final array:\n";
    display(a,n);
    delete[] a;
    return 0;
}
*/