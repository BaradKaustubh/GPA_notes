#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int c, e;
    struct n *x;
} N;

N *new(int c, int e)
{
    N *n = malloc(sizeof(N));
    n->c = c;
    n->e = e;
    n->x = 0;
    return n;
}

N *add(N *h, int c, int e)
{
    N *n = new (c, e);
    if (!h)
        return n;
    N *t = h;
    while (t->x)
        t = t->x;
    t->x = n;
    return h;
}

void show(N *h)
{
    while (h)
    {
        printf("%dx^%d%s", h->c, h->e, h->x ? " + " : "\n");
        h = h->x;
    }
}

int main()
{
    N *p = 0;
    p = add(p, 1, 2);
    p = add(p, 2, 1);
    p = add(p, 3, 0);
    printf("Polynomial: ");
    show(p);
    return 0;
}
