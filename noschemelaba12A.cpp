#pragma warning(push)
#pragma warning(disable: 6001)
/*
#include <iostream>
#include <random>
#include <iomanip>

int amount, n, m;
int** arr, ** ptr_arr, ** new_arr;

#define size_init \
std::cout << "Enter the size of a matrix n*m (n<m)\nn:\n";\
std::cin >> n;\
std::cout << "m:\n";\
std::cin >> m;\
amount = m - n;

#define arr_init \
arr = new int* [n];\
for (size_t i(0); i < n; ++i) {\
*(arr + i) = new int[m];\
}

#define arr_fill \
for (size_t i(0); i < n; ++i) { \
for (size_t j(0); j < m; ++j) {\
size_t neg = rand() % 2;\
int num = rand() % 100;\
*(*(arr + i) + j) = neg % 2 == 0 ? num * -1 : *(*(arr + i) + j) = num;\
}\
}\
std::cout << std::endl;

#define arr_display \
std::cout << "Initial matrix:\n";\
for (size_t i(0); i < n; ++i) {\
for (size_t j(0); j < m; ++j) {\
std::cout << std::setw(4) << *(*(arr + i) + j) << " ";\
}\
std::cout << std::endl;\
}\
std::cout << std::endl;

#define ptr_arr_init \
ptr_arr = new int* [n];\
for (size_t i(0); i < n; ++i) {\
*(ptr_arr + i) = new int[amount];\
}

#define ptr_arr_fill \
for (size_t i(0); i < n; ++i) {\
for (size_t j(0); j < amount; ++j) {\
int minim = INT_MAX;\
for (size_t k(0); k < m; ++k) {\
if (*(*(arr + i) + k) < minim) {\
bool flag = true;\
for (size_t l(0); l < amount; ++l) {\
if (*(*(arr + i) + k) == *(*(ptr_arr + i) + l)) {\
size_t amount_in_arr(0);\
size_t amount_in_ptr_arr(0);\
for (size_t o(0); o < m; ++o) {\
if (*(*(arr + i) + k) == *(*(arr + i) + o)) amount_in_arr++;\
}\
for (size_t o(0); o < amount; ++o) {\
if (*(*(arr + i) + k) == *(*(ptr_arr + i) + o)) amount_in_ptr_arr++;\
}\
if (amount_in_ptr_arr >= amount_in_arr) flag = false;\
}\
}\
if (flag) minim = *(*(arr + i) + k);\
}\
}\
*(*(ptr_arr + i) + j) = minim;\
}\
}

#define ptr_arr_display \
std::cout << amount << " min elements in each row:\n";\
for (size_t i(0); i < n; ++i) {\
for (size_t j(0); j < amount; ++j) {\
std::cout << std::setw(4) << *(*(ptr_arr + i) + j) << " ";\
}\
std::cout << std::endl;\
}\
std::cout << std::endl;\

#define ptr_arr_display_pointers \
std::cout << amount << " pointers to min elements in each row:\n";\
for (size_t i(0); i < n; ++i) {\
for (size_t j(0); j < amount; ++j) {\
std::cout << std::setw(5) << ptr_arr + i + j << "(" << *(*(ptr_arr + i) + j) << ") ";\
}\
std::cout << std::endl;\
}\
std::cout << std::endl;

#define new_arr_init \
new_arr = new int* [n];\
for (size_t i(0); i < n; ++i) {\
*(new_arr + i) = new int[n];\
}

#define new_arr_fill \
for (size_t i(0); i < n; ++i) {\
size_t temp_ind(0);\
for (size_t j(0); j < m; ++j) {\
bool flag = true;\
for (size_t k(0); k < amount; ++k) {\
if ((*(*(arr + i) + j)) == (*(*(ptr_arr + i) + k))) {\
(*(*(ptr_arr + i) + k)) = INT_MAX;\
flag = false;\
};\
}\
if (flag) {\
*(*(new_arr + i) + temp_ind) = *(*(arr + i) + j);\
temp_ind++;\
}\
}\
}

#define new_arr_display \
std::cout << "Final matrix:\n";\
for (size_t i(0); i < n; ++i) {\
for (size_t j(0); j < n; ++j) {\
std::cout << std::setw(4) << *(*(new_arr + i) + j) << " ";\
}\
std::cout << std::endl;\
}\
std::cout << std::endl;

#define task int x;\
srand(time(NULL));\
size_init;\
arr_init;\
arr_fill;\
arr_display;\
ptr_arr_init;\
ptr_arr_fill;\
ptr_arr_display;\
ptr_arr_display_pointers;\
new_arr_init;\
new_arr_fill;\
new_arr_display;\
return 0;

int main() {
	task;
}

#pragma warning(pop)
*/
