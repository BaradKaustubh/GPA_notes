// 12. Write a C Program to Implement Doubly Linked List with Operations: (i) Insert at end, (ii) Insert After, (iii) Delete (iv) Delete from given place (v) Delete at End (vi) Display

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtEnd(struct node *head, int data)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAfter(struct node *head, int data, int position)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteNode(struct node *head, int position)
{
    if (head == NULL)
    {
        return;
    }
    else if (position == 1)
    {
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else
    {
        struct node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        struct node *toDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        free(toDelete);
    }
}

void deleteAtEnd(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        struct node *toDelete = temp->next;
        temp->next = NULL;
        free(toDelete);
    }   
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    head = createNode(10);
    insertAtEnd(head, 20);
    display(head);
    insertAtEnd(head, 30);
    display(head);
    insertAtEnd(head, 40);
    display(head);
    insertAfter(head, 25, 3);
    display(head);
    deleteNode(head, 2);
    display(head);
    deleteAtEnd(head);
    display(head);
    return 0;
}