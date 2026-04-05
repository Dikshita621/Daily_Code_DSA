/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n)
            nodes[i]->left = nodes[left];
        if (right < n)
            nodes[i]->right = nodes[right];
    }

    return nodes[0];
}

// Count nodes
int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isCBT(struct Node* root, int index, int total) {
    if (!root) return 1;

    if (index >= total)
        return 0;

    return isCBT(root->left, 2*index + 1, total) &&
           isCBT(root->right, 2*index + 2, total);
}

// Check Min-Heap property
int isMinHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right) {
        return (root->data <= root->left->data);
    }

    return (root->data <= root->left->data) &&
           (root->data <= root->right->data) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int total = countNodes(root);

    if (isCBT(root, 0, total) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
