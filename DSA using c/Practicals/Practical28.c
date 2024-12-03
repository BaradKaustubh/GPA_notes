#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left, *right;
};

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert(struct Node *node, int value)
{
    if (!node)
        return createNode(value);
    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    return node;
}

int findLargest(struct Node *node)
{
    while (node && node->right)
        node = node->right;
    return node->value;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Largest node in BST: %d\n", findLargest(root));
    return 0;
}
