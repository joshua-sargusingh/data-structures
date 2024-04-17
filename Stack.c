#include <stdio.h>

//define DS
struct Stack {
    int items[100];
    int top;
};

void push(struct Stack *stack, int value) {
    //error check for stack overflow
    if (stack->top == 99) {
        printf("stack overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

int pop(struct Stack *stack) {
    //error check for empty stack
    if (stack->top == -1) {
        printf("empty stack\n");
        return -1;
    }
    int popped = stack->items[stack->top];
    stack->top--;
    return popped;
}

int peek(struct Stack *stack) {
    //error check for empty stack
    if (stack->top == -1) {
        printf("empty stack\n");
        return -1;
    }

    int value = stack->items[stack->top];
    return value;
}

int main() {
    // Declare variable stack of struct Stack
    struct Stack stack;
    // Initialize top to -1 indicating an empty stack
    stack.top = -1;

    // Push elements to top of stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print the top element of the stack
    printf("Top element of the stack: %d\n", peek(&stack));

    // Pop elements from the stack and print them
    printf("Popped elements: ");
    while (stack.top != -1) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

     // Try to pop from an empty stack

    // Try to pop from an empty stack
    pop(&stack); // This will print "Stack underflow! Cannot pop element"

    return 0;
}