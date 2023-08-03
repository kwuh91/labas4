/*
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <iostream>

int amount_v, amount_c;

struct Node_vowel {
    char *data = new char[100];
    struct Node_vowel *next;
};

struct Node_consonant {
    char *data = new char[100];
    struct Node_consonant *next;
};


bool is_vowel(char *str) {
    char *vowels = new char[5]{'e', 'u', 'i', 'o', 'a'};
    for (size_t i = 0; i < 5; ++i) {
        if (*(str) == *(vowels + i)) {
            return true;
        }
    }
    return false;
}

void append(struct Node_vowel **head_v, struct Node_consonant **head_c, char newsymb[80], bool flag) {
    if (flag) {
        struct Node_vowel *new_node = new Node_vowel;
        struct Node_vowel *last = *head_v;
        strcpy(new_node->data, newsymb);
        new_node->next = nullptr;
        if (*head_v == nullptr) {
            *head_v = new_node;
            return;
        }
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    } else {
        struct Node_consonant *new_node = new Node_consonant;
        struct Node_consonant *last = *head_c;
        strcpy(new_node->data, newsymb);
        new_node->next = nullptr;
        if (*head_c == nullptr) {
            *head_c = new_node;
            return;
        }
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }
}

void display_v(struct Node_vowel *head) {
    int count = 0;
    while (head != nullptr) {
        printf("%s\n", head->data);
        ++count;
        head = head->next;
    }
    std::cout << "Size: " << count << std::endl;
    amount_v = count;
}

void display_c(struct Node_consonant *head) {
    int count = 0;
    while (head != nullptr) {
        printf("%s\n", head->data);
        ++count;
        head = head->next;
    }
    std::cout << "Size: " << count << std::endl;
    amount_c = count;
}

void destruct_v(struct Node_vowel **head) {
    struct Node_vowel *temp = *head;
    struct Node_vowel *next;
    while (temp != nullptr) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = nullptr;
}

void destruct_c(struct Node_consonant **head) {
    struct Node_consonant *temp = *head;
    struct Node_consonant *next;
    while (temp != nullptr) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = nullptr;
}

int main() {
    struct Node_vowel *head_v = nullptr;
    struct Node_consonant *head_c = nullptr;
    FILE *f;
    f = fopen("text.txt", "w+");
    char *str = new char[500];
    std::cout << "Enter your string:\n";
    gets_s(str,500);
    fputs(str, f);
    memset(str, 0, strlen(str));
    rewind(f);
    std::cout << "\nEntered string:\n";
    while (fgets(str, 500, f) != nullptr) {
        std::cout << str << std::endl;
    }
    rewind(f);
    while (fgets(str, 500, f) != nullptr) {
        char *temp_str = new char[100]{""};
        for (size_t i = 0; i < strlen(str); ++i) {
            while (*(str + i) != ' ' && i < strlen(str)) {
                strncat(temp_str, &*(str + i), 1);
                ++i;
            }
            append(&head_v, &head_c, temp_str, is_vowel(temp_str));
            //std::cout << "STRING: " << temp_str << std::endl;
            memset(temp_str, 0, strlen(temp_str));
        }
    }
    std::cout << "\nWords, that start with a vowel:\n";
    display_v(head_v);
    std::cout << "\nWords, that start with a consonant:\n";
    display_c(head_c);
    if (amount_v > amount_c) {
        std::cout << "\nThere are more words, that start with a vowel(" << amount_v << ">" << amount_c << ")"
                  << std::endl;
    } else {
        std::cout << "\nThere are more words, that start with a consonant(" << amount_c << ">" << amount_v << ")"
                  << std::endl;
    }
    destruct_v(&head_v);
    destruct_c(&head_c);
    fclose(f);
    remove("text.txt");
    return 0;
}
*/