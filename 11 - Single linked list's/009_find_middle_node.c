/*
Find the Middle Node
Input: 1 → 2 → 3 → 4 → 5
Expected Output: 3
*/


#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* findMid(Node* head) 
{
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;    
}

int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    
    printf("%d", findMid(head)->data);

    return 0;
}