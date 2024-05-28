#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
struct Stack {
    int *items;
    int top;
    int capacity;
};

// Initialize the stack
void initializeStack(struct Stack *s, int size) {
    s->capacity = size;
    s->items = (int*)malloc(size * sizeof(int));
    if (!s->items) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == s->capacity - 1;
}

// Resize the stack
void resize(struct Stack *stack) {
    stack->capacity *= 2;
    stack->items = (int*)realloc(stack->items, stack->capacity * sizeof(int));
    if (!stack->items) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Stack resized to capacity %d\n", stack->capacity);
}

// Push an element onto the stack
void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        resize(stack);
    }
    stack->items[++stack->top] = data;
}

// Pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return -1 if the stack is empty
    }
    return stack->items[stack->top--];
}

// Display the elements of the stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
}

// Free the stack memory
void freeStack(struct Stack *stack) {
    free(stack->items);
}

int main() {
    struct Stack stack; // Allocate memory for the stack structure
    initializeStack(&stack, 3); // Initialize the stack with initial capacity

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30); // This will trigger a resize
    push(&stack, 40);

    // Display the stack
    display(&stack);

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    // Display the stack again
    display(&stack);

    // Free the stack memory
    freeStack(&stack);

    return 0;
}
