#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    struct treeNode* right;
    struct treeNode* left;
    int data;
};

struct treeNode* createNode(int data) {
    //allocate size
    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));

    //error check
    if (newNode == NULL) {
        printf("no memory available");
        exit(1);
    }

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;

    //return
    return newNode;
};

struct treeNode* insertNode(struct treeNode* root, int data) {
    //BASE
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
};

void sumTree(struct treeNode* root, int* sum) {
    if (root != NULL) {
        sumTree(root->left, sum); // Traverse left subtree
        *sum += root->data; // Add current node's data to sum
        sumTree(root->right, sum); // Traverse right subtree
    }
}

int heightTree(struct treeNode* root) {
    //BASE
    if (root == NULL) {
        return -1;
    }

    //printf("%d ",root->data);

    int leftHeight = heightTree(root->left);
    int rightHeight = heightTree(root->right);
    //printf("\n");
    //printf("left: %d\n",leftHeight);
    //printf("right: %d\n",rightHeight);
    int height;

    if (leftHeight>rightHeight) {
        height = leftHeight+1;
    } else {
        height = rightHeight+1;
    }

    //printf("height %d\n",height);

    return height;
};

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

void freeTree(struct treeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    //initiliaze
    struct treeNode* root = NULL;

    //create bin tree
    root = insertNode(root, 50);
    root = insertNode(root, 10);
    root = insertNode(root, 90);
    root = insertNode(root, 100);
    root = insertNode(root, 0);
    root = insertNode(root, 25);
    root = insertNode(root, 75);
    root = insertNode(root, 60);
    root = insertNode(root, 40);

    //print tree
    printTree(root,0);
    printf("\n");
    
    //sum
    int sum = 0;
    sumTree(root, &sum);
    printf("Sum: %d\n", sum);

    //height
    int height = heightTree(root);
    printf("Height: %d\n", height);

    // Free memory
    freeTree(root);

    return 0;
}