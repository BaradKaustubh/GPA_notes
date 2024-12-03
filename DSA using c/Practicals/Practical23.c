#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *f, *r;

void enqueue(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    if(!f) {
        f = r = n;
        n->next = f;
    } else {
        n->next = f;
        r->next = n;
        r = n;
    }
    printf("Enqueue: %d\n", x);
}

void dequeue() {
    if(!f) printf("Queue Underflow\n");
    else if(f == r) {
        printf("Dequeue: %d\n", f->data);
        free(f);
        f = r = NULL;
    } else {
        struct Node *t = f;
        printf("Dequeue: %d\n", t->data);
        f = f->next;
        r->next = f;
        free(t);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    return 0;
}
