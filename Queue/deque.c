#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Deque {
    int items[SIZE];
    int front;
    int rear;
    int count;
};

// Initialize the deque
void initializeDeque(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
    deque->count = 0;
}

// Check if the deque is empty
int isEmpty(struct Deque *deque) {
    return deque->count == 0;
}

// Check if the deque is full
int isFull(struct Deque *deque) {
    return deque->count == SIZE;
}

// Insert an element at the front
void insertFront(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full!\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + SIZE) % SIZE;
    }
    deque->items[deque->front] = data;
    deque->count++;
}

// Insert an element at the rear
void insertRear(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full!\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % SIZE;
    }
    deque->items[deque->rear] = data;
    deque->count++;
}

// Delete an element from the front
int deleteFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return -1;
    }

    int data = deque->items[deque->front];
    deque->front = (deque->front + 1) % SIZE;
    deque->count--;

    if (isEmpty(deque)) {
        deque->front = -1;
        deque->rear = -1;
    }

    return data;
}

// Delete an element from the rear
int deleteRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return -1;
    }

    int data = deque->items[deque->rear];
    deque->rear = (deque->rear - 1 + SIZE) % SIZE;
    deque->count--;

    if (isEmpty(deque)) {
        deque->front = -1;
        deque->rear = -1;
    }

    return data;
}

// Display the deque
void display(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque contents:\n");
    int i = deque->front;
    for (int c = 0; c < deque->count; c++) {
        printf("%d ", deque->items[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    struct Deque deque;
    initializeDeque(&deque);

    insertRear(&deque, 1);
    insertRear(&deque, 2);
    insertFront(&deque, 3);
    insertFront(&deque, 4);
    insertRear(&deque, 5);
    display(&deque);

    printf("Deleted from front: %d\n", deleteFront(&deque));
    display(&deque);

    printf("Deleted from rear: %d\n", deleteRear(&deque));
    display(&deque);

    return 0;
}
