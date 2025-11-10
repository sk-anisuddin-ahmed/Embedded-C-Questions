/*
Detect a Loop
Input: 1 → 2 → 3 → 4 → 5 (node 5 points back to node 2)
Expected Output: Loop detected. Starting node of loop is 2
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

bool detectLoop(Node* head) 
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
            return true;
        }
    }
    return false;
}

int main()
{
    Node* head = createNode(0);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    // head->next->next->next = head->next;

    printf("%d\n", detectLoop(head));

    return 0;
}