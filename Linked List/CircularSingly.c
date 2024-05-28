#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertFront(struct node *head, int data)
{
    // insert front...
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (head == NULL)
        newNode->next = newNode;
    else
    {
        struct node *tmp = head;
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    return newNode;
}
struct node *insertEnd(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    // insert end...
    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        struct node *tmp = head;
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->next = head;
    }
    return head;
}
struct node *insertPos(struct node *head, int data, int pos)
{
    // insert pos...
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    // insert end...
    if (pos == 0 || head == NULL)
    {
        head = insertFront(head, data);
    }
    else
    {
        struct node *tmp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }

        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    return head;
}
struct node *delFront(struct node *head)
{
    // del front...
    if (head == NULL)
    {
        printf("empty");
    }
    else
    {
        struct node *tmp = head;
        struct node *tmp1 = head;
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }
        head = head->next;
        tmp->next = head;
        free(tmp1);
    }
    return head;
}
struct node *delEnd(struct node *head)
{
    // del end...
    if (head == NULL)
    {
        printf("empty");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL; // Set head to NULL since the list is now empty
        return head;
    }
    else
    {
        struct node *tmp = head;
        while (tmp->next->next != head)
        {
            tmp = tmp->next;
        }
        free(tmp->next);
        tmp->next = head;
    }
    return head;
}

void display(struct node *head)
{
    if (head == NULL)
        printf("EMPTY");
    else
    {

        struct node *tmp = head;
        do
        {
            printf("%d->", tmp->data);
            tmp = tmp->next;
        } while (tmp != head);
    }
}

struct node *reverse(struct node *head)
{
    struct node *current = head;
    struct node *prev = NULL;
    struct node *next_node = NULL;
    while (current != NULL)
    {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    head = prev;
    return head;
}

int main()
{
    struct node *head = NULL;
    head = insertEnd(head, 12);
    head = insertEnd(head, 13);
    head = insertEnd(head, 14);
    head = insertPos(head, 200, 1);
    display(head);
    head = delEnd(head);
    printf("\n");
    display(head);
    return 0;
}