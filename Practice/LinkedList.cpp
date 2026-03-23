#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Basically Name Is next
};

struct Node *head = NULL, *last = NULL;

void insertNodeLast() // Also Known As Append Node
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Data : ");
    scanf("%d", newNode->data);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}

void insertNode()
{
    int pos, counter = 1;

    printf("\nEnter The Position To Insert Node : ");
    scanf("%d", &pos);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Data : ");
    scanf("%d", newNode->data);

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;

        if (last == NULL)
        {
            last = newNode;
        }
        return;
    }

    struct Node *tempNode = head;

    while (tempNode != NULL && counter < pos - 1)
    {
        tempNode = tempNode->next;
        counter++;
    }

    if (newNode->next == NULL)
    {
        last = newNode;
    }

    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

void deleteNode()
{
    int pos, counter = 1;

    printf("\nEnter The Position To Delete Node : ");
    scanf("%d", &pos);

    struct Node *temp = head;
    struct Node *prev = NULL;

    if (pos == 1)
    {
        head = head->next;
        free(temp);

        if (head == NULL)
        {
            last == NULL;
        }

        return;
    }

    while (temp != NULL && counter < pos)
    {
        prev = temp;
        temp = temp->next;
        counter++;
    }

    prev->next = temp->next;

    if (temp->next == NULL)
        last = prev;

    free(temp);
}

void reverseNodes()
{

    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Current Order
        current->next = prev; // Setting Current's Next To Be Previous Node
        prev = current;       // Now Previous Node Becomes Current
        current = next;       // Current Node Becomes Next
    }
}
