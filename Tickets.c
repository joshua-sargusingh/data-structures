#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Queue {
    struct Ticket* line[SIZE];
    int front, back;
    int count;
};

struct Ticket {
    int seat_num;
    int serial_num;
};

struct Ticket* new_ticket(int seat, int serial) {
    struct Ticket* new_ticket = (struct Ticket*)malloc(sizeof(struct Ticket));
    
    if (new_ticket == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_ticket->seat_num = seat;
    new_ticket->serial_num = serial;

    return new_ticket;
}

void enqueue(struct Queue* queue, struct Ticket* ticket) {
    if (queue->count > SIZE-1) {
        printf("overflow");
        exit(1);
    }

    if (queue->count == 0) {
        //first
        queue->front = 0;  
    }
    
    //other
    queue->back++;
    queue->line[queue->back] = ticket;
    queue->count++;
}

void dequeue_all(struct Queue* queue) {
    if (queue->count == 0) {
        printf("no queue");
        exit(1);
    }

    while (queue->count != 0) {
        //current
        struct Ticket *current = queue->line[queue->front];
        printf("Seat: %d, SN: %d\n", current->seat_num, current->serial_num);
        free(current);
        queue->count--;
        queue->front++;
    }
}

int main() {
    //init
    struct Queue queue;

    queue.count = 0;
    queue.back = -1;
    queue.front = -1;

    //new ticket
    enqueue(&queue, new_ticket(1,111));
    enqueue(&queue, new_ticket(2,222));
    enqueue(&queue, new_ticket(3,333));

    //dequeue
    printf("Dequeued List:\n");
    
    dequeue_all(&queue);

    return 0;
}