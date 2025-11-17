/*
Find Intersection Point
Input: List1: 1 → 2 → 3 → 4 → 5, List2: 9 → 4 → 5 (nodes 4 and 5 are shared)
Expected Output: Intersection at node with value 4
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* inersectionNode(Node* head) 
{
    Node* slow = head;
    Node* fast = head;
    int Slow = 0;
    while (fast)
    {
        if (++Slow >= 2)
        {
            slow = slow->next;
            Slow = 0;
        }
        fast = fast->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    Node* head2 = createNode(9);
    head2->next = head->next->next->next;
    printList(head);
    printList(head2);

    head->next->next->next->next = head2;

    Node* result = inersectionNode(head);
    if (result)
        printf("%d\n", result->data);

    return 0;
}