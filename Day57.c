/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/
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

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[n];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n) {
        struct Node* cur = q[f++];

        if (arr[i] != -1) {
            cur->left = newNode(arr[i]);
            q[r++] = cur->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = newNode(arr[i]);
            q[r++] = cur->right;
        }
        i++;
    }
    return root;
}

// Mirror function
void mirror(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    mirror(root);          // Convert to mirror
    inorder(root);         // Print inorder of mirrored tree

    return 0;
}
