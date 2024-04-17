#include <stdio.h>
#include <stdlib.h>

//define LL
struct Node {
    int data;
    struct Node* next;
};

//Create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    //error
    if (newNode == NULL) {
        exit(1);
    }

    //create New Node
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
};

void insertAtBeg(struct Node** headref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headref;
    *headref = newNode;
}

void printList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    printList(head->next);
    printf("%d ",head->data);
}

/*void removeTwo(struct Node** headref) {
    //empty check
    if (*headref == NULL) {
        return;
    }

    //create temp and previous
    struct Node* current = *headref;
    struct Node* previous = NULL;

    //while
    while (current != NULL) {

        //standard removal
        if (current->data == 2) {

            //check first node
            if (previous == NULL) {
                *headref = current->next;
            } 
            // standard case
            else {
                previous->next = current->next;
            }
            //free up space and change current
            free(current);
            current = previous->next;
        }

        //else reset current and previous for next loop
        previous = current;
        current = current->next;
    }

}*/

void removeTwo(struct Node** headref) {
    
    // If the list is empty, return
    if (*headref == NULL) {
        return;
    }

    // Temporary pointer to traverse the list
    struct Node* current = *headref;
    // Pointer to keep track of the previous node
    struct Node* prev = NULL;

    // Traverse the list
    while (current != NULL) {
        // If the current node contains the specified value, remove it
        if (current->data == 2) {
            // If the node to be removed is the first node (head)
            if (prev == NULL) {
                *headref = current->next; // Update the head pointer
            } else {
                prev->next = current->next; // Remove the current node
            }
            free(current); // Free memory allocated for the current node
            current = prev->next; // Move to the next node
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }
}

int main() {

    //initialize LL
    struct Node* head = NULL;

    insertAtBeg(&head, 2);
    insertAtBeg(&head, 4);
    insertAtBeg(&head, 2);
    insertAtBeg(&head, 3);
    insertAtBeg(&head, 2);
    insertAtBeg(&head, 2);
    insertAtBeg(&head, 1);

    printf("Original Linked List: ");
    printList(head);
    printf("\n");

    printf("New Linked List: ");
    removeTwo(&head);
    printList(head);
    printf("\n");

    return 0;
}