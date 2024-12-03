#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int s[MAX], t = -1;

void push(int x) {
    if(t == MAX-1) printf("Overflow!");
    else printf("Pushed: %d", s[++t] = x);
}

void pop() {
    if(t < 0) printf("Underflow!");
    else printf("Popped: %d", s[t--]);
}

void show() {
    if(t < 0) printf("Empty!");
    else while(t >= 0) printf("%d ", s[t--]);
}

int main() {
    int n, c;
    do {
        printf("\n1.Push 2.Pop 3.Show 4.Exit\nChoice: ");
        scanf("%d", &c);
        switch(c) {
            case 1: printf("Value: "); scanf("%d", &n); push(n); break;
            case 2: pop(); break;
            case 3: show(); break;
            case 4: exit(0);
            default: printf("Invalid!\n");
        }
    } while(1);
}