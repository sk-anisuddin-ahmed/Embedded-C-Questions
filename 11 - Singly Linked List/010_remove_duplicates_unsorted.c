/*
Remove Duplicates (Unsorted List)
Input: 1 → 2 → 3 → 2 → 1 → 4
Expected Output: 1 → 2 → 3 → 4
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

int findMax(int num1, int num2) 
{
    return (num1 > num2) ? num1 : num2;
}

void removeDuplicates(Node* head) 
{
    if (!head) return;

    Node* temp = head;
    int maxvalue = 0;
    while(temp)
    {
        maxvalue = findMax(maxvalue, temp->data);
        temp = temp->next;
    }

    bool seen[maxvalue] = {};   //Need Hash-Map for Better Space Complexity
    Node* prev = NULL;
    Node* curr = head;

    while (curr) 
    {
        if (seen[curr->data])
        {
            prev->next = curr->next;
            curr = prev->next;
        } 
        else 
        {
            seen[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 4);

    removeDuplicates(head);
    printList(head);

    return 0;
}