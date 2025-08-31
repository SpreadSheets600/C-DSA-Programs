# Programming Exercises - August 25, 2025

## Exercise 1 : Binary Search Iteration And Reccursion

**Qestion:** WAP in C to implement Binary search using iteration, recursion.

**Sollution:** [View Code](BinarySearch.cpp)

```cpp
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int iterationBinarySearch(int arr[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int recursionBinarySearch(int arr[], int x, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] > x)
        {
            return recursionBinarySearch(arr, x, low, mid - 1);
        }
        else
        {
            return recursionBinarySearch(arr, x, mid + 1, high);
        }
    }
    return -1;
}

int main()
{
    int arr[100];
    int n;

    printf("Enter The Number Of Elements : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter The Element %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nEntered Array ~\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    int result1;
    int result2;

    int toSearch;
    int choice;

    do
    {
        printf("\n\n*** Binary Search Menu ***\n");
        printf("1. Search With Iteration\n");
        printf("2. Search With Recursion\n");
        printf("3. Exit\n");

        printf("\nEnter The Element To Search : ");
        scanf("%d", &toSearch);

        printf("Enter Your Choice (1 - 3) : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Binary Search With Iteration ~\n");

            result1 = iterationBinarySearch(arr, toSearch, 0, n - 1);

            if (result1 == -1)
            {
                printf("Element Not Found In The Array!\n");
            }
            else
            {
                printf("Element Found At Index %d\n", result1);
            }
            break;

        case 2:
            printf("Binary Search With Recursion ~\n");

            result2 = recursionBinarySearch(arr, toSearch, 0, n - 1);

            if (result2 == -1)
            {
                printf("Element Not Found In The Array!\n");
            }
            else
            {
                printf("Element Found At Index %d\n", result2);
            }
            break;

        case 3:
            printf("Exiting Program\n");
            exit(0);

        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (choice != 3);

    return 0;
}

```

### OUTPUT 1

```bash
Enter The Number Of Elements : 5
Enter The Element 0 : 12
Enter The Element 1 : 39
Enter The Element 2 : 71
Enter The Element 3 : 2
Enter The Element 4 : 90

Entered Array ~
12 39 71 2 90 


*** Binary Search Menu ***
1. Search With Iteration
2. Search With Recursion
3. Exit

Enter The Element To Search : 71
Enter Your Choice (1 - 3) : 1
Binary Search With Iteration ~
Element Found At Index 3


*** Binary Search Menu ***
1. Search With Iteration
2. Search With Recursion
3. Exit

Enter The Element To Search : 1
Enter Your Choice (1 - 3) : 2
Binary Search With Recursion ~
Element Not Found In The Array!


*** Binary Search Menu ***
1. Search With Iteration
2. Search With Recursion
3. Exit

Enter The Element To Search : 3
Enter Your Choice (1 - 3) : 3
Exiting Program
```

## Exercise 2 : Selection Sort

**Qestion:** WAP in C implement Selection sort using iteration.

**Sollution:** [View Code](SelectionSort.cpp)

```cpp
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n)
{
    int i, j, temp, min;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }

            if (min != i)
            {
                temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[100];
    int n;

    printf("Enter The Number Of Elements : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter The Element %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nEntered Array ~\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nSorted Array ~\n");
    printArray(arr, n);

    return 0;
}

```

### OUTPUT 2

```bash
Enter The Number Of Elements : 5
Enter The Element 0 : 12
Enter The Element 1 : 39
Enter The Element 2 : 71
Enter The Element 3 : 2
Enter The Element 4 : 90

Entered Array ~
12 39 71 2 90 

Sorted Array ~
2 12 39 71 90

```
