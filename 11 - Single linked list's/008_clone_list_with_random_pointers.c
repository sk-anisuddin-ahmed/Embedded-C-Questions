/*
Clone a List with Random Pointers
Input: A (rand→C) → B (rand→A) → C (rand→B)
Expected Output: New cloned list where each node’s random pointer is correctly set
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node_randomList* findNode(Node_randomList* head, int key)
{
    while (head)
    {    
        if (head->data == key)
        {
            return head;
        }
        head = head->next;
    }
    return head;
}

Node_randomList* cloneList(Node_randomList* head)
{
    Node_randomList* returnNode = NULL;
    Node_randomList* temp = head;
    while (temp)
    {
        insertAtEnd_randomList(&returnNode, temp->data);
        temp = temp->next;
    }
    temp = head;
    Node_randomList* returnNodeTemp = returnNode;

    while (returnNodeTemp)
    {
        returnNodeTemp->random = findNode(returnNodeTemp, head->random->data);
        returnNodeTemp = returnNodeTemp->next;
    }
    
    return returnNode;
}

int main()
{
    Node_randomList* head = NULL;

    insertAtEnd_randomList(&head, 1);
    insertAtEnd_randomList(&head, 2);
    insertAtEnd_randomList(&head, 3);

    // Set random pointers manually
    head->random = head->next->next; // 1 → 3
    head->next->random = head;       // 2 → 1
    head->next->next->random = head->next; // 3 → 2

    printf("Original list:\n");
    printList_randomList(head);

    printList_randomList(cloneList(head));

    return 0;
}