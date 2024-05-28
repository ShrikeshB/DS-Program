#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head != NULL)
    {
        newNode->next = *head;
    }
    *head = newNode;
}

void pop(struct node **head)
{
    if (*head == NULL)
    {
        printf("list is empty");
        return;
    }
    else
    {
        struct node *tmp = *head;

        *head = (*head)->next;
        free(tmp);
    }
}

void display(struct node *head)
{
    printf("displaying..\n");
    if (head == NULL)
    {
        printf("list is empty");
        return;
    }
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int peek(struct node *head)
{
    if (head == NULL)
    {
        printf("list is empty");
        return;
    }
    else
        return head->data;
}

void reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev; // Update the head to point to the new first node
}
int main()
{
    struct node *head = NULL;
    int choice = 1;
    int n;
    while (choice)
    {
        printf("enter your choice\n1.push\n2.reverse\n3.display\n4.exit\n");
        scanf("%d", &choice);
        printf("---------------------------\n");
        switch (choice)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d", &n);
            push(&head, n);
            break;
        case 2:
            reverse(&head);
            break;

        case 3:
            display(head);
            break;
        case 4:
            printf("exit\n");
            exit(0);
        }
    }

    return 0;
}