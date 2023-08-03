/*
#pragma warning(push)
#pragma warning(disable: 6001)

#include <iostream>
#include <random>
#include <iomanip>

void arr_fill(int, int, int**);

void arr_display(int, int, int**);

void ptr_arr_fill(int, int, int, int**, int**);

void ptr_arr_display(int, int, int**);

void ptr_arr_display_pointers(int, int, int**);

void new_arr_fill(int, int, int, int**, int**, int**);

void new_arr_display(int, int**);

int main() {
	//time reset
	srand(time(NULL));

	//initializing variables
	int amount, n, m;
	int** arr, ** ptr_arr, ** new_arr;

	//giving size
	std::cout << "Enter the size of a matrix n*m (n<m)\nn:\n";
	std::cin >> n;
	std::cout << "m:\n";
	std::cin >> m;
	amount = m - n;

	//initializing arr
	arr = new int* [n];
	for (size_t i(0); i < n; ++i) {
		*(arr + i) = new int[m];
	}

	//filling arr
	arr_fill(n, m, arr);

	//displaying arr
	arr_display(n, m, arr);

	//initializing ptr_arr 
	ptr_arr = new int* [n];
	for (size_t i(0); i < n; ++i) {
		*(ptr_arr + i) = new int[amount];
	}

	//filling ptr_arr (with min elements)
	ptr_arr_fill(n, m, amount, arr, ptr_arr);

	//displaying ptr_arr
	ptr_arr_display(n, amount, ptr_arr);

	//displaying ptr_arr pointers
	ptr_arr_display_pointers(n, amount, ptr_arr);

	//initializing new_arr
	new_arr = new int* [n];
	for (size_t i(0); i < n; ++i) {
		*(new_arr + i) = new int[n];
	}

	//filling new_arr
	new_arr_fill(n, m, amount, arr, ptr_arr, new_arr);

	//displaying new_arr
	new_arr_display(n, new_arr);

	return 0;
}

//filling arr
void arr_fill(int n, int m, int **arr) {
	for (size_t i(0); i < n; ++i) {
		for (size_t j(0); j < m; ++j) {
			size_t neg = rand() % 2;
			int num = rand() % 100;
			*(*(arr + i) + j) = neg % 2 == 0 ? num * -1 : *(*(arr + i) + j) = num;
		}
	}
	std::cout << std::endl;
}

//displaying arr
void arr_display(int n, int m, int **arr) {
	std::cout << "Initial matrix:\n";
	for (size_t i(0); i < n; ++i) {
		for (size_t j(0); j < m; ++j) {
			std::cout << std::setw(4) << *(*(arr + i) + j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//filling ptr_arr (with min elements)
void ptr_arr_fill(int n, int m, int amount, int **arr, int **ptr_arr) {
	for (size_t i(0); i < n; ++i) {
		for (size_t j(0); j < amount; ++j) {
			int minim = INT_MAX;
			for (size_t k(0); k < m; ++k) {
				if (*(*(arr + i) + k) < minim) {
					bool flag = true;
					for (size_t l(0); l < amount; ++l) {
						if (*(*(arr + i) + k) == *(*(ptr_arr + i) + l)) {
							size_t amount_in_arr(0);
							size_t amount_in_ptr_arr(0);
							for (size_t o(0); o < m; ++o) {
								if (*(*(arr + i) + k) == *(*(arr + i) + o)) amount_in_arr++;
							}
							for (size_t o(0); o < amount; ++o) {
								if (*(*(arr + i) + k) == *(*(ptr_arr + i) + o)) amount_in_ptr_arr++;
							}
							if (amount_in_ptr_arr >= amount_in_arr) flag = false;
						}
					}
					if (flag) minim = *(*(arr + i) + k);

				}
			}
			*(*(ptr_arr + i) + j) = minim;
		}
	}
}

//displaying ptr_arr
void ptr_arr_display(int n, int amount, int **ptr_arr) {
	std::cout << amount << " min elements in each row:\n";
	for (size_t i(0); i < n; ++i) {
		for (size_t j(0); j < amount; ++j) {
			std::cout << std::setw(4) << *(*(ptr_arr + i) + j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//displaying ptr_arr pointers
void ptr_arr_display_pointers(int n, int amount, int **ptr_arr) {
	std::cout << amount << " pointers to min elements in each row:\n";
	for (size_t i(0); i < n; ++i) {
		for (size_t j(0); j < amount; ++j) {
			std::cout << std::setw(5) << ptr_arr + i + j << "(" << *(*(ptr_arr + i) + j) << ") ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//filling new_arr
void new_arr_fill(int n, int m, int amount, int **arr, int **ptr_arr, int **new_arr) {
	for (size_t i(0); i < n; ++i) {
		size_t temp_ind(0);
		for (size_t j(0); j < m; ++j) {
			bool flag = true;
			for (size_t k(0); k < amount; ++k) {
				if ((*(*(arr + i) + j)) == (*(*(ptr_arr + i) + k))) {
					(*(*(ptr_arr + i) + k)) = INT_MAX;
					flag = false;
				};
			}
			if (flag) {
				*(*(new_arr + i) + temp_ind) = *(*(arr + i) + j);
				temp_ind++;
			}
		}
	}
}

//displaying new_arr
void new_arr_display(int n, int **new_arr) {
	std::cout << "Final matrix:\n";
	for (size_t i(0); i < n; ++i) {
		for (size_t j(0); j < n; ++j) {
			std::cout << std::setw(4) << *(*(new_arr + i) + j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

#pragma warning(pop)
*/
