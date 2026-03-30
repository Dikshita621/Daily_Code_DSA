/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If digit (handle multi-digit)
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(&stack, num);
        }

        // Operator
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }

            push(&stack, result);
            i++;
        }
    }

    return pop(&stack);
}

int main() {
    char exp[100];

    // Read full line input
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}
