#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char name[20];
    int roll, marks;
    struct Node *next;
};

struct Node *Head = NULL, *Last = NULL;

void appendNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Student Data ~");
    printf("\nEnter Student Name : ");
    scanf("%s", &newNode->name);

    printf("\nEnter Student Roll No : ");
    scanf("%d", &newNode->roll);

    printf("\nEnter Student Marks : ");
    scanf("%d", &newNode->marks);

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

void displayNode()
{
    struct Node *newNode = Head;

    if (Head == NULL)
    {
        printf("List Empty!");
    }
    else
    {
        while (newNode != NULL)
        {
            if (newNode->marks >= 50)
            {
                printf("%s\n", newNode->name);
            }
            newNode = newNode->next;
        }
    }
}

int main()
{
    int choise;

    while (1)
    {
        printf("*** Linked List Operations ***\n");
        printf("\n1. Append New Student\n2. Display Students\n3. Exit");

        printf("\nEnter Your Choise : ");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            appendNode();
            break;

        case 2:
            displayNode();
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid Input");
            break;
        }
    }

    return 0;
}
