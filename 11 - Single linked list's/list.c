#include <stdio.h>
#include <stdlib.h>
#include "list.h"

NodeMulti* createMultiLLNode(int data) {
    NodeMulti* newNode = (NodeMulti*)malloc(sizeof(NodeMulti));
    newNode->data = data;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) return;
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void printMultiList(NodeMulti* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node_randomList* createNode_randomList(int data)
{
    Node_randomList* newNode = (Node_randomList*)malloc(sizeof(Node_randomList));
    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

void insertAtEnd_randomList(Node_randomList** head, int data)
{
    Node_randomList* newNode = createNode_randomList(data);

    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }

    Node_randomList* temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void printList_randomList(Node_randomList* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        if (head->random)
            printf("(rand -> %d) ", head->random->data);
        else
            printf("(rand -> NULL) ");
        head = head->next;
    }
    printf("NULL\n");
}