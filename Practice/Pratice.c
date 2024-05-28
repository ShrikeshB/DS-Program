#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue
{
    int *items;
    int front;
    int rear;
};

void createQueue(struct Queue *q, int n)
{
    q->items = (int *)malloc(n * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct Queue *q)
{
    return q->rear == -1;
}

bool isFull(struct Queue *q, int n)
{
    return q->rear == n - 1;
}

void enqueue(struct Queue *q, int data, int n)
{
    if (isFull(q, n))
    {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->rear++;
    q->items[q->rear] = data;
}

int dequeue(struct Queue *q)
{
    int item = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}

void BFS(int graph[][100], int source, int n)
{
    struct Queue q;
    createQueue(&q, n);
    bool visited[100] = {false};

    visited[source] = true;
    enqueue(&q, source, n);

    while (!isEmpty(&q))
    {
        int currentNode = dequeue(&q);
        printf("%d ", currentNode);

        for (int i = 0; i < n; i++)
        {
            if (graph[currentNode][i] == 1 && !visited[i])
            {
                visited[i] = true;
                enqueue(&q, i, n);
            }
        }
    }
}

int main()
{
    int numNodes, startNode;

    int graph[100][100] = {{0, 1, 1, 0, 0},
                           {0, 0, 1, 1, 0},
                           {0, 1, 0, 0, 1},
                           {0, 1, 0, 0, 1},
                           {0, 0, 1, 1, 0}};

    printf("BFS Traversal: ");
    BFS(graph, 0, 5);

    return 0;
}
