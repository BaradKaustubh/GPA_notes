#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;  
    struct node *next;
};

void displayList(struct node *head) {
    printf("\nDisplaying the linked list:\n");
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("HEAD -> ");
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct node *createNode(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("\nCreating new node with data: %d\n", data);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node *createLinkedList(struct node *head) {
    int data, more;
    struct node *current = NULL;
    printf("\n=== Creating Linked List ===\n");
    do {
        printf("\nEnter value for the new node: ");
        scanf("%d", &data);
        struct node *newNode = createNode(data);
        if(head == NULL) {
            head = current = newNode;
            printf("First node created and set as head\n");
        } else {
            current->next = newNode;
            current = newNode;
            printf("Node added to the end of the list\n");
        }
        printf("\nDo you want to add more nodes? (1 for Yes, 0 for No): ");
        scanf("%d", &more);
    } while(more);
    printf("\nLinked list creation completed!\n");
    return head;
}

struct node *insertAtBeginning(struct node *head, int data) {
    printf("\n=== Inserting at Beginning ===\n");
    struct node *newNode = createNode(data);
    newNode->next = head;
    printf("New node with data %d inserted at the beginning\n", data);
    return newNode;
}

struct node *searchNode(struct node *head, int data) {
    printf("\n=== Searching for %d in the list ===\n", data);
    int position = 1;
    struct node *temp = head;
    while(temp != NULL) {
        if(temp->data == data) {
            printf("Node with data %d found at position %d\n", data, position);
            return temp;
        }
        temp = temp->next;
        position++;
    }
    printf("Node with data %d not found in the list\n", data);
    return NULL;
}

int main() {
    printf("\n====== Linked List Operations ======\n");
    struct node *head = NULL;
    printf("\nInitializing empty linked list...\n");
    
    head = createLinkedList(head);
    printf("\nInitial List: ");
    displayList(head);
    
    printf("\nInserting 5 at the beginning of the list\n");
    head = insertAtBeginning(head, 5);
    printf("List after insertion: ");
    displayList(head);
    
    int searchKey = 5;
    printf("\nSearching for value %d in the list\n", searchKey);
    struct node *foundNode = searchNode(head, searchKey);
    if(foundNode)
        printf("Successfully found node with value %d!\n", searchKey);
    else
        printf("Failed to find node with value %d!\n", searchKey);
    
    printf("\n====== Program Completed ======\n");
    return 0;
}
