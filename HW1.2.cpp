/*
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <cstring>

void find(char *this_string, char *in_this_string, int *f_i, int *l_i) {
    for (size_t i = 0; i < strlen(in_this_string); ++i) {
        if (*this_string == *(in_this_string + i)) {
            bool flag = false;
            size_t ind = i;
            *f_i = i;
            for (size_t j = 0; j < strlen(this_string); ++j) {
                if (*(this_string + j) != *(in_this_string + ind)) {
                    flag = true;
                    break;
                }
                ++ind;
            }
            *l_i = ind;
            if (!flag) {
                return;
            }
        }
    }
    *f_i = -1;
    *l_i = -1;
}

void reform_with_deletion(char **a, int n) {

    //initializing
    char **temp_arr = new char *[100];
    for (size_t i = 0; i < 100; ++i) {
        *(temp_arr + i) = new char[100];
    }

    //creating
    size_t ind = 0;
    for (size_t i = 0; i < 100; ++i) {
        if (i != n) {
            strcpy(*(temp_arr + ind), *(a + i));
            ++ind;
        }
    }

    //deleting
    for (size_t i = 0; i < 100; ++i) {
        delete[] *(a + i);
    }
    delete[] a;

    //reforming
    a = new char *[100];
    for (size_t i = 0; i < 100; ++i) {
        *(a + i) = new char[100];
    }

    //recreating
    for (size_t i = 0; i < 100; ++i) {
        for (size_t j = 0; j < 100; ++j) {
            *(*(a + i) + j) = *(*(temp_arr + i) + j);
        }
    }
}

void display(char **arr, int n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d) %s", (int) i + 1, *(arr + i));

        std::cout << std::endl;
    }
}

void menu_display() {
    std::cout
            << "\n 0 - add a string\n 1 - concatenate 2 strings\n 2 - find a string in a string\n 3 - copy a string\n 4 - reset strings\n 5 - display all of your strings\n 6 - exit a program\n";
}

int main() {

    //initializing
    int n = 0;
    char **arr_of_strings = new char *[100];
    for (size_t i = 0; i < 100; ++i) {
        *(arr_of_strings + i) = new char[100];
    }
    int option;
    std::cout << "Choose action:\n";
    menu_display();
    while (true) {
        std::cin >> option;
        switch (option) {
            case 0: {

                //add
                std::cout << "Enter your string:\n";
                ++n;
                //std::cin >> *(arr_of_strings + n - 1);
                scanf("%s", *(arr_of_strings + n - 1));
                menu_display();
                break;
            }
            case 1: {

                //concatenation
                int option4;
                std::cout << "Choose action:\n";
                std::cout
                        << "\n 1 - concatenate your string to new\n 2 - concatenate new string to yours\n 3 - concatenate your string to yours\n 4 - concatenate new string to new\n 5 - cancel\n";
                std::cin >> option4;
                switch (option4) {
                    case 1: {

                        //existent to new
                        display(arr_of_strings, n);
                        std::cout << "Which string would you like to concatenate with a new one?:\n";
                        int string_choice;
                        std::cin >> string_choice;
                        bool flag0 = false;
                        for (size_t i = 1; i <= n; ++i) {
                            if (string_choice == i) {
                                flag0 = true;
                            }
                        }
                        if (!flag0) {
                            std::cout << "There is no such string\n";
                            break;
                        } else {
                            std::cout << "Enter new string to concatenate with:\n";
                            ++n;
                            //std::cin >> *(arr_of_strings + n - 1);
                            scanf("%s", *(arr_of_strings + n - 1));
                            char *concatenated_string = new char[100]{""};
                            for (size_t i = 0; i < strlen(*(arr_of_strings + string_choice - 1)); ++i) {
                                strncat(concatenated_string, &*(*(arr_of_strings + string_choice - 1) + i), 1);
                            }
                            for (size_t i = 0; i < strlen(*(arr_of_strings + n - 1)); ++i) {
                                strncat(concatenated_string, &*(*(arr_of_strings + n - 1) + i), 1);
                            }
                            ++n;
                            strcpy(*(arr_of_strings + n - 1), concatenated_string);
                            std::cout << "Your concatenated string: " << *(arr_of_strings + n - 1)
                                      << "\nwas added to your strings\n";
                        }
                        break;
                    }
                    case 2: {

                        //new to existent
                        std::cout << "Enter new string to concatenate with yours:\n";
                        ++n;
                        //std::cin >> *(arr_of_strings + n - 1);
                        scanf("%s", *(arr_of_strings + n - 1));
                        display(arr_of_strings, n);
                        std::cout << "Which string would you like to concatenate with a new one?:\n";
                        int string_choice;
                        std::cin >> string_choice;
                        bool flag0 = false;
                        for (size_t i = 1; i <= n; ++i) {
                            if (string_choice == i) {
                                flag0 = true;
                            }
                        }
                        if (!flag0) {
                            std::cout << "There is no such string\n";
                            memset(*(arr_of_strings + n - 1), 0, strlen(*(arr_of_strings + n - 1)));
                            break;
                        } else {
                            char *concatenated_string = new char[100]{""};
                            for (size_t i = 0; i < strlen(*(arr_of_strings + n - 1)); ++i) {
                                strncat(concatenated_string, &*(*(arr_of_strings + n - 1) + i), 1);
                            }
                            for (size_t i = 0; i < strlen(*(arr_of_strings + string_choice - 1)); ++i) {
                                strncat(concatenated_string, &*(*(arr_of_strings + string_choice - 1) + i), 1);
                            }
                            ++n;
                            strcpy(*(arr_of_strings + n - 1), concatenated_string);
                            std::cout << "Your concatenated string: " << *(arr_of_strings + n - 1)
                                      << "\nwas added to your strings\n";
                        }
                        break;
                    }
                    case 3: {

                        //existent to existent
                        display(arr_of_strings, n);
                        std::cout << "Which string would you like to concatenate with yours?:\n";
                        int string_choice;
                        std::cin >> string_choice;
                        bool flag0 = false;
                        for (size_t i = 1; i <= n; ++i) {
                            if (string_choice == i) {
                                flag0 = true;
                            }
                        }
                        if (!flag0) {
                            std::cout << "There is no such string\n";
                            memset(*(arr_of_strings + n - 1), 0, strlen(*(arr_of_strings + n - 1)));
                            break;
                        } else {
                            display(arr_of_strings, n);
                            std::cout << "Which string would you like to concatenate with chosen?:\n";
                            int string_choice2;
                            std::cin >> string_choice2;
                            bool flag1 = false;
                            for (size_t i = 1; i <= n; ++i) {
                                if (string_choice == i) {
                                    flag1 = true;
                                }
                            }
                            if (!flag1) {
                                std::cout << "There is no such string\n";
                                memset(*(arr_of_strings + n - 1), 0, strlen(*(arr_of_strings + n - 1)));
                                break;
                            } else {
                                char *concatenated_string = new char[100]{""};
                                for (size_t i = 0; i < strlen(*(arr_of_strings + string_choice - 1)); ++i) {
                                    strncat(concatenated_string, &*(*(arr_of_strings + string_choice - 1) + i), 1);
                                }
                                for (size_t i = 0; i < strlen(*(arr_of_strings + string_choice2 - 1)); ++i) {
                                    strncat(concatenated_string, &*(*(arr_of_strings + string_choice2 - 1) + i), 1);
                                }
                                ++n;
                                strcpy(*(arr_of_strings + n - 1), concatenated_string);
                                std::cout << "Your concatenated string: " << *(arr_of_strings + n - 1)
                                          << "\nwas added to your strings\n";
                            }
                        }
                        break;
                    }
                    case 4: {

                        //new to new
                        std::cout << "Enter first new string to concatenate with:\n";
                        ++n;
                        scanf("%s", *(arr_of_strings + n - 1));
                        //std::cin >> *(arr_of_strings + n - 1);
                        std::cout << "Enter second new string to concatenate with the first:\n";
                        ++n;
                        scanf("%s", *(arr_of_strings + n - 1));
                        //std::cin >> *(arr_of_strings + n - 1);
                        char *concatenated_string = new char[100]{""};
                        for (size_t i = 0; i < strlen(*(arr_of_strings + n - 2)); ++i) {
                            strncat(concatenated_string, &*(*(arr_of_strings + n - 2) + i), 1);
                        }
                        for (size_t i = 0; i < strlen(*(arr_of_strings + n - 1)); ++i) {
                            strncat(concatenated_string, &*(*(arr_of_strings + n - 1) + i), 1);
                        }
                        ++n;
                        strcpy(*(arr_of_strings + n - 1), concatenated_string);
                        std::cout << "Your concatenated string: " << *(arr_of_strings + n - 1)
                                  << "\nwas added to your strings\n";
                        break;
                    }
                    case 5:
                        break;
                    default:
                        std::cout << "Invalid option\n";
                        break;
                }
                menu_display();
                break;
            }
            case 2: {

                //what to find
                int option2;
                std::cout << "Choose action:\n";
                std::cout
                        << "\n 1 - to find your string in your string\n 2 - to find your string in a new string\n 3 - to find a new string in your string\n 4 - to find a new string in a new string\n 5 - cancel\n";
                std::cin >> option2;
                switch (option2) {
                    case 1: {

                        //your string in your string
                        display(arr_of_strings, n);
                        std::cout << "Which string would you like to find in another?:\n";
                        int string_choice;
                        std::cin >> string_choice;
                        bool flag0 = false;
                        for (size_t i = 1; i <= n; ++i) {
                            if (string_choice == i) {
                                flag0 = true;
                            }
                        }
                        if (!flag0) {
                            std::cout << "There is no such string\n";
                            break;
                        } else { //
                            display(arr_of_strings, n);
                            std::cout << "In which string would you like to find yours?:\n";
                            int string_choice2;
                            std::cin >> string_choice2;
                            bool flag1 = false;
                            for (size_t i = 1; i <= n; ++i) {
                                if (string_choice2 == i) {
                                    flag1 = true;
                                }
                            }
                            if (!flag1) {
                                std::cout << "There is no such string\n";
                                break;
                            } else {
                                if (strlen(*(arr_of_strings + string_choice - 1)) >
                                    strlen(*(arr_of_strings + string_choice2 - 1))) {
                                    std::cout << "First string is bigger, than the second" << std::endl;
                                    std::cout << "You can't find a bigger string in a smaller one" << std::endl;
                                    break;
                                } else {
                                    int first_ind;
                                    int last_ind;
                                    find(*(arr_of_strings + string_choice - 1), *(arr_of_strings + string_choice2 - 1),
                                         &first_ind, &last_ind);
                                    if (first_ind == -1 || last_ind == -1) {
                                        std::cout << "string " << *(arr_of_strings + string_choice - 1)
                                                  << " is not in string " << *(arr_of_strings + string_choice2 - 1)
                                                  << std::endl;
                                        break;
                                    } else {
                                        std::cout << "string " << *(arr_of_strings + string_choice - 1)
                                                  << " is in string " << *(arr_of_strings + string_choice2 - 1)
                                                  << std::endl;
                                        std::cout << "It starts at position " << first_ind + 1
                                                  << " and ends at position " << last_ind << std::endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    case 2: {

                        //your string in new string
                        display(arr_of_strings, n);
                        std::cout << "Which string would you like to find in another?:\n";
                        int string_choice;
                        std::cin >> string_choice;
                        bool flag0 = false;
                        for (size_t i = 1; i <= n; ++i) {
                            if (string_choice == i) {
                                flag0 = true;
                            }
                        }
                        if (!flag0) {
                            std::cout << "There is no such string\n";
                            break;
                        } else {
                            std::cout << "Enter a string in which you would like to find your chosen earlier string:\n";
                            ++n;
                            scanf("%s", *(arr_of_strings + n - 1));
                            //std::cin >> *(arr_of_strings + n - 1);
                            if (strlen(*(arr_of_strings + string_choice - 1)) > strlen(*(arr_of_strings + n - 1))) {
                                std::cout << "First string is bigger, than the second" << std::endl;
                                std::cout << "You can't find a bigger string in a smaller one" << std::endl;
                                break;
                            } else {
                                int first_ind;
                                int last_ind;
                                find(*(arr_of_strings + string_choice - 1), *(arr_of_strings + n - 1), &first_ind,
                                     &last_ind);
                                if (first_ind == -1 || last_ind == -1) {
                                    std::cout << "string " << *(arr_of_strings + string_choice - 1)
                                              << " is not in string " << *(arr_of_strings + n - 1) << std::endl;
                                    break;
                                } else {
                                    std::cout << "string " << *(arr_of_strings + string_choice - 1) << " is in string "
                                              << *(arr_of_strings + n - 1) << std::endl;
                                    std::cout << "It starts at position " << first_ind + 1 << " and ends at position "
                                              << last_ind << std::endl;
                                    break;
                                }
                            }
                        }
                    }
                    case 3: {

                        //new string in your string
                        std::cout << "Enter a string which you would like to find in one of your strings:\n";
                        ++n;
                        scanf("%s", *(arr_of_strings + n - 1));
                        //std::cin >> *(arr_of_strings + n - 1);
                        display(arr_of_strings, n);
                        std::cout << "In which string would you like to find your entered string?:\n";
                        int string_choice;
                        std::cin >> string_choice;
                        bool flag0 = false;
                        for (size_t i = 1; i <= n; ++i) {
                            if (string_choice == i) {
                                flag0 = true;
                            }
                        }
                        if (!flag0) {
                            std::cout << "There is no such string\n";
                            break;
                        } else {
                            if (strlen(*(arr_of_strings + n - 1)) > strlen(*(arr_of_strings + string_choice - 1))) {
                                std::cout << "First string is bigger, than the second" << std::endl;
                                std::cout << "You can't find a bigger string in a smaller one" << std::endl;
                                break;
                            } else {
                                int first_ind;
                                int last_ind;
                                find(*(arr_of_strings + n - 1), *(arr_of_strings + string_choice - 1), &first_ind,
                                     &last_ind);
                                if (first_ind == -1 || last_ind == -1) {
                                    std::cout << "string " << *(arr_of_strings + n - 1)
                                              << " is not in string " << *(arr_of_strings + string_choice - 1)
                                              << std::endl;
                                    break;
                                } else {
                                    std::cout << "string " << *(arr_of_strings + n - 1) << " is in string "
                                              << *(arr_of_strings + string_choice - 1) << std::endl;
                                    std::cout << "It starts at position " << first_ind + 1 << " and ends at position "
                                              << last_ind << std::endl;
                                    break;
                                }
                            }
                        }
                    }
                    case 4: {

                        //new string in new string
                        std::cout << "Enter a string which you would like to find in another string:\n";
                        ++n;
                        scanf("%s", *(arr_of_strings + n - 1));
                        //std::cin >> *(arr_of_strings + n - 1);
                        std::cout << "Enter a string in which you would like to find your entered earlier string:\n";
                        ++n;
                        scanf("%s", *(arr_of_strings + n - 1));
                        //std::cin >> *(arr_of_strings + n - 1);
                        if (strlen(*(arr_of_strings + n - 2)) > strlen(*(arr_of_strings + n - 1))) {
                            std::cout << "First string is bigger, than the second" << std::endl;
                            std::cout << "You can't find a bigger string in a smaller one" << std::endl;
                            break;
                        } else {
                            int first_ind;
                            int last_ind;
                            find(*(arr_of_strings + n - 2), *(arr_of_strings + n - 1), &first_ind,
                                 &last_ind);
                            if (first_ind == -1 || last_ind == -1) {
                                std::cout << "string " << *(arr_of_strings + n - 2)
                                          << " is not in string " << *(arr_of_strings + n - 1) << std::endl;
                                break;
                            } else {
                                std::cout << "string " << *(arr_of_strings + n - 2) << " is in string "
                                          << *(arr_of_strings + n - 1) << std::endl;
                                std::cout << "It starts at position " << first_ind + 1 << " and ends at position "
                                          << last_ind << std::endl;
                                break;
                            }
                        }
                    }
                    case 5:
                        break;
                    default: {
                        std::cout << "Invalid option" << std::endl;
                        break;
                    }
                }
                menu_display();
                break;
            }
            case 3: {

                //copy
                display(arr_of_strings, n);
                std::cout << "Which string would you like to copy?:\n";
                int string_choice;
                std::cin >> string_choice;
                bool flag0 = false;
                for (size_t i = 1; i <= n; ++i) {
                    if (string_choice == i) {
                        flag0 = true;
                    }
                }
                if (!flag0) {
                    std::cout << "There is no such string\n";
                    break;
                } else {
                    std::cout << "Where would you like to copy this string to?(Press 0 to copy to a new slot):\n";
                    int string_dest;
                    std::cin >> string_dest;
                    bool flag1 = false;
                    for (size_t j = 0; j <= n; ++j) {
                        if (string_dest == j) {
                            flag1 = true;
                        }
                    }
                    if (string_dest == 0) {
                        flag1 = true;
                    }
                    if (!flag1) {
                        std::cout << "There is no such slot\n";
                        break;
                    }
                    if (string_dest == 0) {
                        ++n;
                        strcpy(*(arr_of_strings + n - 1), *(arr_of_strings + string_choice - 1));
                        std::cout << "String " << *(arr_of_strings + string_choice - 1)
                                  << " was copied to a new slot and added to your strings\n";
                    } else {
                        strcpy(*(arr_of_strings + string_dest - 1), *(arr_of_strings + string_choice - 1));
                        std::cout << "String " << *(arr_of_strings + string_choice - 1) << " was copied to the "
                                  << string_dest << " slot and added to your strings\n";

                    }
                }
                menu_display();
                break;
            }
            case 4: {

                //reset
                int option5;
                std::cout << "Choose action:\n";
                std::cout
                        << "\n 1 - reset a particular string\n 2 - reset all of the strings\n 3 - cancel\n";
                std::cin >> option5;
                switch (option5) {
                    case 1: {

                        //reset one
                        display(arr_of_strings, n);
                        std::cout << "Which string would you like to reset?:\n";
                        int string_choice;
                        std::cin >> string_choice;
                        bool flag0 = false;
                        for (size_t i = 1; i <= n; ++i) {
                            if (string_choice == i) {
                                flag0 = true;
                            }
                        }
                        if (!flag0) {
                            std::cout << "There is no such string\n";
                            break;
                        } else {
                            reform_with_deletion(arr_of_strings, string_choice - 1); //HERE in case 1
                            n--;
                            std::cout << "String number " << string_choice << " has been reset\n";
                        }
                        break;
                    }
                    case 2: {

                        //reset all
                        //deleting
                        for (size_t i = 0; i < 100; ++i) {
                            delete[] *(arr_of_strings + i);
                        }
                        delete[] arr_of_strings;

                        //reforming
                        arr_of_strings = new char *[100];
                        for (size_t i = 0; i < 100; ++i) {
                            *(arr_of_strings + i) = new char[100];
                        }
                        n = 0;
                        std::cout << "All of your strings have been reset\n";
                        break;
                    }
                    case 3:
                        break;
                    default:
                        std::cout << "Invalid option\n";
                        break;
                }
                menu_display();
                break;
            }
            case 5: {

                //display
                if (n == 0) {
                    std::cout << "You have no saved strings\n";
                    menu_display();
                    break;
                } else {
                    std::cout << "Your entered strings:\n";
                    display(arr_of_strings, n);
                    menu_display();
                    break;
                }
            }
            case 6: {

                //deleting
                for (size_t i = 0; i < 100; ++i) {
                    delete[] *(arr_of_strings + i);
                }
                delete[] arr_of_strings;
                exit(0);
            }
            default: {
                std::cout << "Invalid option" << std::endl;
                break;
            }
        }
    }
}
*/
