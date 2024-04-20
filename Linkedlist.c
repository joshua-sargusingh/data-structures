#include <stdio.h>
#include <stdlib.h>

//define ds
struct node {
    int data;
    struct node* next;
};

//struct node* is a pointer to a node ds
struct node* node_create(const int data) {

    struct node* node_new = (struct node*)malloc(sizeof(struct node));

    //error check
    if (node_new == NULL) {
        printf("memory allocation error");
        exit(1);
    }

    //assign
    node_new->data = data;
    node_new->next = NULL;

    return node_new;
}

void node_insert_beg(struct node** head, const int data) {

    struct node* node = node_create(data);

    node->next = *head; //reassign next
    *head = node; //change head
}

void node_insert_end(struct node** head, const int data) {

    struct node* node = node_create(data);
    struct node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}

void node_print(struct node** head) {

    struct node* current = *head;

    while (current != NULL) {
        printf("%d ",current->data);
        current = current->next;
    }

    printf("\n");
}

void node_free_all(struct node** head) {

    struct node* current = *head;
    
    while (current->next != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {

    //initialize empty linked list
    struct node* head = NULL;

    int num;
    printf("Enter data to store in linked list (-1 to quit):\n");

    while (scanf("%d",&num) == 1 && num != -1) {
        node_insert_beg(&head, num);
    }

    node_print(&head);
    node_free_all(&head);
    
    return 0;
}