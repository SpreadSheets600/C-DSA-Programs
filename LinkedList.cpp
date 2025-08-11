#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Head = NULL, *Last = NULL;

void createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\n Enter Data");
    scanf("%d", &newNode->data); // Since We Are Using Pointers

    newNode->next = NULL;

    if (Head == NULL)
    {
        Head = newNode;
        Last = newNode;
    }
    else
    {
        Last->next = newNode;
        Last = newNode;
    }
}

void displayList()
{
    struct Node *newNode = Head; // Copying Address Of Head To newNode, Cause Head Pointer Should Not Be Changed

    while (newNode != NULL)
    {
        printf("\n%d ", newNode->data);
        newNode = newNode->next;
    }
}

void deleteNode()
{
    if (Head == NULL)
    {
        printf("\nList is Empty");
        return;
    }

    struct Node *temp = Head;
    Head = Head->next;
    free(temp);

    if (Head == NULL)
    {
        Last = NULL; // If The List Becomes Empty
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n1. Create Node\n2. Display List\n3. Delete Node\n4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createNode();
            break;
        case 2:
            displayList();
            break;
        case 3:
            deleteNode();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }

    return 0;
}
