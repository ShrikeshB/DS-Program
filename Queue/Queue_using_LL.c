#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void initializeQueue(struct Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

void Enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    // if queue is empty
    if (queue->front == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("queue is empty!\n");
        return -1;
    }

    struct Node *tmp = queue->front;
    queue->front = queue->front->next;
    int value = tmp->data;
    free(tmp);
    if (queue->front == NULL)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }

    return value;
}

void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("queue is empty!\n");
        return;
    }

    struct Node *tmp = queue->front;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int main()
{
    struct Queue queue;
    initializeQueue(&queue);

    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    Enqueue(&queue, 4);
    Enqueue(&queue, 5);
    display(&queue);

    printf("Dequeued: %d\n", Dequeue(&queue));
    display(&queue);

    return 0;
}