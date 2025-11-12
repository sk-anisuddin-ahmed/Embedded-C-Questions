/*
Merge Two Sorted Lists
Input: List1: 1 → 3 → 5, List2: 2 → 4 → 6
Expected Output: 1 → 2 → 3 → 4 → 5 → 6
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* Merge_Two_Sorted_Lists(Node* head1, Node* head2) 
{
    Node* returnNode = head2;
    Node* temp = head2;
    if (head1->data < head2->data)
    {
        temp = head1;
        returnNode = head1;
        head1 = head1->next;        
    }
    else
    {
        head2 = head2->next;
    }

    while(head1 && head2)
    {
        if (head1->data < head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1 != NULL)
    {
        temp->next = head1;
    }
    else if (head2 != NULL)
    {
        temp->next = head2;
    }

    return returnNode;
}

int main()
{
    Node* head1 = NULL;
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 5);

    Node* head2 = NULL;
    insertAtEnd(&head2, 2);
    insertAtEnd(&head2, 4);
    insertAtEnd(&head2, 6);
    
    printList(Merge_Two_Sorted_Lists(head1, head2));

    return 0;
}