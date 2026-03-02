# Insertion Sort

## Idea Like You Are 10

Imagine you are holding playing cards.

You pick one card at a time and slide it into the correct spot among the cards already in your hand.

That is exactly how Insertion Sort works.

## Small Example

Sort:

```text
5 3 8 1
```

Start:

```text
[5] | 3 8 1
```

`[5]` is the sorted part.

Insert `3`:

```text
3 5 | 8 1
```

Insert `8`:

```text
3 5 8 | 1
```

Insert `1`:

```text
1 3 5 8
```

## Diagram

```text
Sorted part   Unsorted part
[5]           [3] [8] [1]

Take 3 and insert it:
[3] [5]       [8] [1]

Take 8 and insert it:
[3] [5] [8]   [1]
```

## Algorithm

1. Pretend the first element is already sorted
2. Take the next element
3. Move bigger elements one step right
4. Put the current element in its correct place
5. Repeat

## Pseudocode

```text
insertionSort(arr):
    for i from 1 to n-1:
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
```

## Time Complexity

| Case | Time |
|------|------|
| Best | `O(n)` |
| Average | `O(n^2)` |
| Worst | `O(n^2)` |

## Why This Time Complexity?

### Best Case: `O(n)`

If the list is already sorted, each new item is already in the right place.

So we only do one quick check for each element.

### Average Case: `O(n^2)`

Usually, each new element must move left a little bit.

That creates many shifts over and over.

### Worst Case: `O(n^2)`

If the list is in reverse order, every new element must move across almost the whole sorted part.

Example:

```text
5 4 3 2 1
```

The total work becomes:

```text
1 + 2 + 3 + ... + (n-1)
```

That adds up to about `n^2`.

## Space Complexity

`O(1)` because it sorts in place.

## Performance

- Great for very small lists
- Great when the list is already almost sorted
- Slow for large random lists

## When To Use

- Small arrays
- Nearly sorted data
- As a helper inside bigger sorting systems
