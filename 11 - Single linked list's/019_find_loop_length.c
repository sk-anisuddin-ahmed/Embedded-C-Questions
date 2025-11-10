/*
Find the Length of a Loop
Input: 1 → 2 → 3 → 4 → 2 (loop includes nodes 2, 3, 4)
Expected Output: Loop length is 3
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

int loopLen(Node* head) 
{
    Node* slow = head;
    Node* fast = head;
    int loopLen = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            do
            {
                ++loopLen;
                slow = slow->next;
            } while (slow != fast);
            break;
        }
    }
    return loopLen;
}

int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    head->next->next->next->next = head->next;

    printf("%d", loopLen(head));

    return 0;
}