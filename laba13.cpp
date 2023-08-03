/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int maxsum = 0;

struct Node {
    char *data = new char[100];
    struct Node *next;
};

void append(struct Node **head, char *str) {
    struct Node *new_node = new Node;
    struct Node *last = *head;
    strcpy(new_node->data, str);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void display_pre(char *str) {
    std::cout << "String with all the addresses:\n";
    std::cout << str << std::endl;
    for (size_t i = 0; i < strlen(str); ++i) {
        printf("%c: %p\n", *(str + i), str + i);
    }
}

void taskexp(char *str) {
    int max = -1000000;
    size_t maxind = 0;
    for (size_t i = 0; i < strlen(str); ++i) {
        char *temp_str = new char[100]{0};
        int temp_ind = 0;
        int tempmaxind = 0;
        while (*(str + i) != ' ' && i < strlen(str)) {
            *(temp_str + temp_ind) = *(str + i);
            if (temp_ind == 0) {
                tempmaxind = i;
            }
            ++i;
            ++temp_ind;
        }
        if (atoi(temp_str) > max) {
            max = atoi(temp_str);
            maxind = tempmaxind;
        }
        memset(temp_str, 0, strlen(temp_str));
    }
    maxsum += max;
    std::cout << "\nINDEX OF A FIRST ELEMENT OF A MAX_NUMBER: " << maxind << std::endl;
    std::cout << "MAX_NUMBER: " << max << std::endl;
    printf("ADDRESS OF A FIRST ELEMENT OF A MAX_NUMBER: %p \nFIRST ELEMENT OF A MAX_NUMBER: %c\n", str + maxind,
           *(str + maxind));
}

void display(struct Node *head) {
    while (head != NULL) {
        display_pre(head->data);
        taskexp(head->data);
        head = head->next;
    }
    std::cout << std::endl;
}

void destruct(struct Node **head) {
    struct Node *temp = *head;
    struct Node *next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {    
    struct Node *head = NULL;
    char *string = new char[100];
    std::cout << "Enter your strings:\n";
    gets_s(string,99);
    while (*(string) != NULL) {
        append(&head, string);
        gets_s(string,99);
    }
    display(head);
    std::cout << "Sum of max elements:\n";
    std::cout << maxsum << std::endl;

    destruct(&head);
    delete[]string;
    return 0;
}
*/
