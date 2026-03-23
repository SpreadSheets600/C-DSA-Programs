#include <stdio.h>
#define SIZE 5

// Global Queue Array And Pointers
int Queue[SIZE]; // Array To Store Elements
int Front = -1;  // Points To First Element
int Rear = -1;   // Points To Last Element

// Function To Check If Queue Is Full
int IsFull()
{
    if (Rear == SIZE - 1)
    {
        return 1; // Queue Is Full
    }
    return 0; // Queue Is Not Full
}

// Function To Check If Queue Is Empty
int IsEmpty()
{
    if (Front == -1 || Front > Rear)
    {
        return 1; // Queue Is Empty
    }
    return 0; // Queue Is Not Empty
}

// Function To Insert Element
void Enqueue(int Value)
{
    if (IsFull())
    {
        printf("Queue Is Full\n");
        return;
    }

    if (Front == -1) // First Element In Queue
    {
        Front = 0;
    }

    Rear++;              // Move Rear Forward
    Queue[Rear] = Value; // Insert Value
}

// Function To Delete Element
void Dequeue()
{
    if (IsEmpty())
    {
        printf("Queue Is Empty\n");
        return;
    }

    printf("Deleted Element Is %d\n", Queue[Front]);

    Front++; // Move Front Forward
}

// Function To Display Queue
void Display()
{
    if (IsEmpty())
    {
        printf("Queue Is Empty\n");
        return;
    }

    printf("Queue Elements Are : ");

    for (int i = Front; i <= Rear; i++)
    {
        printf("%d ", Queue[i]);
    }

    printf("\n");
}

// Main Function For Testing
int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);

    Display();

    Dequeue();
    Dequeue();

    Display();

    return 0;
}
