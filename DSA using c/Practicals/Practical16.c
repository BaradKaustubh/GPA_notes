#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
} *Top;

void push(int v){
    struct Node *n = malloc(sizeof(struct Node));
    n->data = v;
    n->next = Top;
    Top = n;
}

void pop(){
    if(!Top) printf("Empty!\n");
    else {
        printf("%d\n", Top->data);
        struct Node *t = Top;
        Top = Top->next;
        free(t);
    }
}

void show(){
    for(struct Node *t=Top; t; t=t->next)
        printf("%d ", t->data);
    printf("\n");
}

int main(){
    int n, c;
    do{
        printf("\n1.Push 2.Pop 3.Show 4.Exit\nChoice: ");
        scanf("%d", &c);
        switch(c){
            case 1: printf("Value: "); scanf("%d", &n); push(n); break;
            case 2: pop(); break;
            case 3: show(); break;
            case 4: exit(0);
            default: printf("Invalid!\n");
        }
    }while(1);
}