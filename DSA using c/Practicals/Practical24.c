#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

void enqueue(struct Node **head, int data, int priority)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    if (*head == NULL || priority < (*head)->priority) {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL && current->next->priority <= priority) {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}

int dequeue(struct Node **head)
{
    if (*head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    struct Node *temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL) {
        printf("Data: %d (Priority: %d)\n", current->data, current->priority);
        current = current->next;
    }
}

int main()
{
    struct Node *priorityQueue = NULL;
    
    enqueue(&priorityQueue, 4, 2);
    enqueue(&priorityQueue, 5, 1);
    enqueue(&priorityQueue, 6, 3);
    enqueue(&priorityQueue, 7, 0);
    
    printf("Priority Queue contents:\n");
    display(priorityQueue);
    
    printf("\nDequeuing elements:\n");
    for (int i = 0; i < 4; i++) {
        int data = dequeue(&priorityQueue);
        if (data != -1) {
            printf("Dequeued: %d\n", data);
        }
    }
    
    return 0;
}
