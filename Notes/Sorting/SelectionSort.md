# Selection Sort

## Idea Like You Are 10

Imagine you want to line up kids from shortest to tallest.

You look at everyone, find the shortest kid, and place them first.

Then you look at the remaining kids, find the next shortest, and place them second.

That is Selection Sort.

## Small Example

Sort:

```text
5 3 8 1
```

Step 1: find the smallest number, which is `1`

```text
5 3 8 1
1 3 8 5
```

Step 2: from the remaining part, find the smallest number, which is `3`

```text
1 3 8 5
```

Step 3: from the remaining part, find the smallest number, which is `5`

```text
1 3 5 8
```

## Diagram

```text
Unsorted: [5] [3] [8] [1]
Smallest:              [1]
Swap with first:
[1] [3] [8] [5]

Now sort the rest:
[1] [3] [8] [5]
     sorted   unsorted
```

## Algorithm

1. Find the smallest element in the unsorted part
2. Swap it with the first unsorted position
3. Move the boundary of the sorted part one step right
4. Repeat

## Pseudocode

```text
selectionSort(arr):
    for i from 0 to n-2:
        minIndex = i
        for j from i+1 to n-1:
            if arr[j] < arr[minIndex]:
                minIndex = j
        swap arr[i], arr[minIndex]
```

## Time Complexity

| Case | Time |
|------|------|
| Best | `O(n^2)` |
| Average | `O(n^2)` |
| Worst | `O(n^2)` |

## Why This Time Complexity?

Selection Sort always searches the rest of the array to find the smallest item.

That means:

- first round checks about `n` items
- second round checks about `n-1`
- then `n-2`
- and so on

So total work is:

```text
n + (n-1) + (n-2) + ...
```

That becomes about `n^2`, even if the list was already sorted.

## Space Complexity

`O(1)` because it uses only a few extra variables.

## Performance

- Easy to understand
- Usually slower than good `O(n log n)` sorts
- Makes fewer swaps than Bubble Sort

## When To Use

- When swaps are expensive and you want to keep them low
- When teaching the idea of choosing the smallest repeatedly
