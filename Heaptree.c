#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* right;
    struct Node* left;
    int data;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    //error
    if (node == NULL) {
        printf("Memory Allocatiuon Failed");
    }

    node->left = NULL;
    node->right = NULL;
    node->data = data;

    return node;
};

int isMaxHeap(struct Node* root) {
    //BASE
    if (root == NULL) {
        return 1;
    }

    if (root->left != NULL && root->left->data > root->data) {
        return 0;
    }

    if (root->right != NULL && root->right->data > root->data) {
        return 0;
    }

    return isMaxHeap(root->left) && isMaxHeap(root->right);
}

int isMinHeap(struct Node* root) {
    //BASE
    if (root == NULL) {
        return 1;
    }

    if (root->left != NULL && root->left->data < root->data) {
        return 0;
    }

    if (root->right != NULL && root->right->data < root->data) {
        return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    //INIT
    struct Node* root = createNode(5);

    //others
    root->left = createNode(6);
    root->right = createNode(7);
    root->left->left = createNode(8);
    root->left->right = createNode(9);
    root->right->left = createNode(10);
    root->right->right = createNode(11);
    root->left->left->left = createNode(12);
    root->left->left->right = createNode(13);
    root->left->right->left = createNode(14);

    //HEAP?
    if (isMinHeap(root)) {
        printf("Given binary tree is a Min Heap\n");
    } else if (isMaxHeap(root)) {
        printf("Given binary tree is a Max Heap\n");
    } else {
        printf("Given binary tree is not a Heap\n");
    }

    //FREE
    freeTree(root);

    return 0;
}