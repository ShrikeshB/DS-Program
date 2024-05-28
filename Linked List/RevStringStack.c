#include <stdio.h>
#include <string.h>
int maxSize = 50;
int top = -1;
int revTop = -1;

char stack[50];
char stackRev[50];
void push(char c, int size)
{
    if (top > size)
    {
        printf("Stack overflow\n");
        return;
    }

    top++;
    stack[top] = c;
}

char pop()
{
    if (top < 0)
    {
        printf("under flow\n");
        return;
    }

    char x = stack[top];
    top--;
    return x;
}

void reverseStr(int size)
{

    if (revTop > size)
    {
        printf("overflow\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        revTop++;
        stackRev[revTop] = pop();
    }
}

void display(int size)
{
    for (int i = 0; i < size; i++)
        printf("%c", stackRev[i]);
}

int main()
{

    char str[maxSize];
    printf("Enter the String:");
    scanf("%s", &str);
    int size = strlen(str);
    printf("len=%d\n",size);
    for (int i = 0; i < size; i++)
    {
        push(str[i], size);
    }
    reverseStr(size);
    display(size);
    return 0;
}