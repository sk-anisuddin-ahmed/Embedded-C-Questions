/*
Detect and Remove Loop
Input: 1 → 2 → 3 → 4 → 2 (loop at node 2)
Expected Output: Loop removed. New list: 1 → 2 → 3 → 4
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

void removeLoop(Node* head) 
{
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow->next->next = NULL;
            break;
        }
    }
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

    head->next->next->next->next->next->next->next = head->next->next;

    removeLoop(head);
    printList(head);

    return 0;
}