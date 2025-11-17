/*
Remove N-th Node from End
Input: 1 → 2 → 3 → 4 → 5, n = 2
Expected Output: 1 → 2 → 3 → 5
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

void Remove_N_th_Node_End(Node* head, int N) 
{
    Node* slow = head;
    Node* fast = head->next;
    
    while(N--)
    {
        fast = fast->next;
    }
    
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
}

int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);

    Remove_N_th_Node_End(head, 3);
    printList(head);

    return 0;
}