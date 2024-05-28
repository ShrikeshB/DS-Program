#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *items;
    int front;
    int rear;
    int capacity;
};


//! init Queue
void initializeQueue(struct Queue *queue, int size)
{
    queue->capacity = size;
    queue->items = (int *)malloc(queue->capacity * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
}

//! check Queue is Empty
int isEmpty(struct Queue *queue)
{
    return queue->rear == -1;
}

//! check queue is full
int isFull(struct Queue *queue)
{
    return queue->rear == queue->capacity - 1;
}


//! resize the queue 
void resize(struct Queue *queue) {
    queue->capacity *= 2;
    queue->items = (int *)realloc(queue->items, queue->capacity * sizeof(int));
}

//! add new element
void Enqueue(struct Queue *queue, int data)
{
    if (isFull(queue))
    {
        resize(queue);
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->items[++queue->rear] = data;
}


//! remove element
int Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty!\n");
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


//! display queue
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty!\n");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d\n", queue->items[i]);
}
int main()
{
    struct Queue queue;
    initializeQueue(&queue, 5);

    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    Enqueue(&queue, 4);
    Enqueue(&queue, 5);
    Enqueue(&queue, 6); // queue is full
    display(&queue);
    printf("Popped: %d\n", Dequeue(&queue));
    printf("Popped: %d\n", Dequeue(&queue));
    printf("Popped: %d\n", Dequeue(&queue));
    printf("Popped: %d\n", Dequeue(&queue));
    printf("Popped: %d\n", Dequeue(&queue));
    printf("Popped: %d\n", Dequeue(&queue));
    display(&queue);

    return 0;
}