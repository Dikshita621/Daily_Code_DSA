/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if (size == MAX) return;
    pq[size++] = x;
}

// Find index of minimum element
int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete (remove min)
void deleteMin() {
    int index = findMinIndex();

    if (index == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[index]);

    // Shift elements
    for (int i = index; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek (get min)
void peek() {
    int index = findMinIndex();

    if (index == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[index]);
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {  // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {  // delete
            deleteMin();
        }
        else if (op[0] == 'p') {  // peek
            peek();
        }
    }

    return 0;
}
