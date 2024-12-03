// #include <stdio.h>
// #define MAX 5

// int queue[MAX], front = 0, rear = 0;

// void enqueue(int value)
// {
//     if (rear == MAX)
//         printf("Queue Overflow\n");
//     else
//     {
//         queue[rear++] = value;
//         printf("Enqueue: %d\n", value);
//     }
// }

// void dequeue()
// {
//     if (front == rear)
//         printf("Queue Underflow\n");
//     else
//         printf("Dequeue: %d\n", queue[front++]);
// }

// int main()
// {
//     enqueue(10);
//     enqueue(20);
//     dequeue();
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int arr[MAX], front = 0, rear = 0;

void enqueue(int value)
{
    if (rear == MAX)
        printf("Queue Overflow\n");
    else
        arr[rear++] = value;
}
\
void dequeue()
{
    if (front == rear)
        printf("Queue Underflow\n");
    else
        printf("Dequeue: %d\n", arr[front++]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    dequeue();
    return 0;
}
