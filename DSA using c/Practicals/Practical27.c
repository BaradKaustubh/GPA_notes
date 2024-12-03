#include <stdio.h>
#include <stdlib.h>
struct Node {int data; struct Node *l,*r;};
struct Node *createNode(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->l = node->r = NULL;
    return node;
}
struct Node *insert(struct Node *node, int data) {
    if(!node) return createNode(data);
    if(data < node->data) node->l = insert(node->l, data);
    else if(data > node->data) node->r = insert(node->r, data);
    return node;
}
int height(struct Node *node) {
    if(!node) return 0;
    int left = height(node->l), right = height(node->r);
    return (left > right ? left : right) + 1;
}
int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30); insert(root, 20); insert(root, 40);
    insert(root, 70); insert(root, 60); insert(root, 80);
    insert(root, 15); insert(root, 25); insert(root, 35);
    insert(root, 45); insert(root, 55); insert(root, 65);
    insert(root, 75); insert(root, 85);
    printf("Height of tree: %d\n", height(root));
    return 0;
}