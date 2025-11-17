/*
Segregate Even and Odd Nodes
Input: 1 → 2 → 3 → 4 → 5 → 6
Expected Output: 2 → 4 → 6 → 1 → 3 → 5
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* evenOddSplit(Node* head) 
{
    Node* evenHead = NULL, *oddHead = NULL;
    Node* evenHeadHead = NULL, *oddHeadHead = NULL;

    while (head)
    {
        if (head->data % 2)
        {
            if (oddHead)
            {
                oddHead->next = head;
                oddHead = oddHead->next;
            }
            else
            {
                oddHeadHead = oddHead = head;
            }
        }
        else
        {
            if (evenHead)
            {
                evenHead->next = head;
                evenHead = evenHead->next;
            }
            else
            {
                evenHeadHead = evenHead = head;
            }
        }
        head = head->next;
    }
    oddHead->next = NULL;
    evenHead->next = oddHeadHead;

    return evenHeadHead;
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

    head = evenOddSplit(head);
    printList(head);

    return 0;
}