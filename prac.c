#include <stdio.h>
#include <stdlib.h>

struct node_tree {
    int value;
    struct node_tree* left;
    struct node_tree* right;   
};

struct node_tree* node_create(int value) {

    struct node_tree* node = (struct node_tree*)malloc(sizeof(struct node_tree));

    //error check
    if (node == NULL) {
        printf("no memory available");
        exit(1);
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct node_tree* node_insert(struct node_tree* root, int value) {

    //base case
    if (root == NULL) {
        return node_create(value);
    }

    if (value < root->value) {
        root->left = node_insert(root->left, value) ;
    } else {
        root->right = node_insert(root->right, value) ;
    }

    return root;
}

void tree_sum(struct node_tree* root, int* sum) {
    if (root != NULL) {
        tree_sum(root->left, sum);
        *sum += root->value;
        tree_sum(root->right, sum);
    }
}

void tree_free(struct node_tree* root) {
    if (root != NULL) {
        tree_free(root->left);
        tree_free(root->right);
        free(root);
    }
}

int main() {
    //initiliaze
    struct node_tree* root = NULL;

    //create bin tree
    root = node_insert(root, 50);
    root = node_insert(root, 10);
    root = node_insert(root, 90);
    root = node_insert(root, 100);
    root = node_insert(root, 0);
    root = node_insert(root, 25);
    root = node_insert(root, 75);
    
    //sum
    int sum = 0;
    tree_sum(root, &sum);
    printf("Sum: %d\n", sum);

    // Free memory
    tree_free(root);

    return 0;
}