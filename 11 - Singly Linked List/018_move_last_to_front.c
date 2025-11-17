/*
Move Last Element to Front
Input: 1 → 2 → 3 → 4 → 5
Expected Output: 5 → 1 → 2 → 3 → 4
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* moveLastHead(Node* head) 
{
    Node* curr = head;
    Node* prev = NULL;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = head;
    head = curr;
    return head;
}

int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    head = moveLastHead(head);
    printList(head);

    return 0;
}