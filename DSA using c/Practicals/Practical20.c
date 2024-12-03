#include <stdio.h>
#define MAX 5

int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    if (rear == MAX) printf("Queue is Full\n");
    else queue[rear++] = x;
}

void dequeue() {
    if (front == rear) printf("Queue is Empty\n");
    else printf("%d\n", queue[front++]);
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    return 0;
}
