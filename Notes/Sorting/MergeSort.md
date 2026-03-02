# Merge Sort

## Idea Like You Are 10

Imagine tearing a big pile of cards into smaller and smaller piles until every pile has just one card.

Then you join the piles back together in sorted order.

That is Merge Sort.

## Small Example

Sort:

```text
5 3 8 1
```

Split:

```text
5 3 | 8 1
5 | 3   8 | 1
```

Single items are already sorted.

Now merge:

```text
5 and 3  -> 3 5
8 and 1  -> 1 8
```

Merge the two sorted parts:

```text
3 5 and 1 8 -> 1 3 5 8
```

## Diagram

```text
            [5 3 8 1]
            /       \
         [5 3]     [8 1]
         /   \     /   \
       [5]  [3]  [8]  [1]
         \   /     \   /
        [3 5]     [1 8]
            \     /
          [1 3 5 8]
```

## Algorithm

1. Split the array into two halves
2. Sort each half
3. Merge the two sorted halves
4. Repeat until complete

## Pseudocode

```text
mergeSort(arr):
    if array size <= 1:
        return

    split into left and right
    mergeSort(left)
    mergeSort(right)
    merge(left, right)
```

## Time Complexity

| Case | Time |
|------|------|
| Best | `O(n log n)` |
| Average | `O(n log n)` |
| Worst | `O(n log n)` |

## Why This Time Complexity?

Merge Sort always:

- splits into halves, which creates about `log n` levels
- merges all `n` elements at each level

So the work is:

```text
n * log n
```

No matter if the input is already sorted or completely messy, the time stays the same.

## Space Complexity

`O(n)` because it usually needs extra arrays while merging.

## Performance

- Very reliable
- Good for large data
- Stable sort
- Needs extra memory

## When To Use

- When you want guaranteed `O(n log n)` time
- When stability matters
- When extra memory is okay
