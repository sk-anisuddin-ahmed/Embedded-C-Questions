/*
Find Intersection with Arbitrary Lengths
Input: List1: 1 → 2 → 3 → 4 → 5, List2: 9 → 8 → 5 (node 5 shared)
Expected Output: Intersection at node with value 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

Node* findIntersection(Node* head1, Node* head2)
{
    int len1 = 0, len2 = 0;
    Node *temp1 = head1, *temp2 = head2;

    while (temp1)
    {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    int diff = abs(len1 - len2);

    temp1 = head1;
    temp2 = head2;

    if (len1 > len2)
        while (diff--) temp1 = temp1->next;
    else
        while (diff--) temp2 = temp2->next;

    while (temp1 && temp2)
    {
        if (temp1 == temp2)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1;
}

int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    
    Node* head2 = NULL;
    insertAtEnd(&head2, 9);
    insertAtEnd(&head2, 8);
    head2->next->next = head->next->next->next->next;
    
    printf("%d", findIntersection(head, head2)->data);

    return 0;
}