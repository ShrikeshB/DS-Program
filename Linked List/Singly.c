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
    newNode->next = head;
    head = newNode;
}
struct node *insertEnd(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    // insert end...
    if (head == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
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
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct node *tmp = head;
        for (int i = 0; i < pos - 1 && tmp != NULL; i++)
        {
            tmp = tmp->next;
        }
        if (tmp == NULL)
        {
            printf("invalid position");
        }
        else
        {
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
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
        head = head->next;
        free(tmp);
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
    else if (head->next == NULL)
    {
        free(head);
        head = NULL; // Set head to NULL since the list is now empty
        return head;
    }
    else
    {
        struct node *tmp = head;
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        free(tmp->next);
        tmp->next = NULL;
    }
    return head;
}

struct node *delPos(struct node *head, int pos)
{
    // del pos...
    struct node *tmp = head;
    if (head == NULL)
    {
        printf("empty");
    }
    else if (pos == 0)
    {
        head = head->next;
        free(tmp);
    }
    else
    {
        struct node *prev = head;

        for (int i = 0; i < pos - 1 && tmp != NULL; i++)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        free(tmp);
    }

    return head;
}

struct node *delVal(struct node *head, int value)
{
    // del pos...
    struct node *tmp = head;
    if (head == NULL)
    {
        printf("empty");
    }
    else if (head->data == value)
    {
        head = head->next;
        free(tmp);
    }
    else
    {
        struct node *prev = head;

        while (tmp != NULL && tmp->data != value)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        free(tmp);
    }

    return head;
}

void display(struct node *head)
{
    if (head == NULL)
        printf("EMPTY");
    else
        while (head != NULL)
        {
            printf("%d->", head->data);
            head = head->next;
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
    head = insertEnd(head, 15);
    head = insertEnd(head, 16);
    head = insertEnd(head, 20);
    head = insertPos(head, 200, 2);

    display(head);
    // head = delEnd(head);
    head = delVal(head, 20);
    printf("\n");

    // head = reverse(head);
    display(head);
    return 0;
}