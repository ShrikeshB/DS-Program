#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

void initializeStack(struct Stack *stack)
{
    stack->top = NULL;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

void push(struct Stack *stack, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }

    struct Node *tmp = stack->top;
    stack->top = stack->top->next;
    int poppedData = tmp->data;
    free(tmp);
    return poppedData;
}
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }

    struct Node *tmp = stack->top;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}
int main()
{
    struct Stack stack;
    initializeStack(&stack);
    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    // Display the stack
    display(&stack);

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    display(&stack);
    return 0;
}