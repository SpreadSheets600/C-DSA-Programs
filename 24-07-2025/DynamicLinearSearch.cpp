#include <stdio.h>
#include <stdlib.h>

int linerSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
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
    int n, key, *arr;

    printf("Enter The Number Of Elements : ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter The Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter The Key To Be Searched : ");
    scanf("%d", &key);

    int index = linerSearch(arr, n, key);

    if (index != -1)
    {
        printf("Element Found At Index : %d\n", index);
    }
    else
    {
        printf("Element Not Found\n");
    }

    return 0;
}
