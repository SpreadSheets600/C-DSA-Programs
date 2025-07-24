# Programming Exercises - July 24, 2025

## Exercise 1 : Staic Liner Search

**Qestion:** Write a program to perform liner search using static memory allocation.

**Sollution:** [View Code](StaticLinearSearch.cpp)

```cpp
#include <stdio.h>
#include <stdlib.h>

int linerSearch(int arr[100], int n, int key)
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
    int n, key, arr[100];

    printf("Enter The Number Of Elements : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter The Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter The Key To Be Searched : ");
    scanf("%d", &key);

    int index = linerSearch(arr, n, key);

    if (index != 1)
    {
        printf("Element Found At Index : %d\n", index);
    }
    else
    {
        printf("Element Not Found\n");
    }

    return 0;
}
```

### OUTPUT 1

```bash
Enter The Number Of Elements : 3
Enter The Element 1 : 2
Enter The Element 2 : 6
Enter The Element 3 : 9
Enter The Key To Be Searched : 9
Element Found At Index : 2
```

## Exercise 2 : Dynamic Linear Search

**Qestion:** Write a program to perform liner search using dynamic memory allocation.

**Sollution 1:** [View Code](DynamicLinearSearch.cpp)
**Sollution 2:** [View Code](DynamicLinearSearchPointer.cpp)

```cpp
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
```

### OUTPUT 2

```bash
Enter The Number Of Elements : 3
Enter The Element 1 : 4
Enter The Element 2 : 5
Enter The Element 3 : 6
Enter The Key To Be Searched : 5
Element Found At Index : 1
```
