/*
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-50, 50);
    FILE *f;
    char *str = new char[100];
    f = fopen("file1.bin", "w+");
    int amount = abs((int) (floor(dist(mt))))+5;
    for (size_t i = 0; i < amount; ++i){
        char *numb_str = new char[10];
        int numb = floor(dist(mt));
        sprintf(numb_str,"%d",numb);
        fputs(numb_str,f);
        fputs("\n",f);
        memset(numb_str,0,strlen(numb_str));
    }
    rewind(f);
    int count = 1;
    printf("Initial file:\n");
    while (fgets(str, 100, f) != nullptr) {
        printf("%d) %s", count, str);
        ++count;
    }
    rewind(f);
    FILE *f0;
    f0 = fopen("file2.bin","w+");
    count = 1;
    while (fgets(str, 100, f) != nullptr) {
        if (count%2 != 0){
            fputs(str,f0);
        }
        ++count;
    }
    fclose(f);
    rewind(f0);
    count = 1;
    printf("\nEnd file:\n");
    while (fgets(str,100,f0) != nullptr){
        std::cout << count << ") " << str;
        count += 2;
    }
    fclose(f0);
    remove("file1.txt");
    remove("file2.txt");
    return 0;
}
*/