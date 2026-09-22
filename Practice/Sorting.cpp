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
