# Bubble Sort

## Idea Like You Are 10

Imagine numbers are standing in a line.

You look at **two neighbors at a time**:

- If they are in the wrong order, swap them
- Keep doing that again and again

The biggest number keeps moving right, like a bubble floating up in water.

## Small Example

Sort:

```text
5 3 8 1
```

Pass 1:

```text
5 3 8 1
3 5 8 1   swap 5 and 3
3 5 8 1   5 and 8 are fine
3 5 1 8   swap 8 and 1
```

Now the biggest number, `8`, is in the correct place.

Pass 2:

```text
3 5 1 8
3 5 1 8   3 and 5 are fine
3 1 5 8   swap 5 and 1
```

Pass 3:

```text
3 1 5 8
1 3 5 8   swap 3 and 1
```

Sorted.

## Diagram

```text
Start:   [5] [3] [8] [1]
          |---|
Swap ->  [3] [5] [8] [1]

Then move right:
               |---|
No swap -> [3] [5] [8] [1]

Then move right:
                    |---|
Swap ->     [3] [5] [1] [8]
```

## Algorithm

1. Compare neighboring elements
2. Swap if left is bigger than right
3. After one full pass, the biggest unsorted element reaches the end
4. Repeat for the remaining unsorted part

## Pseudocode

```text
bubbleSort(arr):
    repeat n-1 times:
        swapped = false
        for i from 0 to n-2:
            if arr[i] > arr[i+1]:
                swap arr[i], arr[i+1]
                swapped = true
        if swapped == false:
            stop early
```

## Time Complexity

| Case | Time |
|------|------|
| Best | `O(n)` |
| Average | `O(n^2)` |
| Worst | `O(n^2)` |

## Why This Time Complexity?

### Best Case: `O(n)`

If the list is already sorted, we make one pass, see no swaps, and stop.

That means we check about `n` elements once.

### Average And Worst Case: `O(n^2)`

In the average or bad case, we may do:

- about `n` passes
- and in each pass, about `n` comparisons

So it becomes:

```text
n * n = n^2
```

## Space Complexity

`O(1)` because it sorts in the same array and uses only a tiny amount of extra memory.

## Performance

- Very easy to understand
- Very slow for big lists
- Good for learning, not usually for real large programs

## When To Use

- When you are just starting to learn sorting
- When the list is tiny
- When you want a simple idea, not the fastest one
