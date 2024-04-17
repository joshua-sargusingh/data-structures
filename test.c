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
    struct Stack stack;
    stack.top = -1;

    char text[100];
    char bracket;
    int i = 0;

    //read
    while (scanf("%c",&bracket)==1 && bracket != '\n') {
        text[i] = bracket;
        i++;
    }

    //null terminate string
    text[i] = '\0';
    
    //first push
    push(&stack,text[0]);

    //compare
    for (int j = 1;text[j] != '\0';++j) {

        char curr = text[j];

        // Ignore words and only process symbols
        if (curr == '[' || curr == '(' || curr == '{') {
            push(&stack, curr);
        } else if (curr == ']' || curr == ')' || curr == '}') {
            char prev = pop(&stack);
            if ((prev == '[' && curr == ']') ||
                (prev == '(' && curr == ')') ||
                (prev == '{' && curr == '}')) {
                // Brackets match, continue processing
            } else {
                // Brackets do not match, exit with an error
                printf("Error: Bracket mismatch\n");
                exit(EXIT_FAILURE);
            }
        }
    }

}







    


}