#include <stdio.h>
#include <stdlib.h>

// Definition of the 'node' structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create a linked list of 'n' nodes
node* create(int n) {
    if (n <= 0) {
        return NULL;  // Invalid input, return NULL
    }

    node *p, *q, *r;
    int i;

    // Create the first node
    p = (node*)malloc(sizeof(node));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter data for node 1: ");
    scanf("%d", &(p->data));
    p->next = NULL;
    q = p;

    // Create and append the remaining nodes
    for (i = 1; i < n; i++) {
        r = (node*)malloc(sizeof(node));
        if (r == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &(r->data));
        r->next = NULL;

        // Link the new node to the end of the list
        q->next = r;
        q = r;
    }

    return p;  // Return the head of the linked list
}

// Function to traverse the linked list and print its elements
void traverse(node* p) {
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the linked list
    node* myList = create(n);

    // Print the original linked list
    printf("Original Linked List: ");
    traverse(myList);

    // Creating a new node to insert
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;

    // Manually inserting the new node at position 2
    printf("Enter data for the new node: ");
    scanf("%d", &(newNode->data));

    // Manually linking the new node to the list at position 2
    newNode->next = myList->next;
    myList->next = newNode;

    // Print the modified linked list
    printf("Modified Linked List: ");
    traverse(myList);

    // Free allocated memory
    node* current = myList;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
