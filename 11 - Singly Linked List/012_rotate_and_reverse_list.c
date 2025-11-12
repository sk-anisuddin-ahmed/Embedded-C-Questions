/*
Rotate Linked List
Input: 1 → 2 → 3 → 4 → 5, k = 2
Expected Output: 4 → 5 → 1 → 2 → 3
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* reverse(Node* head) 
{
    Node* prev = NULL;
    Node* curr = head;

    while (curr)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* reverseRecursive(Node* head) 
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* temp = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
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

    head = reverseRecursive(head);
    printList(head);

    return 0;
}