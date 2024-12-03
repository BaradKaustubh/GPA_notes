#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printReverse(struct Node *head) {
    if (head) {
        printReverse(head->next);
        printf("%d ", head->data);
    }
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));
    head->data = 1;
    second->data = 2; 
    third->data = 3;
    head->next = second;
    second->next = third;
    third->next = NULL;
    printf("Original: ");
    struct Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    printf("Reversed: ");
    printReverse(head);
    printf("\n");
    return 0;
}
