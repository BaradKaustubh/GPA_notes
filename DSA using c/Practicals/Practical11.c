#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertAtEnd(struct node *head, int data) {
    struct node *newNode = createNode(data);
    if (!head) return newNode;
    struct node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

struct node* insertAfter(struct node *head, int data, int pos) {
    struct node *temp = head;
    for (int i = 1; i < pos && temp; i++) temp = temp->next;
    if (!temp) return head;
    struct node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct node* deleteAt(struct node *head, int pos) {
    if (!head) return NULL;
    if (pos == 1) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node *temp = head;
    for (int i = 1; i < pos-1 && temp; i++) temp = temp->next;
    if (!temp || !temp->next) return head;
    struct node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

struct node* deleteEnd(struct node *head) {
    if (!head || !head->next) {
        free(head);
        return NULL;
    }
    struct node *temp = head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

void display(struct node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    
    head = insertAtEnd(head, 10);
    display(head);
    head = insertAtEnd(head, 20);
    display(head);
    head = insertAtEnd(head, 30);
    display(head);
    head = insertAfter(head, 25, 2);
    display(head);
    head = deleteAt(head, 2);
    display(head);
    head = deleteEnd(head);
    display(head);
    
    return 0;
}
