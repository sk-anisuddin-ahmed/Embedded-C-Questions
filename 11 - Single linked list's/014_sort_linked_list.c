/*
Sort a Linked List
Input: 3 → 1 → 5 → 2 → 4
Expected Output: 1 → 2 → 3 → 4 → 5

Input2: 7 → 8 → 9 → 4 → 5 → 6
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* swapLL(Node* first, Node*second, Node* firstPrev)
{
    Node* temp = second->next;
    second->next = first;
    first->next = temp;
    if (firstPrev) firstPrev->next = second;
    return second;
}

Node* sortLL(Node* head) 
{
    //Bubble sort LinkedList
    Node* temp, *prevTemp = NULL;
    _Bool swap = 1;
    Node* last = NULL;
    while (swap)
    {
        temp = head;
        prevTemp = NULL;
        swap = 0;
        while(temp->next != last)
        {
            if (temp->data > temp->next->data)
            {
                Node* newFront = swapLL(temp, temp->next, prevTemp);
                
                if (temp == head)  head = newFront;
                prevTemp = newFront;
                
                temp = newFront->next;
                swap = 1;
            }
            else
            {
                prevTemp = temp;
                temp = temp->next;
            }
        }
        last = temp;
    }
    
    return head;
}

int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    head = sortLL(head);

    printList(head);

    return 0;
}