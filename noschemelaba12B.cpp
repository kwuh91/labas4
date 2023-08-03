#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
/*
int n, ** a;

#define creation \
for (size_t i = 0; i < n; ++i) {\
for (size_t j = 0; j < n; ++j) {\
    *(*(a + i) + j) = rand() % 90 + 10;\
}\
}

#define display \
for (size_t i = 0; i < n; ++i) {\
for (size_t j = 0; j < n; ++j) {\
    std::cout << std::setw(3) << *(*(a + i) + j) << ' ';\
}\
std::cout << std::endl;\
}

#define task int x;\
srand(time(nullptr));\
std::cout << "Enter n, the size of a matrix(n*n):\n";\
std::cin >> n;\
if (n < 0) {\
    std::cout << "n < 0\n";\
    return 0;\
}\
int** a = new int* [n];\
for (int i = 0; i < n; ++i) {\
    *(a + i) = new int[n];\
}\
std::cout << "\nInitial matrix:\n";\
for (size_t i(0); i < n; ++i) std::cout << " (" << i << ")";\
std::cout << std::endl;\
creation;\
display;\
std::cout << "\nOutput, based on task:\n";\
for (size_t i(1); i < n; i += 2) std::cout << " (" << i << ")";\
std::cout << "   ";\
for (size_t i(0); i < n; i += 2) std::cout << " (" << i << ")";\
std::cout << std::endl;\
for (size_t i = 0; i < n; ++i) {\
    for (size_t j = 1; j < n; j += 2) {\
        std::cout << std::setw(3) << *(*(a + i) + j) << ' ';\
    }\
    std::cout << "   ";\
    for (size_t k = 0; k < n; k += 2) {\
        std::cout << std::setw(3) << *(*(a + i) + k) << ' ';\
    }\
    std::cout << std::endl;\
}\
for (int i = 0; i < n; ++i) {\
    delete[] * (a + i);\
}\
delete[] a;\
return 0;

int main() {
    task;
}
*/
