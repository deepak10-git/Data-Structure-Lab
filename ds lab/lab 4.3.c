
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Create a new node
void create()
{
    struct node *newnode, *temp;
    int x;

    printf("Enter data: ");
    scanf("%d", &x);

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
}

// Insert a node to the left of a given node
void insert()
{
    struct node *newnode, *temp;
    int key, x;

    printf("Enter the value before which to insert: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    printf("Enter new data: ");
    scanf("%d", &x);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    newnode->prev = temp->prev;
    newnode->next = temp;

    if(temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;
}

// Delete a node based on a specific value
void delete()
{
    struct node *temp;
    int key;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node deleted successfully\n");
}

// Display the list
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1. Create");
        printf("\n2. Insert to the left");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                create();
                break;

            case 2:
                insert();
                break;

            case 3:
                delete();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

