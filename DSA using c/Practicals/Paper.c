#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

void printList(Node *head) {
    for (; head; head = head->next)
        printf("%d -> ", head->data);
    printf("NULL\n");
}

Node *deleteLastOccurrence(Node *head, int key) {
    Node *last = NULL, *prev = NULL, *curr = head;
    for (Node **p = &head; *p; p = &(*p)->next) {
        if ((*p)->data == key) {
            last = *p;
            prev = p;
        }
    }
    if (last) {
        *prev = last->next;
        free(last);
    }
    return head;
}

int main() {
    Node *head = NULL, **p = &head;
    int vals[] = {1,2,3,2,4,2};
    for (int i = 0; i < sizeof(vals)/sizeof(vals[0]); i++) {
        *p = createNode(vals[i]);
        p = &(*p)->next;
    }

    printf("Original list: ");
    printList(head);

    int key = 2;
    head = deleteLastOccurrence(head, key);

    printf("List after deleting last occurrence of %d: ", key);
    printList(head);

    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
