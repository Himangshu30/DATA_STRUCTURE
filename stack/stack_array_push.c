#include <stdio.h>
#include <stdlib.h>

#define size 100

typedef struct stack
{
    int arr[size];
    int top;
} stack;

int push(int a, stack *s)
{
    if (s->top == size - 1) {
        printf("Stack overflow!\n");
        return 0;
    } else {
        s->top += 1;
        s->arr[s->top] = a;
        return 1;  // Successful push
    }
}

int main() {
    // Example usage of the stack
    stack myStack;
    myStack.top = -1;  // Initialize the top of the stack

    // Push some elements onto the stack
    push(1, &myStack);
    push(2, &myStack);
    push(3, &myStack);

    // Print the elements in the stack
    printf("Elements in the stack: ");
    for (int i = 0; i <= myStack.top; i++) {
        printf("%d ", myStack.arr[i]);
    }

    return 0;
}
