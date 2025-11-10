/*
Add Two Numbers Represented by Linked Lists
Input: List1: 2 → 4 → 3 (342), List2: 5 → 6 → 4 (465)
Expected Output: 7 → 0 → 8 (807)
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* reverse(Node* head)
{
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addLL(Node* head1, Node* head2) 
{
    Node* result = NULL;
    head1 = reverse(head1);
    head2 = reverse(head2);

    int carry = 0;

    while (head1 && head2)
    {
        int sum = head1->data + head2->data + carry;
        carry = sum / 10;
        sum = sum % 10;

        insertAtBeginning(&result, sum);

        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1)
    {
        int sum = head1->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        insertAtBeginning(&result, sum);
        head1 = head1->next;
    }
    while (head2)
    {
        int sum = head2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        insertAtBeginning(&result, sum);
        head2 = head2->next;
    }

    if (carry)
    {
        insertAtBeginning(&result, carry);
    }

    return result;
}

int main()
{
    Node* head1 = NULL;
    insertAtEnd(&head1, 9);
    insertAtEnd(&head1, 9);
    insertAtEnd(&head1, 9);

    Node* head2 = NULL;
    insertAtEnd(&head2, 1);
    
    printList(addLL(head1, head2));

    return 0;
}