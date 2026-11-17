

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

// Stack Push
void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

// Stack Pop
void pop()
{
    struct node *temp;

    if(top == NULL)
        printf("Stack Underflow\n");
    else
    {
        temp = top;
        printf("Deleted element = %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

// Stack Display
void displayStack()
{
    struct node *temp = top;

    if(top == NULL)
        printf("Stack is Empty\n");
    else
    {
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Queue Enqueue
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

// Queue Dequeue
void dequeue()
{
    struct node *temp;

    if(front == NULL)
        printf("Queue Underflow\n");
    else
    {
        temp = front;
        printf("Deleted element = %d\n", temp->data);
        front = front->next;

        if(front == NULL)
            rear = NULL;

        free(temp);
    }
}

// Queue Display
void displayQueue()
{
    struct node *temp = front;

    if(front == NULL)
        printf("Queue is Empty\n");
    else
    {
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int ch, x;

    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Display Stack");
        printf("\n4. Enqueue\n5. Dequeue\n6. Display Queue");
        printf("\n7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
