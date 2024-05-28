#include <stdio.h>

struct student
{
    int id;
    char name[50];
    int sem;
    struct student *next;
};
struct student *head = NULL;

void insertAtFront()
{

    struct student *newNode = (struct student *)malloc(sizeof(struct student));

    int id, sem;
    char name[50];
    printf("\nenter the ID:");
    scanf("%d", &id);
    printf("\nenter the name:");
    scanf("%s", name);
    printf("\nenter the Sem:");
    scanf("%d", &sem);

    newNode->id = id;
    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->sem = sem;

    newNode->next = head;
    head = newNode;
    printf("at start");
}

void insertAtEnd()
{
    struct student *tmp;
    struct student *newNode = (struct student *)malloc(sizeof(struct student));

    int id, sem;
    char name[50];
    printf("\nenter the ID:");
    scanf("%d", &id);
    printf("\nenter the name:");
    scanf("%s", name);
    printf("\nenter the Sem:");
    scanf("%d", &sem);

    newNode->id = id;
    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->sem = sem;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        printf("at front");
    }
    else
    {
        tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        printf("end");
    }
}

int calSizeOfLL()
{
    int size = 0;
    struct student *tmp;
    tmp = head;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        size++;
    }

    return size;
}

void insertMid(int pos)
{
    int size = calSizeOfLL();
    struct student *tmp, *newNode;

    if (pos > size || pos < 1)
        printf("insertion is not possible\n");
    else
    {
        tmp = head;

        struct student *newNode = (struct student *)malloc(sizeof(struct student));

        int id, sem;
        char name[50];
        printf("\nenter the ID:");
        scanf("%d", &id);
        printf("\nenter the name:");
        scanf("%s", name);
        printf("\nenter the Sem:");
        scanf("%d", &sem);

        newNode->id = id;
        strncpy(newNode->name, name, sizeof(newNode->name));
        newNode->sem = sem;

        while (--pos)
        {
            tmp = tmp->next;
        }

        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

void deleteFront()
{
    if (head != NULL)
    {
        head = head->next;
    }
}

void deleteRear()
{
    struct student *tmp, *prev;
    if (head != NULL)
    {
        tmp = head;
        while (tmp->next != NULL)
        {
            prev = tmp;
            tmp = tmp->next;
        }

        prev->next = NULL;
    }
}

void deleteInPosition()
{
    int size = calSizeOfLL();
    printf("%d",size);
}

void display()
{
    struct student *tmp;
    if (head != NULL)
    {
        tmp = head;
        while (tmp != NULL)
        {

            printf("\n=================\n");
            printf("%d\n", tmp->id);
            printf("%s\n", tmp->name);
            printf("%d", tmp->sem);
            printf("\n=================\n");

            tmp = tmp->next;
        }
    }
}

int main()
{
    insertAtFront();
    insertAtEnd();
    insertAtEnd();
    deleteRear();
    // insertMid(2);
    display();

    return 0;
}