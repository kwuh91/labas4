/*
#include "MODULE14.h"
#include <cstring>
#include <iostream>

void MODULE(int **a, int *j, int n) {
    int count = 0;
    std::cout << "Element(s) in column " << *j << ", that are divisible by 3: ";
    for (size_t i = 0; i < n; ++i) {
        if (*(*(a + i) + (*j)) % 3 == 0) {
            ++count;
            std::cout << *(*(a + i) + (*j)) << ' ';
        }
    }
    std::cout << "(amount: " << count << ")" << std::endl;
    if (count > 0) {
        *(*(a + (*j)) + (*j)) = count;
    } else {
        *(*(a + (*j)) + (*j)) = 0;
    }
}
*/
