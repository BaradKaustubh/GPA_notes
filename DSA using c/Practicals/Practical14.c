// Write a 'C' Program to add Two Polynomials using a Linked List.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff, pow;
    struct Node *next;
};

struct Node *createNode(int c, int p)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->coeff = c;
    node->pow = p;
    node->next = NULL;
    return node;
}

void insertNode(struct Node **poly, int c, int p)
{
    struct Node *newNode = createNode(c, p);
    if (!(*poly))
    {
        *poly = newNode;
    }
    else
    {
        struct Node *temp = *poly;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void addPolynomials(struct Node *poly1, struct Node *poly2, struct Node **result)
{
    while (poly1 && poly2)
    {
        if (poly1->pow == poly2->pow)
        {
            insertNode(result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow)
        {
            insertNode(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else
        {
            insertNode(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }
    while (poly1)
    {
        insertNode(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2)
    {
        insertNode(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
}

void display(struct Node *poly)
{
    while (poly)
    {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    insertNode(&poly1, 5, 2);
    insertNode(&poly1, 4, 1);
    insertNode(&poly1, 2, 0);

    insertNode(&poly2, 5, 1);
    insertNode(&poly2, 5, 0);

    addPolynomials(poly1, poly2, &result);

    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);
    printf("Sum: ");
    display(result);

    return 0;
}
