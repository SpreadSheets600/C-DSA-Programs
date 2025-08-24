# Programming Exercises - August 18, 2025

## Exercise 1 : Linked List Operations

**Qestion:** Write a menu driven program to implement single linklist and write the following functions :

                1. Append()

                2. Display ()

Note -  i. Data parts contain Roll,Name,Marks
        ii. Display those student names with marks >= 50

**Sollution:** [View Code](StudentLinkedList.cpp)

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
```

### OUTPUT 1

```bash
*** Linked List Operations ***

1. Append New Student
2. Display Students
3. Exit
Enter Your Choise : 1

Enter Student Data ~
Enter Student Name : S1             

Enter Student Roll No : 1

Enter Student Marks : 30
*** Linked List Operations ***

1. Append New Student
2. Display Students
3. Exit
Enter Your Choise : 1

Enter Student Data ~
Enter Student Name : S2

Enter Student Roll No : 2 

Enter Student Marks : 90
*** Linked List Operations ***

1. Append New Student
2. Display Students
3. Exit
Enter Your Choise : 2
S2
*** Linked List Operations ***

1. Append New Student
2. Display Students
3. Exit
Enter Your Choise : 3

```
