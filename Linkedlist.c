#include <stdio.h>
#include <stdlib.h>

//define DS
struct Node {
    int data;
    struct Node* next;
};

//newNode Creation
//struct Node* is a pointer of Node ds
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    //error check
    if (newNode == NULL) {
        printf("no memory room\n");
        exit(1);
    }
    //assign
    newNode->data = data;
    newNode->next = NULL;
    //return
    return newNode;
};

//insert Node at beginning of linked list
void insertatBeg(struct Node** headref, int data) {
    struct Node* newNode =  createNode(data);
    //reassign next
    //Here, the next pointer of the newly created node (newNode) is set to point to the current first node in the linked list, which is pointed to by *headref
    newNode->next=*headref;
    //change headref
    *headref = newNode;
}

/*
void insertAtEnd(struct Node** headref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *headref;

    // If the list is empty, make the new node the head
    if (*headref == NULL) {
        *headref = newNode;
        return;
    }

    // Traverse to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    // Link the new node at the end of the list
    current->next = newNode;
}
*/

void printRev(struct Node* head) {

    //return if nothing
    if (head == NULL) {
        return;
    }

    //recursive
    printRev(head->next);
    
    printf("%d ", head->data);

    /*while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");*/
}

int main () {

    //initialize empty linked list
    struct Node* head = NULL;
    int num;

    while (1) {

        scanf("%d", &num);

        if (num == -1) {
            break;
        }
        
        insertatBeg(&head, num);
    }

    printRev(head);
    printf("\n");
    
    return 0;
}