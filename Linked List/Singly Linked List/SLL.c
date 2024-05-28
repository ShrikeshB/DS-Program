#include <stdio.h>
#include <stdlib.h>

//! creation of struct
struct Node
{
    int data;
    struct Node *next;
};

//! creation of new newNode
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // if failed to allocate the memory
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//! insert the new node on LL
struct Node *insertAtFront(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode; // Directly return the new head
}

//! insert at rear
struct Node *insertAtRear(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = head;
        return newNode; // If the list is empty, return the new node as the head
    }
    else
    {
        struct Node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return head; // Return the original head
}

//! insert at position
struct Node *insertAtPos(struct Node *head, int data, int pos)
{
    struct Node *newNode = createNode(data);
    if (head == NULL || pos <= 1)
    {
        newNode->next = head;
        return newNode;
    }

    struct Node *tmp = head;
    for (int i = 1; i < pos - 1 && tmp->next != NULL; i++)
    {

        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    return head;
}

//! delete at front
struct Node *deleteAtFront(struct Node *head)
{
    if (head == NULL)
    {
        printf("nothing to delete!\n");
        return head;
    }

    struct Node *tmp = head;
    printf("%d deleted!\n", head->data);
    head = head->next;
    free(tmp);
    return head;
}

//! delete at rear
struct Node *deleteAtRear(struct Node *head)
{
    if (head == NULL)
    {
        printf("nothing to delete!\n");
        return head;
    }

    // single element in list
    if (head->next == NULL)
    {
        printf("%d deleted!\n", head->data);
        free(head);
        return NULL;
    }

    // more the 1 element
    struct Node *tmp = head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    printf("%d deleted!\n", tmp->next->data);
    free(tmp->next);
    tmp->next = NULL;
    return head;
}

//! delete at position
struct Node *deleteAtPosition(struct Node *head, int pos)
{
    if (head == NULL)
    {
        printf("nothing to delete!");
        return head;
    }

    if (pos == 1)
    {
        struct Node *tmp = head;
        printf("%d deleted!\n", head->data);
        head = head->next;
        free(tmp);
        return head;
    }

    struct Node *tmp = head;
    struct Node *prev = NULL;
    for (int i = 1; i < pos && tmp != NULL; i++)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        printf("No such position!\n");
        return head;
    }

    printf("%d deleted!\n", tmp->data);
    prev->next = tmp->next;
    free(tmp);
    return head;
}

//! display List
void displayList(struct Node *head)
{

    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

//! search from list
void search(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }

    struct Node *tmp = head;
    while (tmp != NULL && tmp->data != key)
        tmp = tmp->next;

    if (tmp == NULL)
    {
        printf("no data found!\n");
    }
    else
    {
        printf("%d found!\n", tmp->data);
    }
}

//! reverse the Linked list
struct Node *reverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return head;
    }

    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next_node = NULL;
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
    struct Node *head = NULL;
    head = insertAtFront(head, 10);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 30);
    head = insertAtPos(head, 40, 4);

    displayList(head);
    // head = deleteAtPosition(head, 4);
    // head = reverse(head);
    displayList(head);
    return 0;
}