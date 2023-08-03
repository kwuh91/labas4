/*
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <random>

static int* arr;
static int I = 0;
const int limit = 1000;
static int curr = 0;

int fact(int n) {
	if (n > 1)
		return n * fact(n - 1);
	else
		return 1;
}

char* swap(char* numb, int i, int j) {
	char temp = numb[i];
	numb[i] = numb[j];
	numb[j] = temp;
	return numb;
}

int a_of_e(int numb) {
	int c = 0;
	while (numb) {
		c++;
		numb /= 10;
	}
	return c;
}

void rec(int numb, char* snumb, int times, int i, int j) {
	curr++;
	if (!times || curr == limit) {
		return;
	}
	else {
		bool flag = true;
		for (int k = 0; k < I; ++k) {
			if (arr[k] == atoi(snumb)) flag = false;
		}
		if (flag) {
			arr[I] = atoi(snumb);
			I++;
		}

		if (!flag) rec(numb, swap(snumb, i, j), times, (i + rand()) % a_of_e(numb), (j + rand()) % a_of_e(numb)); 
		if (flag) rec(numb, swap(snumb, i, j), times - 1, (i + rand()) % a_of_e(numb), (j + rand()) % a_of_e(numb));	
	}
}

void rec(int numb) {
	char snum[100];
	sprintf(snum, "%d", numb);
	arr = new int[fact(a_of_e(numb))];
	rec(numb, snum, fact(a_of_e(numb)), 0, 1);
}

int main() {
	srand(time(NULL));
	int number;
	std::cout << "Enter number:\n";
	std::cin >> number;
	rec(number);
	std::cout << "\nAll possible permutations:\n";
	int t = 0;
	for (int i = 0; i < I; ++i) {
		std::cout << arr[i] << " ";
		t++;
		if (t % 8 == 0) std::cout << std::endl;
		
	}
	std::cout << std::endl;
	return 0;
}
*/
