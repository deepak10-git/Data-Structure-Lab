#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Push operation
void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push element.\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d pushed into the stack.\n", value);
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

// Display operation
void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
