/*
Reverse Alternate K Nodes
Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, k = 2
Expected Output: 2 → 1 → 3 → 4 → 6 → 5 → 7 → 8
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* reverseLink(Node* head, Node* prev, int k)
{
    Node* previous = NULL;
    Node* curr = head;        
    while (head && k--)
    {
        head = head->next;
        curr->next = previous;
        previous = curr;
        curr = head;
    }        
    if (prev)
        prev->next = previous;
    return previous;
}

Node* reverseKGroup(Node* head, int k) 
{
    Node* previous = NULL;
    Node* returnHead = NULL;
    while(head)
    {
        int i = 1;
        Node* temp = head;
        for (; i < k; i++)
        {
            if (!temp) break;
            temp = temp->next;
        }
        if (!temp)
        {
            if (returnHead)
            {
                reverseLink(head, previous, i);
            }
            else
            {
                returnHead = reverseLink(head, previous, i);
            }
            previous = head;
            head = temp;
        }
        else
        {
            temp = temp->next; //Reach next Kth first node
            if (returnHead)
            {
                reverseLink(head, previous, k);
            }
            else
            {
                returnHead = reverseLink(head, previous, k);
            }
            previous = head;
            head = temp;
        }
    }
    return returnHead;
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
    head = reverseKGroup(head, 2);
    printList(head);

    return 0;
}