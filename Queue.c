#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int items[100];
    int front, back;
    int count;
};

void enqueue (struct Queue* queue, int value) {
    //error check
    if (queue->count == 100) {
        printf("Queue overflow! Cannot enqueue element %d\n", value);
        return;
    }

    //set front index in queue to be 0 if empty queue
    if (queue->count == 0) {
        queue->front = 0; 
    }

    //logic
    queue->back = (queue->back + 1) % 100;//ensures wrapping (101 % 100 = 1)
    queue->items[queue->back] = value;
    queue->count++;
}

int dequeue(struct Queue* queue) {
    //error check
    if (queue->count == 0) {
        printf("Queue underflow! Cannot dequeue element\n");
        return -1;
    }

    //declare dequeue
    int dequeued = queue->items[queue->front];

    //logic
    //if 1 element
    if (queue->front == queue->back) {
        queue->front = -1;
        queue->back = -1;
    } else {
        //increment front by 1 with wrapping
        queue->front = (queue->front + 1) % 100;
    }
    queue->count--; // Decrement count after dequeueing
    return dequeued;
}

// Function to peek at the front element of the queue without removing it
int peek(struct Queue *queue) {
    //error check
    if (queue->count == 0) {
        printf("Queue underflow! Cannot dequeue element\n");
        return -1;
    }

    int value = queue->items[queue->front];
    return value;
}

int main() {
    //initialize
    struct Queue queue;
    queue.back = -1;
    queue.front = -1;
    queue.count = 0;

    //Enqueue elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    //Print first element of queue
    printf("Front element of the queue %d\n", peek(&queue));

    // Dequeue elements from the queue and print them
    printf("Dequeued elements: ");
    while (queue.count != 0) {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    // Try to dequeue from an empty queue
    dequeue(&queue); // This will print "Queue underflow! Cannot dequeue element"

    return 0;
}