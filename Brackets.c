#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    char phrase[100];
};

void push(struct Stack* stack, char brack) {
    //error if full
    if (stack->top == 99) {
        printf("stack overflow\n");
        return;
    }

    //do
    stack->top++;
    stack->phrase[stack->top] = brack;
}

char pop(struct Stack* stack) {
    //error check
    if (stack->top == -1) {
        printf("empty stack\n");
        exit(1);
    }

    char popped = stack->phrase[stack->top];
    stack->top--;

    return popped;
}

int main() {

    //intialize
    struct Stack stack;
    //set
    stack.top = -1;

    //declare var
    char brack;
    char str[100];
    int i = 0;

    //read in
    while (scanf("%c", &brack) == 1 && brack != '\n') {
        str[i] = brack; // Store the character in the array
        i++;         // Move to the next index
    }
    str[i] = '\0'; // Null-terminate the string

    //push first element
    push(&stack,str[0]);

    for (int j = 1; str[j] != '\0'; ++j) {
        //declare
        char prev = pop(&stack);
        char curr = str[j];

        //logic
        if ((prev == '[' && curr == ']') ||
            (prev == '(' && curr == ')') ||
            (prev == '{' && curr == '}')) {
            push(&stack, str[j+1]);
            ++j;

        } else {
            printf("false\n");
            exit(1);
        }

        prev = curr;
   }

    // Check if stack is empty after processing the string
    if (stack.top == 0) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}