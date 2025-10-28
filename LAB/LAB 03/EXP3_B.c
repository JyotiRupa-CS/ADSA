#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    double items[MAX]; // Use double to handle non-integer results
};

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push element to stack
void push(struct Stack *s, double value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Pop element from stack
double pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return 0;
    }
    return s->items[(s->top)--];
}

// Evaluate postfix expression
double evaluatePostfix(char* postfix) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            // Operand: convert char to number and push
            push(&s, ch - '0');
        } else {
            // Operator: pop two operands
            double val2 = pop(&s);
            double val1 = pop(&s);
            switch(ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                case '^': push(&s, pow(val1, val2)); break;
                default: printf("Unknown operator %c\n", ch);
            }
        }
    }
    return pop(&s); // Final result
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression (single-digit operands only): ");
    scanf("%s", postfix);

    double result = evaluatePostfix(postfix);

    printf("Result of postfix expression: %.2lf\n", result);

    return 0;
}
