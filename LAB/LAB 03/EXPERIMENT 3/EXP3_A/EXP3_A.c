#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    char items[MAX];
};

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Push element to stack
void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Pop element from stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// Peek top element of stack
char peek(struct Stack *s) {
    if (!isEmpty(s))
        return s->items[s->top];
    return '\0';
}

// Return precedence of operator
int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Check if character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int k = 0;  // Index for postfix
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            // Operand, directly add to postfix
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            // Pop until '('
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) == '(')
                pop(&s); // Remove '('
        } else if (isOperator(ch)) {
            // Pop operators with higher or equal precedence
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop remaining operators
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0'; // Null terminate
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
