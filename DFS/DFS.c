#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Stack
{
    int items[MAX_NODES];
    int top;
};

void initializeStack(struct Stack *s)
{
    s->top = -1;
}

bool isStackEmpty(struct Stack *s)
{
    return s->top == -1;
}

bool isStackFull(struct Stack *s, int n)
{
    return s->top == n - 1;
}

void push(struct Stack *s, int data)
{
    if (isStackFull(s, MAX_NODES))
    {
        printf("Stack is full.\n");
        return;
    }
    s->top++;
    s->items[s->top] = data;
}

int pop(struct Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    int data = s->items[s->top];
    s->top--;
    return data;
}

void DFS(int graph[][MAX_NODES], int source, int n)
{
    bool visited[MAX_NODES] = {false};
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, source);
    visited[source] = true;

    while (!isStackEmpty(&stack))
    {
        int currentNode = pop(&stack);
        printf("%d ", currentNode);

        for (int i = n - 1; i >= 0; i--)
        {
            if (graph[currentNode][i] == 1 && !visited[i])
            {
                push(&stack, i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int numNodes;

    int graph[MAX_NODES][MAX_NODES] = {{0, 1, 1, 0, 0},
                                       {0, 0, 1, 1, 0},
                                       {0, 1, 0, 0, 1},
                                       {0, 1, 0, 0, 1},
                                       {0, 0, 1, 1, 0}};

    printf("DFS Traversal: ");
    DFS(graph, 0, 5);

    return 0;
}
