#include <stdio.h>

struct node{
    int data;
    struct node* next;
};

struct node* getNewNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
}

void insertFront(struct node** head, int data){
    struct node* newNode = getNewNode(data);
    if((*head) == NULL){
        head = newNode;
    }
}

int main() {
    struct node* head = NULL;

    return 0;
}