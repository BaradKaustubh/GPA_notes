// #include <stdio.h>
// #include <stdlib.h>
// struct Node {
//     int data;
//     struct Node *left, *right;
// };
// struct Node *createNode(int data) {
//     struct Node *newNode = malloc(sizeof(struct Node));
//     if (!newNode) {
//         printf("Memory allocation failed!\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }
// struct Node *add(struct Node *root, int data) {
//     if (!root)
//         return createNode(data);
//     if (data < root->data)
//         root->left = add(root->left, data);
//     else if (data > root->data)
//         root->right = add(root->right, data);
//     return root;
// }
// void preOrder(struct Node *root) {
//     if (!root)
//         return;
//     printf("%d ", root->data);
//     preOrder(root->left);
//     preOrder(root->right);
// }
// void inOrder(struct Node *root) {
//     if (!root)
//         return;
//     inOrder(root->left);
//     printf("%d ", root->data);
//     inOrder(root->right);
// }
// void postOrder(struct Node *root) {
//     if (!root)
//         return;
//     postOrder(root->left);
//     postOrder(root->right);
//     printf("%d ", root->data);
// }
// void freeTree(struct Node *root) {
//     if (!root)
//         return;
//     freeTree(root->left);
//     freeTree(root->right);
//     free(root);
// }
// int main() {
//     struct Node *root = NULL;
//     int values[] = {50, 30, 20, 40, 70, 60, 80};
//     int n = sizeof(values) / sizeof(values[0]);
//     for (int i = 0; i < n; i++)
//         root = add(root, values[i]);
//     printf("Inorder traversal   : ");
//     inOrder(root);
//     printf("\nPreorder traversal  : ");
//     preOrder(root);
//     printf("\nPostorder traversal : ");
//     postOrder(root);
//     printf("\n");
//     freeTree(root);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *l, *r;
};
struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->l = node->r = NULL;
    return node;
}
struct Node *insert(struct Node *node, int data)
{
    if (!node)
        return createNode(data);
    if (data < node->data)
        node->l = insert(node->l, data);
    else if (data > node->data)
        node->r = insert(node->r, data);
    return node;
}
int preOrder(struct Node *node)
{
    if (!node)
        return 0;
    printf("%d ", node->data);
    preOrder(node->l);
    preOrder(node->r);
}
int inOrder(struct Node *node)
{
    if (!node)
        return 0;
    inOrder(node->l);
    printf("%d ", node->data);
    inOrder(node->r);
}
int postOrder(struct Node *node)
{
    if (!node)
        return 0;
    postOrder(node->l);
    postOrder(node->r);
    printf("%d ", node->data);
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
    printf("Preorder traversal: ");
    preOrder(root);
    printf("\nInorder traversal: ");
    inOrder(root);
    printf("\nPostorder traversal: ");
    postOrder(root);
    return 0;
}

