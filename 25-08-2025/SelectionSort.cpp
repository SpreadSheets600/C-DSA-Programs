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
