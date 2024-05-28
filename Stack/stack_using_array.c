#include <stdio.h>
#define SIZE 5
struct Stack
{
    int items[SIZE];
    int top;
};

//! initialize the stack
void createStack(struct Stack *s)
{
    s->top = -1;
}

//! check if stack is empty
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

//! check if stack is full
int isFull(struct Stack *s)
{
    return s->top == SIZE - 1;
}

void push(struct Stack *s, int data)
{
    if (isFull(s))
    {
        printf("stack is full");
        return;
    }

    s->top++;
    s->items[s->top] = data;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is empty");
        return -1;
    }
    return s->items[s->top--];
}

void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is empty");
        return;
    }

    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->items[i]);
    }
}

int main()
{
    struct Stack stack;
    createStack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Display the stack
    display(&stack);

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    // Display the stack again
    display(&stack);
    return 0;
}