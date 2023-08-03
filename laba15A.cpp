/*
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>

int main(int argc, char *argv[]) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 100);
    FILE *f;
    int amount_of_strings = ((int) floor(dist(mt))) % 40 + 5;
    std::cout << "AMOUNT = " << amount_of_strings << std::endl;
    f = fopen("file1.txt", "w+");
    char *str = new char[100];
    char alph[26]{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z',
                  'x', 'c', 'v', 'b', 'n', 'm'};
    for (size_t j = 0; j < amount_of_strings; ++j) {
        size_t len = ((int) floor(dist(mt)));
        int letter_index = ((int) floor(dist(mt))) % 26;
        char letter = alph[letter_index];
        for (size_t i = 0; i < len; ++i) {
            *(str + i) = letter;
        }
        if (*(str + strlen(str) - 1) == *(str)) {
            fputs(str, f);
            fputs("\n", f);
        }
        memset(str, 0, strlen(str));
    }
    rewind(f);
    int count = 1;
    printf("Initial file:\n");
    while (fgets(str, 100, f)) {
        std::cout << count << ") " << str;
        ++count;
    }
    
    std::cout << std::endl;
    count = 1;
    rewind(f);
    FILE *f0;
    f0 = fopen("file2.txt", "w+"); 
    while (fgets(str, 100, f)) {
        char *temp_str = new char[100]{""};
        char *count_str = new char[(int) ((ceil(log10(count)) + 1) * sizeof(char))];
        char *len_str = new char[(int) ((ceil(log10((double) strlen(str) - 1)) + 1) * sizeof(char))];

        sprintf(count_str, "%d", count);
        sprintf(len_str, "%llu", (strlen(str) - 1));
        strcat(temp_str, count_str);
        strcat(temp_str, ") ");
        strncat(temp_str, &*(str), 1);
        strcat(temp_str, len_str);

        fputs(temp_str, f0);
        fputs("\n", f0);
        ++count;
        memset(temp_str, 0, strlen(temp_str));
        memset(count_str, 0, strlen(count_str));
        memset(len_str, 0, strlen(len_str));
    }

    rewind(f0);

    printf("End file:\n");
    while (fgets(str, 100, f0) != nullptr) {
        std::cout << str;
    }
    fclose(f);
    fclose(f0);
    remove("file1.txt");
    remove("file2.txt");
    return 0;
}
*/