#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insertFront(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;

    if (head != NULL)
    {
        head->left = newNode;
    }
    newNode->right = head;

    head = newNode;
}
struct node *insertEnd(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;

    if (head == NULL)
    {
        newNode->right = head;
        head = newNode;
    }
    else
    {
        struct node *tmp = head;
        while (tmp->right != NULL)
        {
            tmp = tmp->right;
        }

        tmp->right = newNode;
        newNode->left = tmp;
    }
    return head;
}
struct node *insertPos(struct node *head, int data, int pos)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    if (pos == 0)
    {
        newNode->right = head;
        head = newNode;
    }
    else
    {
        struct node *tmp = head;
        for (int i = 0; i < pos - 1 && tmp != NULL; i++)
        {
            tmp = tmp->right;
        }
        if (tmp == NULL)
        {
            printf("invalid poss");
            return head;
        }
        else
        {
            newNode->right = tmp;
            newNode->left = tmp->left;
            tmp->left->right = newNode;
            tmp->left = newNode;
        }
    }
    return head;
}
struct node *delFront(struct node *head)
{
    if (head == NULL)
        printf("empty");
    else
    {
        struct node *tmp = head;
        head = head->right;
    }
    return head;
}
struct node *delEnd(struct node *head)
{
    if (head == NULL)
        printf("empty");
    else
    {
        struct node *tmp = head;
        while (tmp->right != NULL)
        {
            tmp = tmp->right;
        }
        tmp->left->right = NULL;
        free(tmp);
    }
    return head;
}
struct node *delPos(struct node *head, int pos)
{
    struct node *tmp = head;
    if (head == NULL)
    {
        printf("empty");
    }
    else if (pos == 1)
    {
        head = head->right;
        free(tmp);
    }
    else
    {
        for (int i = 0; i < pos - 1 && tmp != NULL; i++)
        {
            tmp = tmp->right;
        }

        if (tmp == NULL)
        {
            printf("Position exceeds list size\n");
            return head;
        }
        tmp->right->left = tmp->left;
        tmp->left->right = tmp->right;
    }
    return head;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("empty");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d->", head->data);
            head = head->right;
        }
    }
}

void main()
{
    // Your code goes here
    struct node *head = NULL;
    head = insertFront(head, 12);
    head = insertFront(head, 13);
    head = insertFront(head, 14);

    head = insertEnd(head, 14);
    head = insertEnd(head, 15);

    display(head);
    head = delPos(head, 5);
    printf("\n");
    // head = insertPos(head, 200, 2);

    display(head);
}