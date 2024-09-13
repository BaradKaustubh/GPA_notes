#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50

typedef struct Customer
{
    int id;
    char name[MAX_NAME_LEN];
    struct Customer *next;
} Customer;

typedef struct Queue
{
    Customer *front;
    Customer *rear;
    int count;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->count = 0;
    return q;
}

Customer *createCustomer(int id, const char *name)
{
    Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
    newCustomer->id = id;
    strncpy(newCustomer->name, name, MAX_NAME_LEN);
    newCustomer->next = NULL;
    return newCustomer;
}

void enqueue(Queue *q, int id, const char *name)
{
    Customer *newCustomer = createCustomer(id, name);
    if (q->rear == NULL)
    {
        q->front = q->rear = newCustomer;
    }
    else
    {
        q->rear->next = newCustomer;
        q->rear = newCustomer;
    }
    q->count++;
    printf("Customer %s with ID %d added to the queue.\n", name, id);
}

void dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty, no customers to serve.\n");
        return;
    }
    Customer *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    printf("Customer %s with ID %d has been served.\n", temp->name, temp->id);
    free(temp);
    q->count--;
}

void displayQueue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    Customer *temp = q->front;
    printf("Customers in the queue:\n");
    while (temp != NULL)
    {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

int main()
{
    Queue *q = createQueue();
    int choice, id;
    char name[MAX_NAME_LEN];

    while (1)
    {
        printf("\nOnline Ticket Booking System\n");
        printf("1. Book Ticket\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter customer ID: ");
            scanf("%d", &id);
            printf("Enter customer name: ");
            scanf("%s", name);
            enqueue(q, id, name);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            displayQueue(q);
            break;
        case 4:
            printf("Exiting the system.\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}
