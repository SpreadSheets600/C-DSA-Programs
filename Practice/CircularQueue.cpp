#include <stdio.h>
#define SIZE 5

// Global Queue Array And Pointers
int Queue[SIZE]; // Array To Store Elements
int Front = -1;  // Points To First Element
int Rear = -1;   // Points To Last Element

// Function To Check If Queue Is Full
int IsFull()
{
    if ((Front == 0 && Rear == SIZE - 1) || (Front == Rear + 1))
    {
        return 1; // Queue Is Full
    }
    return 0; // Queue Is Not Full
}

// Function To Check If Queue Is Empty
int IsEmpty()
{
    if (Front == -1)
    {
        return 1; // Queue Is Empty
    }
    return 0; // Queue Is Not Empty
}

// Function To Insert Element
void Push(int Value)
{
    if (IsFull())
    {
        printf("Queue Is Full\n");
        return;
    }

    if (Front == -1) // First Element In Queue
    {
        Front = 0;
        Rear = 0;
    }
    else if (Rear == SIZE - 1) // Circular Condition
    {
        Rear = 0;
    }
    else
    {
        Rear++;
    }

    Queue[Rear] = Value; // Insert Value
}

// Function To Delete Element
void Pop()
{
    if (IsEmpty())
    {
        printf("Queue Is Empty\n");
        return;
    }

    printf("Deleted Element Is %d\n", Queue[Front]);

    if (Front == Rear) // Only One Element
    {
        Front = -1;
        Rear = -1;
    }
    else if (Front == SIZE - 1) // Circular Condition
    {
        Front = 0;
    }
    else
    {
        Front++;
    }
}

// Function To Display Queue
void Display()
{
    if (IsEmpty())
    {
        printf("Queue Is Empty\n");
        return;
    }

    int i = Front;

    printf("Queue Elements Are : ");

    while (1)
    {
        printf("%d ", Queue[i]);

        if (i == Rear)
        {
            break;
        }

        if (i == SIZE - 1)
        {
            i = 0; // Circular Move
        }
        else
        {
            i++;
        }
    }

    printf("\n");
}

// Main Function For Testing
int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);

    Display();

    Pop();
    Pop();

    Display();

    Push(60);
    Push(70);

    Display();

    return 0;
}
