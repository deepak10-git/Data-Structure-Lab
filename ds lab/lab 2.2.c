       #include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push an element onto the stack
void push(char ch) {
    stack[++top] = ch;
}

// Pop an element from the stack
char pop() {
    return stack[top--];
}

// Return precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // If opening parenthesis, push onto stack
        else if (ch == '(') {
            push(ch);
        }

        // If closing parenthesis, pop until '('
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Remove '('
        }

        // If operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

