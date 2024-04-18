#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode * createNode(int data) {
    //create
    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));

    //error if no memory for malloc
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    //define
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    //return
    return newNode;
};

struct treeNode* insertNode(struct treeNode* node, int data) {
    //BASE CASE
    if (node == NULL) {
        return createNode(data);
    }

    //Recursive Operation
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }

    //return
    return node;
};

void traverseTree(struct treeNode* root) {
    if (root != NULL) {
        traverseTree(root->left); //traverses all left options then print recursively
        printf("%d ",root->data); //prints the root
        traverseTree(root->right); //prints all right
        //can jump back if multiple branches
    }
}

void printTree(struct treeNode* root, int level) {
    if (root != NULL) {
        
        // Traverse right subtree
        printTree(root->right, level + 1);

        // Print current node with indentation
        for (int i = 0; i < level; i++) {
            printf("    ");
        }

        printf("%d\n", root->data);

        // Traverse left subtree
        printTree(root->left, level + 1);

    }
}

struct treeNode* searchTree(struct treeNode* root, int key) {
    if (root != NULL) {
        if (key == root->data) {
            return root;
        } else if (key < root->data) {
            return searchTree(root->left, key);
        } else {
            return searchTree(root->right, key);
        }
    }

    return NULL;
};

void freeTree(struct treeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    //create
    //struct TreeNode* root = NULL;
    //root = insertNode(root, 50);
    struct treeNode* root = createNode(50);

    // Insert nodes into the binary tree
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    //PRINT
    traverseTree(root);
    printf("\n");
    printTree(root,0);
    printf("\n");

    //SEARCH
    struct treeNode* key = searchTree(root, 30);
    if (key == NULL) {
        printf("key not found\n");
    } else {
        printf("key found\n");
    }

    // Free memory
    freeTree(root);
    
    return 0;
}