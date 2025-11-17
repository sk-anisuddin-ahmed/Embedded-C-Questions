/*
Pairwise Swap Nodes
Input: 1 → 2 → 3 → 4 → 5
Expected Output: 2 → 1 → 4 → 3 → 5
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* swapLL(Node* first, Node*second, Node* firstPrev)
{
    Node* temp = second->next;
    second->next = first;
    first->next = temp;
    if (firstPrev) firstPrev->next = second;
    return second;
}

Node* pairwiseSwap(Node* head)
{
    if (!head || !head->next) return head;

    Node* temp = head;
    Node* tempPrev = NULL;

    while (temp && temp->next)
    {
        Node* newFront = swapLL(temp, temp->next, tempPrev);

        if (temp == head)
            head = newFront;

        tempPrev = temp;
        temp = temp->next;
    }

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
    insertAtEnd(&head, 7);
    head = pairwiseSwap(head);
    printList(head);

    return 0;
}