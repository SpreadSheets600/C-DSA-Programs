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
