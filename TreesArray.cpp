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
