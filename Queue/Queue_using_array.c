#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct Queue
{
    int items[SIZE];
    int front;
    int rear;
};

void initializeQueue(struct Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue *queue)
{
    return queue->rear == -1;
}

int isFull(struct Queue *queue)
{
    return queue->rear == SIZE - 1;
}

void Enqueue(struct Queue *queue, int data)
{
    if (isFull(queue))
    {
        printf("queue is full\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;
    queue->items[++queue->rear] = data;
}

int Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("queue is empty\n");
        return -1;
    }
    int value = queue->items[queue->front++];

    if (queue->front > queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    return value;
}

void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents:\n");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d\n", queue->items[i]);
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
    Enqueue(&queue, 6); // queue is full
    display(&queue);
    printf("popped: %d\n", Dequeue(&queue));
    display(&queue);

    return 0;
}