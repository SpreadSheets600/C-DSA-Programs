# Programming Exercises - August 08, 2025

## Exercise : Linked List Operations

**Qestion:** Write a program to insert a node at a given position and delete a node at a given position.

**Sollution:** [View Code](LinkedList.cpp)

```cpp
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
    scanf("%s", newNode->name);

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

void insertNode()
{
    int pos, c = 1;

    printf("\nEnter The Position To Insert Node : ");
    scanf("%d", &pos);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Student Data ~");
    printf("\nEnter Student Name : ");
    scanf("%s", newNode->name);

    printf("\nEnter Student Roll No : ");
    scanf("%d", &newNode->roll);

    printf("\nEnter Student Marks : ");
    scanf("%d", &newNode->marks);

    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = Head;
        Head = newNode;

        if (Last == NULL)
        {
            Last = newNode;
        }

        printf("\nNode Enterd At %d", pos);

        return;
    }

    struct Node *tempNode = Head;

    while (tempNode != NULL && c < pos - 1)
    {
        tempNode = tempNode->next;
        c++;
    }

    newNode->next = tempNode->next;
    tempNode->next = newNode;

    if (newNode->next == NULL)
    {
        Last = newNode;
    }

    printf("\nNode Enterd At %d", pos);
}

void deleteNode()
{
    int pos, c = 1;

    printf("\nEnter The Position To Delete Node : ");
    scanf("%d", &pos);

    if (Head == NULL)
    {
        printf("List Is Empty!\n");
        return;
    }

    struct Node *temp = Head;
    struct Node *prev = NULL;

    if (pos == 1)
    {
        Head = Head->next;
        free(temp);

        if (Head == NULL)
            Last = NULL;

        printf("Node At Position %d Deleted.\n", pos);
        return;
    }

    while (temp != NULL && c < pos)
    {
        prev = temp;
        temp = temp->next;
        c++;
    }

    if (temp == NULL)
    {
        printf("Invalid Position!\n");
        return;
    }

    prev->next = temp->next;

    if (temp->next == NULL)
        Last = prev;

    free(temp);

    printf("Node At Position %d Deleted.\n", pos);
}

void searchNode()
{
    int roll;
    int found = 0;

    printf("Enter The Roll No : ");
    scanf("%d", &roll);

    struct Node *tempNode = Head;

    if (Head == NULL)
    {
        printf("List Empty!\n");
    }
    else
    {
        while (tempNode != NULL)
        {
            if (tempNode->roll == roll)
            {
                printf("Marks : %d | Name : %s | Roll : %d\n", tempNode->marks, tempNode->name, tempNode->roll);

                found = 1;
                break;
            }
            tempNode = tempNode->next;
        }

        if (!found)
        {
            printf("Roll No %d Not Found!\n", roll);
        }
    }
}

void displayNode()
{
    struct Node *tempNode = Head;

    if (Head == NULL)
    {
        printf("List Empty!");
    }
    else
    {
        printf("\nRoll - Name - Marks\n");

        while (tempNode != NULL)
        {
            printf("%d - %s - %d\n", tempNode->roll, tempNode->name, tempNode->marks);
            tempNode = tempNode->next;
        }
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("*** Linked List Operations ***\n");
        printf("\n1. Append New Student\n2. Insert New Students\n3. Delete Student\n4. Search Student\n5. Display Students\n6. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            appendNode();
            break;

        case 2:
            insertNode();
            break;

        case 3:
            deleteNode();
            break;

        case 4:
            searchNode();
            break;

        case 5:
            displayNode();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Input");
            break;
        }
    }

    return 0;
}
```

### OUTPUT 1

```bash
*** Linked List Operations ***

1. Append New Student
2. Insert New Students
3. Delete Student
4. Search Student
5. Display Students
6. Exit

Enter Your Choice : 1

Enter Student Data ~
Enter Student Name : DEBOJIT

Enter Student Roll No : 1

Enter Student Marks : 98
*** Linked List Operations ***

1. Append New Student
2. Insert New Students
3. Delete Student
4. Search Student
5. Display Students
6. Exit

Enter Your Choice : 1

Enter Student Data ~
Enter Student Name : SAYAN

Enter Student Roll No : 3

Enter Student Marks : 94
*** Linked List Operations ***

1. Append New Student
2. Insert New Students
3. Delete Student
4. Search Student
5. Display Students
6. Exit

Enter Your Choice : 2

Enter The Position To Insert Node : 2

Enter Student Data ~
Enter Student Name : SOHAM

Enter Student Roll No : 2

Enter Student Marks : 96

Node Enterd At 2*** Linked List Operations ***

1. Append New Student
2. Insert New Students
3. Delete Student
4. Search Student
5. Display Students
6. Exit

Enter Your Choice : 5

Roll - Name - Marks
1 - DEBOJIT - 98
2 - SOHAM - 96
3 - SAYAN - 94
*** Linked List Operations ***

1. Append New Student
2. Insert New Students
3. Delete Student
4. Search Student
5. Display Students
6. Exit

Enter Your Choice : 4
Enter The Roll No : 2
Marks : 96 | Name : SOHAM | Roll : 2
*** Linked List Operations ***

1. Append New Student
2. Insert New Students
3. Delete Student
4. Search Student
5. Display Students
6. Exit

Enter Your Choice : 3

Enter The Position To Delete Node : 3
Node At Position 3 Deleted.
*** Linked List Operations ***

1. Append New Student
2. Insert New Students
3. Delete Student
4. Search Student
5. Display Students
6. Exit

Enter Your Choice : 5

Roll - Name - Marks
1 - DEBOJIT - 98
2 - SOHAM - 96
*** Linked List Operations ***

1. Append New Student
2. Insert New Students
3. Delete Student
4. Search Student
5. Display Students
6. Exit

Enter Your Choice : 6

```
