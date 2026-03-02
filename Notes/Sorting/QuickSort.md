# Quick Sort

## Idea Like You Are 10

Pick one number and call it the **pivot**.

Now split everything into:

- numbers smaller than the pivot
- the pivot
- numbers bigger than the pivot

Then do the same thing again for the left part and the right part.

This is called **divide and conquer**.

## Small Example

Sort:

```text
5 3 8 1 4
```

Pick pivot = `5`

Split:

```text
Smaller: 3 1 4
Pivot  : 5
Bigger : 8
```

Now sort the smaller part:

```text
3 1 4
```

Pick pivot = `3`

```text
Smaller: 1
Pivot  : 3
Bigger : 4
```

Now combine:

```text
1 3 4 5 8
```

## Diagram

```text
                [5 3 8 1 4]
                     |
                 pivot = 5
               /     |     \
         [3 1 4]    [5]    [8]
            |
         pivot = 3
         /   |   \
       [1] [3] [4]
```

## Algorithm

1. Choose a pivot
2. Put smaller elements on one side
3. Put bigger elements on the other side
4. Recursively sort both sides

## Pseudocode

```text
quickSort(arr):
    if array has 0 or 1 item:
        return

    choose pivot
    partition array into left and right
    quickSort(left)
    quickSort(right)
```

## Time Complexity

| Case | Time |
|------|------|
| Best | `O(n log n)` |
| Average | `O(n log n)` |
| Worst | `O(n^2)` |

## Why This Time Complexity?

### Best And Average Case: `O(n log n)`

If the pivot splits the array into two fairly equal parts:

- there are about `log n` levels
- each level processes about `n` elements

So:

```text
n * log n
```

### Worst Case: `O(n^2)`

If the pivot is always terrible, like always the smallest or largest item, the split becomes very uneven.

Example:

```text
1 2 3 4 5
```

If we always choose the first or last element as pivot, we get:

```text
n + (n-1) + (n-2) + ...
```

That becomes `O(n^2)`.

## Space Complexity

- Usually `O(log n)` extra stack space because of recursion
- In the worst case, recursion stack can become `O(n)`

## Performance

- Usually one of the fastest in real programs
- Very popular
- Can become slow with bad pivot choices

## When To Use

- Large arrays
- General-purpose fast sorting
- When average speed matters a lot
