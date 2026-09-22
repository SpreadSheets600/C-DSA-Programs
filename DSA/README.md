# DSA Programs

---

## Bubblesort

`BubbleSort.cpp`

```cpp
#include <stdbool.h>
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = false;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);

    printf("Sorted Array : \n");
    printArray(arr, n);

    return 0;
}
```

---

## Adjacencymatrix

`Graph/AdjacencyMatrix.cpp`

```cpp
#include <stdio.h>
#include <string.h>

// Adjacency Matrix For Graph Representation
#define MAX 100

int adjMatrix[MAX][MAX];
int numVertices = 0;

// Initialize Adjacency Matrix
void initMatrix(int graphType)
{
    for (int i = 0; i < MAX; i++)
    {
        if (graphType == 0) // Undirected
        {
            for (int j = 0; j < MAX; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
        else if (graphType == 1) // Directed
        {
            for (int j = 0; j < MAX; j++)
            {
                adjMatrix[i][j] = -1;
            }
        }
    }
}

// Add Edge To Graph
void addEdge(int src, int dest, int weight = 1)
{
    if (src >= MAX || dest >= MAX)
    {
        printf("Invalid vertex!\n");
        return;
    }
    adjMatrix[src][dest] = weight;
}

// Print Adjacency Matrix
void printMatrix()
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    initMatrix(1);
    addEdge(0, 1, 5);
    addEdge(1, 2, 3);
    addEdge(2, 3, 7);
    addEdge(3, 4, 2);
    addEdge(4, 0, 9);

    numVertices = 6;
    printMatrix();
}
```

---

## Joshepwarproblem

`JoshepWarProblem.cpp`

```cpp
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct  Node* createList(int n) {
    struct Node* head = NULL, *temp = NULL, *prev = NULL;

    for (int i = 0; i <= n; i++)
    {   
        temp = (struct Node*)malloc(sizeof(struct Node));

        temp -> data = i;
        temp -> next = head;

        if (head == NULL) {
            head = temp;
        } else {
            prev -> next = temp;
        }
        prev = temp;
    }
    prev -> next = head;
    return head;

};

int josephus(int n, int k) {
    struct Node* head = createList(n);
    struct Node* ptr = head, *prev = NULL;

    while (ptr->next != ptr) {
        for (int count = 1; count < k; count++) {
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = ptr->next;
        printf("Eliminated : %d\n", ptr->data);

        free(ptr);
        ptr = prev->next;
    }
    int survivor = ptr->data;
    free(ptr);

    return survivor;
}

int main() {
    int n = 7, k = 3;
    printf("Survivor : %d\n", josephus(n, k));
    return 0;
}
```

---

## Linkedlist

`LinkedList.cpp`

```cpp
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
```

---

## Treesarray

`TreesArray.cpp`

```cpp
#include <stdio.h>
#define MAX 100

int tree[MAX];
int size = 0;

// Insert Into Array Tree
void insert(int value)
{
    if (size >= MAX)
    {
        printf("Tree is full!\n");
        return;
    }
    tree[size++] = value;
}

// Print Tree In Level Order
void printTree()
{
    printf("Tree: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

// Get Parent Index
int getParentIndex(int index)
{
    if (index == 0)
        return -1;

    return (index - 1) / 2;
}

// Get Left Child Index
int getLeftChildIndex(int index)
{
    return 2 * index + 1;
}

// Get Right Child Index
int getRightChildIndex(int index)
{
    return 2 * index + 2;
}

// Get Parent Value
int getParentValue(int index)
{
    int parentIndex = getParentIndex(index);
    if (parentIndex == -1)
        return -1;

    return tree[parentIndex];
}

// Get Left Child Value
int getLeftChildValue(int index)
{
    int leftChildIndex = getLeftChildIndex(index);
    if (leftChildIndex >= size)
        return -1;

    return tree[leftChildIndex];
}

// Get Right Child Value
int getRightChildValue(int index)
{
    int rightChildIndex = getRightChildIndex(index);
    if (rightChildIndex >= size)
        return -1;

    return tree[rightChildIndex];
}

// Get Value At Index
int getValueAtIndex(int index)
{
    if (index < 0 || index >= size)
        return -1;

    return tree[index];
}

// Get Size Of Tree
int getHeight()
{
    return size;
}

// Check If Tree Is Empty
int isEmpty()
{
    return size == 0;
}

int main()
{
    printf("*** Array Tree ***\n\n");
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printTree();

    int index = 2;
    printf("Parent Of %d : %d\n", tree[index], getParentValue(index));
    printf("Left Child Of %d : %d\n", tree[index], getLeftChildValue(index));
    printf("Right Child Of %d : %d\n\n", tree[index], getRightChildValue(index));

    printf("Value At Index 3 : %d\n", getValueAtIndex(3));
    printf("Height Of Tree : %d\n\n", getHeight());

    printf("Is Tree Empty ? %s\n", isEmpty() ? "Yes" : "No");
    return 0;
}
```

---
