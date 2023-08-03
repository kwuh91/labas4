/*
#include "MODULEHW1.1.h"
#include <cstring>

void MODULE(double** a, int* task_a, int* len, int* a_n_e, int n, int m) {
    int ind = 0;
    for (size_t i = 0; i < n; ++i) {
        int count = 0;
        for (size_t j = 0; j < m; ++j) {
            if (*(*(a + i) + j) < 0) {
                ++count;
            }
        }
        if (count >= 2) {
            task_a[ind] = (int)i;
            a_n_e[ind] = count;
            ++ind;
            ++(*len);
        }
    }
}
*/
