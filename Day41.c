/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/
#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize front and rear
struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
int dequeue() {
    if (front == NULL) {
        return -1; // Queue is empty
    }

    struct Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return value;
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int choice, value;

        scanf("%d", &choice);

        if (choice == 1) {   // Enqueue
            scanf("%d", &value);
            enqueue(value);
        }
        else if (choice == 2) {  // Dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}
