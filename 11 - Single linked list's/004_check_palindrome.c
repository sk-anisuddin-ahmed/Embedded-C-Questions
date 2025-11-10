/*
Check for Palindrome
Input: 1 → 2 → 3 → 2 → 1
Expected Output: True (The list is a palindrome)
*/

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

Node* reverseList(Node* head) 
{
    Node *current = head;
    Node *prev = NULL;
    while (current)
    {
        Node *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}

Node* getMiddleNode(Node* temp)
{
    Node* slow = temp;
    Node* fast = temp;
    
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool isPalindrome(Node *head) 
{
    Node* mid = getMiddleNode(head);
    mid = reverseList(mid);
    while(mid)
    {
        if (mid->data != head->data) return 0;
        mid = mid->next;
        head = head->next;
    }
    return 1;
}

int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);

    printf("%d\n", isPalindrome(head));

    return 0;
}