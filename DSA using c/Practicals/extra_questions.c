#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

void display(struct Node *head)
{
    for (struct Node *current = head; current; current = current->next)
        printf("%d -> ", current->value);
    printf("NULL\n");
}

int main()
{
    struct Node *head = malloc(sizeof(struct Node)), *last = head;
    head->value = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->value = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->value = 3;
    head->next->next->next = NULL;

    display(head);

    int newValue;
    printf("Enter value: ");
    scanf("%d", &newValue);

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = newValue;
    newNode->next = NULL;

    while (last->next)
        last = last->next;
    last->next = newNode;
    display(head);

    return 0;
}