

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
    int data;
    struct node *next;
};

// Function to create a linked list
struct node* create(struct node *head) {
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    return head;
}

// Function to display the linked list
void display(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Function to sort the linked list
void sort(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Linked list sorted successfully.\n");
}

// Function to reverse the linked list
struct node* reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    printf("Linked list reversed successfully.\n");
    return prev;
}

// Function to concatenate two linked lists
struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    temp = head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

// Main function
int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    int choice;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create First Linked List\n");
        printf("2. Create Second Linked List\n");
        printf("3. Display First List\n");
        printf("4. Sort First List\n");
        printf("5. Reverse First List\n");
        printf("6. Concatenate Two Lists\n");
        printf("7. Display Second List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head1 = create(head1);
                break;

            case 2:
                head2 = create(head2);
                break;

            case 3:
                display(head1);
                break;

            case 4:
                sort(head1);
                break;

            case 5:
                head1 = reverse(head1);
                break;

            case 6:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                printf("Lists concatenated successfully.\n");
                display(head1);
                break;

            case 7:
                display(head2);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
