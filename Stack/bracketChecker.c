#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    char data;
    struct Node* next;
};

// Function to push a character onto the stack
void push(struct Node** top, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a character from the stack
char pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    struct Node* temp = *top;
    char data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to check if a character is an opening parenthesis
int isOpening(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

// Function to check if two characters form a valid pair of parentheses
int isPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

// Function to check if the expression has balanced parentheses
int isBalanced(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isOpening(exp[i])) {
            push(&stack, exp[i]);
        } else {
            if (stack == NULL || !isPair(pop(&stack), exp[i])) {
                return 0; // Unbalanced parentheses
            }
        }
    }

    // If stack is empty at the end, expression is balanced
    return (stack == NULL);
}

int main() {
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (isBalanced(exp)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression has unbalanced parentheses.\n");
    }

    return 0;
}
