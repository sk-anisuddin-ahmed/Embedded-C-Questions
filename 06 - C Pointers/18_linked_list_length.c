/*
Problem Statement:
Design a program that finds the length of a linked list using double pointers
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int find_length(struct Node** head)
{
    int length = 0;
    struct Node* current = *head;
    while (current != NULL) 
    {
        length++;
        current = current->next;
    }
    return length;
}

int main() 
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printf("Length of linked list: %d\n", find_length(&head));
    return 0;
}