#include <stdio.h>
#include <stdlib.h>

// Node Structure Definition
struct Node
{
    int Data;          // Data Field Of Node
    struct Node *Next; // Pointer To Next Node
};

// Global Head Pointer
struct Node *Head = NULL;

// Function To Create New Node
struct Node *CreateNode(int Value)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate Memory
    NewNode->Data = Value;                                             // Assign Data
    NewNode->Next = NULL;                                              // Initialize Next Pointer
    return NewNode;
}

// Insertion At Beginning
void InsertAtFirst(int Value)
{
    struct Node *NewNode = CreateNode(Value); // Create New Node

    if (Head == NULL) // If List Is Empty
    {
        Head = NewNode;
        NewNode->Next = Head; // Point To Itself
        return;
    }

    struct Node *Temp = Head; // Temporary Pointer

    while (Temp->Next != Head) // Traverse Till Last Node
    {
        Temp = Temp->Next;
    }

    Temp->Next = NewNode; // Last Node Points To New Node
    NewNode->Next = Head; // New Node Points To Old Head
    Head = NewNode;       // Update Head
}

// Insertion At End
void InsertAtEnd(int Value)
{
    struct Node *NewNode = CreateNode(Value); // Create New Node

    if (Head == NULL) // If List Is Empty
    {
        Head = NewNode;
        NewNode->Next = Head;
        return;
    }

    struct Node *Temp = Head;

    while (Temp->Next != Head) // Traverse Till Last Node
    {
        Temp = Temp->Next;
    }

    Temp->Next = NewNode; // Last Node Points To New Node
    NewNode->Next = Head; // Maintain Circular Property
}

// Insertion At Nth Position
void InsertAtPosition(int Value, int Position)
{
    if (Position == 1)
    {
        InsertAtFirst(Value);
        return;
    }

    struct Node *NewNode = CreateNode(Value);
    struct Node *Temp = Head;

    for (int i = 1; i < Position - 1 && Temp->Next != Head; i++)
    {
        Temp = Temp->Next;
    }

    NewNode->Next = Temp->Next;
    Temp->Next = NewNode;
}

// Deletion At Beginning
void DeleteAtFirst()
{
    if (Head == NULL) // If List Is Empty
    {
        printf("List Is Empty\n");
        return;
    }

    if (Head->Next == Head) // Only One Node
    {
        free(Head);
        Head = NULL;
        return;
    }

    struct Node *Temp = Head;

    while (Temp->Next != Head) // Find Last Node
    {
        Temp = Temp->Next;
    }

    struct Node *DeleteNode = Head;
    Temp->Next = Head->Next; // Last Node Points To Second Node
    Head = Head->Next;       // Update Head
    free(DeleteNode);        // Free Memory
}

// Deletion At End
void DeleteAtEnd()
{
    if (Head == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    if (Head->Next == Head) // Only One Node
    {
        free(Head);
        Head = NULL;
        return;
    }

    struct Node *Temp = Head;
    struct Node *Prev = NULL;

    while (Temp->Next != Head)
    {
        Prev = Temp;
        Temp = Temp->Next;
    }

    Prev->Next = Head; // Second Last Points To Head
    free(Temp);        // Delete Last Node
}

// Deletion At Nth Position
void DeleteAtPosition(int Position)
{
    if (Head == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    if (Position == 1)
    {
        DeleteAtFirst();
        return;
    }

    struct Node *Temp = Head;
    struct Node *Prev = NULL;

    for (int i = 1; i < Position && Temp->Next != Head; i++)
    {
        Prev = Temp;
        Temp = Temp->Next;
    }

    Prev->Next = Temp->Next;
    free(Temp);
}

// Display Circular Linked List
void Display()
{
    if (Head == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    struct Node *Temp = Head;

    do
    {
        printf("%d -> ", Temp->Data);
        Temp = Temp->Next;
    } while (Temp != Head);

    printf("(Back To Head)\n");
}

// Main Function For Testing
int main()
{
    InsertAtFirst(10);
    InsertAtFirst(5);
    InsertAtEnd(20);
    InsertAtEnd(30);

    Display();

    InsertAtPosition(15, 3);
    Display();

    DeleteAtFirst();
    Display();

    DeleteAtEnd();
    Display();

    DeleteAtPosition(2);
    Display();

    return 0;
}
