#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

void insertFront(node **head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (*head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertRear(node **head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (*head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}



void display(node *head)
{
    if (head == NULL)
    {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }

    node *tmp = head;
    do
    {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    } while (tmp != head);
    printf("\n");
    tmp = head->prev;
    do
    {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    } while ((tmp != head->prev));
}

int main()
{
    // Your code goes here
    node *head = NULL;
    insertRear(&head, 1);
    insertRear(&head, 2);
    insertRear(&head, 3);
    display(head);
    return 0;
}