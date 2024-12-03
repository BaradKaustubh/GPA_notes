#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (!front) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (!front) printf("Empty\n");
    else {
        struct Node *temp = front;
        printf("Dequeued: %d\n", temp->data);
        front = front->next;
        if (!front) rear = NULL;
        free(temp);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    return 0;
}
