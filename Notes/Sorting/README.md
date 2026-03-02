# Sorting Techniques

Sorting means putting things in order, usually from **smallest to biggest**.

Example:

```text
Before: 8 3 5 1 4
After : 1 3 4 5 8
```

Think of sorting like arranging books from shortest to tallest, or lining up students by height.

## Files In This Folder

- [Bubble Sort](./BubbleSort.md)
- [Insertion Sort](./InsertionSort.md)
- [Selection Sort](./SelectionSort.md)
- [Quick Sort](./QuickSort.md)
- [Merge Sort](./MergeSort.md)
- [Heap Sort](./HeapSort.md)
- [Comparison](./Comparison.md)
- [Visual Comparison](./VisualComparison.md)

## Fast Idea Of Each Method

| Algorithm | Main Idea |
|-----------|-----------|
| Bubble Sort | Big items "bubble" to the end by swapping neighbors |
| Insertion Sort | Put each new item into the correct place in the sorted part |
| Selection Sort | Repeatedly pick the smallest item and put it in front |
| Quick Sort | Pick a pivot, split into smaller and bigger parts, sort them |
| Merge Sort | Split into halves, sort them, then merge back together |
| Heap Sort | Build a special tree shape and repeatedly remove the largest |

## Which Ones Are Usually Faster?

For very small lists, **Insertion Sort** is often good.

For large lists:

- **Quick Sort** is usually very fast in practice
- **Merge Sort** is very reliable and always `O(n log n)` time
- **Heap Sort** is also `O(n log n)` time, but often a bit less friendly to understand

## Easy Memory Trick

- `O(n^2)` sorts: Bubble, Insertion, Selection
- `O(n log n)` sorts: Quick (average), Merge, Heap

## See Also

For the side-by-side table and when to use each one, read [Comparison](./Comparison.md).

For diagram-heavy visuals, read [Visual Comparison](./VisualComparison.md).
