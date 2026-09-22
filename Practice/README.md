# Practice Programs

---

## Binarysearch

`BinarySearch.cpp`

```cpp
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int iterativeBinarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int size, int start, int end, int key)
{
    int mid = (start + end) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] < key)
    {
        start = mid + 1;
        return recursiveBinarySearch(arr, size, start, end, key);
    }
    else
    {
        end = mid - 1;
        return recursiveBinarySearch(arr, size, start, end, key);
    }
    return -1;
}

int main()
{
    int key, size, choice;
    int arr[SIZE] = {1, 4, 7, 8, 9};

    printf("Binary Search ~\n");
    printf("Enter Type Of Search ~\n1. Iterative\n2. Recursive\n");

    printf("Enter The Type Of Array ( 1 | 2 ) : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter The Element To Search : ");
        scanf("%d", &key);

        int elementIndex = iterativeBinarySearch(arr, SIZE, key);

        if (elementIndex != -1)
        {
            printf("Element Found At %d", elementIndex);
        }
        else
        {
            printf("Element Not Found!");
        }
    }
    else if (choice == 2)
    {

        printf("Enter The Element To Search : ");
        scanf("%d", &key);

        int start = 0;
        int end = SIZE - 1;

        int elementIndex = recursiveBinarySearch(arr, SIZE, start, end, key);

        if (elementIndex != -1)
        {
            printf("Element Found At %d", elementIndex);
        }
        else
        {
            printf("Element Not Found!");
        }
    }
    else
    {
        printf("Invalid Choice!");
    }

    return 0;
}
```

---

## Circularlinkedlist

`CircularLinkedList.cpp`

```cpp
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
```

---

## Circularqueue

`CircularQueue.cpp`

```cpp
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
```

---

## Linearsearch

`LinearSearch.cpp`

```cpp
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int linearSearch(int arr[], int key)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int key, size, choice;

    printf("Linear Search ~\n");
    printf("Enter Type Of Array ~\n1. Static Array\n2. Dynamic Array\n");

    printf("Enter The Type Of Array ( 1 | 2 ) : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int arr[SIZE] = {1, 4, 8, 3, 9};

        printf("Enter The Element To Search : ");
        scanf("%d", &key);

        int elementIndex = linearSearch(arr, key);

        if (elementIndex != -1)
        {
            printf("Element Found At Index %d", elementIndex);
        }
        else
        {
            printf("Element Not Found!");
        }
    }
    else if (choice == 2)
    {
        int *arr = (int *)malloc(size * sizeof(int));

        printf("Enter The Array Size : ");
        scanf("%d", &size);

        printf("Enter Array Elements : ");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("Enter The Element To Search : ");
        scanf("%d", &key);

        int elementIndex = linearSearch(arr, key);

        if (elementIndex != -1)
        {
            printf("Element Found At Index %d", elementIndex);
        }
        else
        {
            printf("Element Not Found!");
        }
    }
    else
    {
        printf("Invalid Choice!");
    }

    return 0;
}
```

---

## Linkedlist

`LinkedList.cpp`

```cpp
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
```

---

## Queue

`Queue.cpp`

```cpp
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
```

---

## Sorting

`Sorting.cpp`

```cpp
#include <stdio.h>

// Function To Print Array
void PrintArray(int Arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void BubbleSort(int Arr[], int N)
{
    // Outer Loop For Passes
    for (int i = 0; i < N - 1; i++)
    {
        // Inner Loop For Comparison
        for (int j = 0; j < N - i - 1; j++)
        {
            if (Arr[j] > Arr[j + 1]) // Swap If Greater
            {
                int Temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = Temp;
            }
        }
    }
}

// Selection Sort
void SelectionSort(int Arr[], int N)
{
    // Loop For Selecting Minimum Element
    for (int i = 0; i < N - 1; i++)
    {
        int MinIndex = i; // Assume Current Index Is Minimum

        for (int j = i + 1; j < N; j++)
        {
            if (Arr[j] < Arr[MinIndex])
            {
                MinIndex = j; // Update Minimum Index
            }
        }

        // Swap Minimum With Current Position
        int Temp = Arr[i];
        Arr[i] = Arr[MinIndex];
        Arr[MinIndex] = Temp;
    }
}

// Insertion Sort
void InsertionSort(int Arr[], int N)
{
    for (int i = 1; i < N; i++)
    {
        int Key = Arr[i]; // Current Element
        int j = i - 1;

        // Shift Elements Greater Than Key
        while (j >= 0 && Arr[j] > Key)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }

        Arr[j + 1] = Key; // Insert Key At Correct Position
    }
}

// Partition Function For Quick Sort
int Partition(int Arr[], int Low, int High)
{
    int Pivot = Arr[High]; // Choose Last Element As Pivot
    int i = Low - 1;       // Index Of Smaller Element

    for (int j = Low; j < High; j++)
    {
        if (Arr[j] < Pivot)
        {
            i++;

            // Swap Elements
            int Temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = Temp;
        }
    }

    // Place Pivot At Correct Position
    int Temp = Arr[i + 1];
    Arr[i + 1] = Arr[High];
    Arr[High] = Temp;

    return i + 1;
}

// Quick Sort
void QuickSort(int Arr[], int Low, int High)
{
    if (Low < High)
    {
        int PivotIndex = Partition(Arr, Low, High);

        // Recursive Calls For Subarrays
        QuickSort(Arr, Low, PivotIndex - 1);
        QuickSort(Arr, PivotIndex + 1, High);
    }
}

// Main Function For Testing
int main()
{
    int Arr1[] = {5, 2, 9, 1, 6};
    int Arr2[] = {5, 2, 9, 1, 6};
    int Arr3[] = {5, 2, 9, 1, 6};
    int Arr4[] = {5, 2, 9, 1, 6};
    int N = 5;

    printf("Bubble Sort:\n");
    BubbleSort(Arr1, N);
    PrintArray(Arr1, N);

    printf("Selection Sort:\n");
    SelectionSort(Arr2, N);
    PrintArray(Arr2, N);

    printf("Insertion Sort:\n");
    InsertionSort(Arr3, N);
    PrintArray(Arr3, N);

    printf("Quick Sort:\n");
    QuickSort(Arr4, 0, N - 1);
    PrintArray(Arr4, N);

    return 0;
}
```

---
