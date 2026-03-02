# Heap Sort

## Idea Like You Are 10

Heap Sort uses a special tree shape called a **heap**.

In a max-heap:

- the biggest number is always at the top

So Heap Sort does this:

1. Build a max-heap
2. Take the biggest element from the top
3. Put it at the end
4. Fix the heap
5. Repeat

## Small Example

Sort:

```text
4 10 3 5 1
```

After building a max-heap, the biggest value goes to the top.

One possible heap view:

```text
        10
       /  \
      5    3
     / \
    4   1
```

Now swap the top with the last element:

```text
10 goes to the end
```

Then fix the heap again with the remaining elements.

Keep repeating until sorted.

## Diagram

```text
Max-Heap:
        9
       / \
      7   6
     / \
    3   2

Largest is always at the top.
Move it to the end, then rebuild the top.
```

## Algorithm

1. Convert the array into a max-heap
2. Swap the first element with the last unsorted element
3. Reduce heap size by one
4. Heapify again
5. Repeat

## Pseudocode

```text
heapSort(arr):
    buildMaxHeap(arr)
    for end from n-1 down to 1:
        swap arr[0], arr[end]
        heapify(arr, size = end, root = 0)
```

## Time Complexity

| Case | Time |
|------|------|
| Best | `O(n log n)` |
| Average | `O(n log n)` |
| Worst | `O(n log n)` |

## Why This Time Complexity?

Building the heap takes `O(n)`.

Then we remove the largest element `n` times, and each time fixing the heap takes about `O(log n)`.

So total work is about:

```text
n * log n
```

That gives `O(n log n)`.

## Space Complexity

`O(1)` extra space for the common in-place version.

## Performance

- Good guaranteed speed
- Does not need extra array space like Merge Sort
- Usually not as fast in practice as a good Quick Sort

## When To Use

- When you want guaranteed `O(n log n)` time
- When you also want in-place sorting
