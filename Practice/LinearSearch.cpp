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
