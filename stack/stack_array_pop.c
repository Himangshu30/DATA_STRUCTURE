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
    if (s->top == size - 1)
    {
        printf("Stack overflow!\n");
        return 0;
    }
    else
    {
        s->top += 1;
        s->arr[s->top] = a;
        return 1; // Successful push
    }
}

int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow!\n");
        return 0;
    }
    else
    {
        s->top -= 1;
        return 1; // Successful pop
    }
}

int main()
{
    stack myStack;
    myStack.top = -1;

    int n, element;

    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);

        if (!push(element, &myStack))
        {
            printf("Unable to push element. Exiting...\n");
            return 1;
        }
    }

    // Print the elements in the stack
    printf("Elements in the stack: ");
    for (int i = 0; i <= myStack.top; i++)
    {
        printf("%d ", myStack.arr[i]);
    }

    // Pop some elements from the stack
    int numPops;
    printf("\nEnter the number of elements to pop from the stack: ");
    scanf("%d", &numPops);

    for (int i = 0; i < numPops; i++)
    {
        if (!pop(&myStack))
        {
            printf("Unable to pop element. Stack is empty.\n");
            break;
        }
    }

    // Print the elements in the stack after popping
    printf("Elements in the stack after popping: ");
    for (int i = 0; i <= myStack.top; i++)
    {
        printf("%d ", myStack.arr[i]);
    }

    return 0;
}
