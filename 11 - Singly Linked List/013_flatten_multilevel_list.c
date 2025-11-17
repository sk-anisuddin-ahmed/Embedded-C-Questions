/*
Flatten a Multilevel Linked List
Input: 1 → 2 → 3, node 2’s child: 7 → 8, node 8’s child: 11
Expected Output: 1 → 2 → 7 → 8 → 11 → 3

1---2---3---4---5---6--NULL
        |
        7---8---9---10--NULL
            |
            11--12--NULL
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

NodeMulti* flatMultiLL(NodeMulti* head) 
{
    if (head == NULL) return head;
    NodeMulti* stack[25] = {NULL};
    int stackPointer = 0;

    NodeMulti* temp = head;
    while (temp)
    {
        while(temp->child)
        {
            if (temp->next) stack[stackPointer++] = temp->next;
            temp->next = temp->child;
            temp->child = NULL;
        }
        if (temp->next == NULL && stackPointer)
        {
            temp->next = stack[--stackPointer];
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    NodeMulti* head = createMultiLLNode(1);
    head->next = createMultiLLNode(2);
    NodeMulti* node2 = createMultiLLNode(7);
    head->next->child = node2;
    node2->next = createMultiLLNode(8);
    node2->next->child = createMultiLLNode(11);
    head->next->next = createMultiLLNode(3);

    head = flatMultiLL(head);
    printMultiList(head);

    return 0;
}