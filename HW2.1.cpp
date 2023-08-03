/*
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#pragma warning ( push )
#pragma warning ( disable : 6031 )
#pragma warning ( disable : 6054 )

#include <iostream>
#include <cstring>

//product structure
struct product {
    char* name = new char[100];
    int date{};
    char* author = new char[100];
    int size{};
};

//displaying menu for a file
void menu_file() {
    std::cout << "============================FILE MENU============================\n";
    std::cout << "Choose option:\n1 - create and open a file\n2 - open an existing file\n3 - exit\n";
}
//3 - what products require less, than a certain amount of memory from a particular year\n4 - what products are created by a certain author in a particular time period\n
//displaying general menu
void menu_general() {
    std::cout << "==============================MENU==============================\n";
    std::cout << "Choose option:\n1 - add product\n2 - delete product\n3 - search\n4 - display information about a product\n5 - display file\n6 - exit\n";
}

//adding data to a file
void add_data(FILE* f) {
    product pr;
    std::cout << "Enter:\n";
    std::cout << "name: ";
    scanf("%s", pr.name);
    std::cout << "author: ";
    scanf("%s", pr.author);
    std::cout << "year of release: ";
    scanf("%d", &pr.date);
    std::cout << "required memory(K): ";
    scanf("%d", &pr.size);
    fseek(f, 0, 2);
    fwrite(&pr, sizeof(product), 1, f);
    std::cout << "\nproduct has been successfully added!\n";
}

//removing data from a file
FILE* delete_data(FILE* f, char* name) {
    product* pr = new product;
    rewind(f);
    FILE* temp = fopen("temp_file", "w+b");
    while (fread(pr, sizeof(product),1, f) != 0) {
        if (strcmp(pr->name, name) != 0) fwrite(pr, sizeof(product), 1, temp);
    }
    fclose(f);
    rewind(temp);
    std::cout << "\nproduct has been successfully deleted!\n";
    return temp;
}

//print info
void print_info(product* pr) {
    printf("%14s %16s %8dK %8d\n", pr->name, pr->author, pr->size, pr->date);
}

//display file
void display(FILE* f) {
    size_t c = 0;
    product* pr = new product;
    std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
    std::cout << ("|     Name     |     Author     |  Size  |  Year  | ") << std::endl;
    rewind(f);
    fseek(f, 0, 0);
    while (fread(pr, sizeof(product), 1, f) != 0) {
        std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
        print_info(pr);
        c++;
    }
    std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
    if (!c) {
        std::cout << "\nFile is empty\n";
    }
    delete pr;
}

//display product
void display_pr(FILE* f, char* name) {
    size_t c = 0;
    product *pr = new product;
    std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
    std::cout << ("|     Name     |     Author     |  Size  |  Year  | ") << std::endl;
    rewind(f);
    fseek(f, 0, 0);
    while (fread(pr, sizeof(product), 1, f) != 0) {
        if (strcmp(pr->name,name) == 0) {
            std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
            print_info(pr);
            c++;
        }
    }
    std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
    if (!c) {
        std::cout << "\nThere is no such product in a file\n";
    }
    delete pr;
}

//< memory display
void display_memory_wise_pr_and_year(FILE* f, int memory, int year) {
    size_t c = 0;
    product* pr = new product;
    std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
    std::cout << ("|     Name     |     Author     |  Size  |  Year  | ") << std::endl;
    rewind(f);
    fseek(f, 0, 0);
    while (fread(pr, sizeof(product), 1, f) != 0) {
        if (pr->size < memory && pr->date == year) {
            std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
            print_info(pr);
            c++;
        }
    }
    std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
    if (!c) {
        std::cout << "\nThere are no products in a file, which require less than " << memory << "K of memory\n";
    }
    delete pr;
}

//author period display
void display_author_period(FILE* f, char* author, int begin, int end) {
    size_t c = 0;
    product* pr = new product;
    std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
    std::cout << ("|     Name     |     Author     |  Size  |  Year  | ") << std::endl;
    rewind(f);
    fseek(f, 0, 0);
    while (fread(pr, sizeof(product), 1, f) != 0) {
        if ((strcmp(pr->author, author) == 0) && pr->date >= begin && pr->date <= end) {
            std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
            print_info(pr);
            c++;
        }
    }
    std::cout << ("+--------------+----------------+--------+--------+ ") << std::endl;
    if (!c) {
        std::cout << "\nThere aren't any products in a file, meeting the given criterias\n";
    }
    delete pr;
}

int main() {
    FILE* f;

    int option_file;
    char filename[30];

    //creating/opening a file
    menu_file();
    while (true) {
        std::cin >> option_file;
        switch (option_file) {
        //create and open a file
        case 1: {
            std::cout << "Enter file name:\n";
            scanf("%s", &filename);
            if (!filename) {
                std::cout << "Please enter a valid file name\n";
                menu_file();
                break;
            }
            f = fopen(filename, "w+b");
            goto loop;
        }
        //open a file
        case 2: {
            std::cout << "Enter file name:\n";
            std::cin >> filename;
            f = fopen(filename, "rb");
            if (f == nullptr) {
                std::cout << "File not found\n";
                menu_file();
                break;
            }
            goto loop;
        }
        //exit
        case 3: {
            return 0; 
        }
        //invalid input
        default: {
            std::cout << "Invalid option\n";
            menu_file();
            break;
        }
        }
    }
    
    loop:
    int option_action;

    //working with a file
    menu_general();
    while (true) {
        std::cin >> option_action;
        switch (option_action) {
        //add
        case 1: {
            add_data(f);
            menu_general();
            break;
        }
        //remove
        case 2: {
            std::cout << "What product would you like to delete?:\n";
            char* name_to_del = new char[100];
            scanf("%s", name_to_del);
            f = delete_data(f, name_to_del);
            menu_general();
            break;
        }
        //search
        case 3: {
            std::cout << "Choose what type of search\n1 - what products require less, than a certain amount of memory from a particular year\n2 - what products are created by a certain author in a particular time period\n";
            int option2;
            std::cin >> option2;
            switch (option2) {
            //< memory and year
            case 1: {
                std::cout << "Products, which require less than WHAT amount of memory would you like to display?:\n";
                int memory;
                scanf("%d", &memory);
                std::cout << "Which year?\n";
                int year;
                std::cin >> year;
                display_memory_wise_pr_and_year(f, memory, year);
                menu_general();
                break;
            }
            //from author in time period
            case 2: {
                std::cout << "Whose products would you like to display?:\n";
                char* author_name = new char[100];
                scanf("%s", author_name);
                std::cout << "What time period?\n";
                std::cout << "Starting with year: ";
                int year_s;
                std::cin >> year_s;
                std::cout << "And ending with year: ";
                int year_e;
                std::cin >> year_e;
                display_author_period(f, author_name, year_s, year_e);
                menu_general();
                break;
            }
            //invalid input
            default: {
                std::cout << "Invalid option\n";
                menu_general();
                break;
            }
            }
            break;
        }
        //display product
        case 4: {
            std::cout << "What product would you like to display?:\n";
            char* name_to_print = new char[100];
            scanf("%s", name_to_print);
            display_pr(f,name_to_print);
            menu_general();
            break;
        }
        //display file
        case 5: {
            display(f);
            menu_general();
            break;
        }
        //exit
        case 6: {
            return 0; 
        }
        //invalid input
        default: {
            std::cout << "Invalid option\n";
            menu_general();
            break;
        }
        }
    }
    return 0;
}

#pragma warning ( pop )
*/
