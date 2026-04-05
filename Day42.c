/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#define MAX 100

// Queue
int queue[MAX];
int front = -1, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int value) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = value;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Push to stack
void push(int value) {
    stack[++top] = value;
}

// Pop from stack
int pop() {
    return stack[top--];
}

int main() {
    int N, x;

    scanf("%d", &N);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue → stack
    while (front <= rear) {
        push(dequeue());
    }

    // Step 2: Move stack → queue (reversed)
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    while (front <= rear) {
        printf("%d ", dequeue());
    }

    return 0;
}
