#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure for a doubly linked list
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

//! create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//! insert At Front
struct Node *insertAtFront(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->right = head;
    if (head != NULL)
        head->left = newNode;
    return newNode;
}

//! insert At Rear
struct Node *insertAtRear(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }

    struct Node *tmp = head;
    while (tmp->right != NULL)
    {
        tmp = tmp->right;
    }
    tmp->right = newNode;
    newNode->left = tmp;
    return head;
}

//! insert At Pos
struct Node *insertAtPos(struct Node *head, int data, int pos)
{
    struct Node *newNode = createNode(data);
    if (pos <= 1 || head == NULL)
    {
        newNode->right = head;
        if (head != NULL)
            head->left = newNode;
        return newNode;
    }

    struct Node *tmp = head;
    for (int i = 1; i < pos - 1 && tmp->right != NULL; i++)
    {
        tmp = tmp->right;
    }

    if (tmp->right == NULL)
    {
        tmp->right = newNode;
        newNode->left = tmp;
    }
    else
    {
        newNode->right = tmp->right;
        newNode->left = tmp;
        tmp->right->left = newNode;
        tmp->right = newNode;
    }

    return head;
}

struct Node *deleteFromFront(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head; 
    }

    printf("%d deleted!\n", head->data);
    struct Node* tmp = head;
    head = head->right;
    if (head != NULL) {
        head->left = NULL; 
    }
    free(tmp);
    return head;
}

//! delete from rear
struct Node *deleteFromRear(struct Node *head)
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return head;
    }
    // only single element exist the delete..
    if (head->right == NULL)
    {
        printf("%d deleted!\n", head->data);
        free(head);
        return NULL;
    }

    // more than single element exist the delete..
    struct Node *tmp = head;
    while (tmp->right != NULL)
        tmp = tmp->right;

    printf("%d deleted!\n", tmp->data);
    tmp->left->right = NULL;
    free(tmp);
    return head;
}

//! delete from position
struct Node *deleteAtPos(struct Node *head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (pos <= 1) {
        struct Node *toDelete = head;
        head = head->right;
        if (head != NULL) {
            head->left = NULL;
        }
        printf("%d deleted!\n", toDelete->data);
        free(toDelete);
        return head;
    }

    struct Node *tmp = head;
    for (int i = 1; i < pos - 1 && tmp->right != NULL; i++) {
        tmp = tmp->right;
    }

    if (tmp->right == NULL) {
        printf("No such position!\n");
        return head;
    }

    struct Node *toDelete = tmp->right;
    tmp->right = toDelete->right;
    if (toDelete->right != NULL) {
        toDelete->right->left = tmp;
    }

    printf("%d deleted!\n", toDelete->data);
    free(toDelete);

    return head;
}

//! display List
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("list is empty\n");
    }
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->right;
    }
    printf("NULL\n");
}

//! search element
void search(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }

    while (head != NULL && head->data != key)
        head = head->right;

    if (head == NULL)
        printf("%d doesn't exists\n", key);
    else
        printf("%d  exists\n", key);
}

int main()
{
    struct Node *head = NULL;
    head = insertAtRear(head, 10);
    head = insertAtRear(head, 20);
    head = insertAtRear(head, 30);
    head = insertAtRear(head, 40);
    head = insertAtPos(head, 100, 100);
    displayList(head);
    head = deleteAtPos(head, 5);
    displayList(head);
    // search(head, 100);
    return 0;
}
