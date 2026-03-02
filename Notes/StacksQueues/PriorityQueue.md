# Priority Queue

## Idea Like You Are 10

In a normal queue, the first person in line goes first.

In a priority queue, a more important person may go first.

Example:

- emergency patient first
- regular patient later

So removal depends on priority, not just arrival time.

## How It Works

Each item has:

- data
- priority

Example:

```text
(A, 3), (B, 1), (C, 2)
```

If smaller number means higher priority, then `B` leaves first.

## Common Operations

- insert item with priority
- delete highest-priority item
- peek highest-priority item

## Simple Array-Based Method

### Insert

If unsorted array is used:

```text
insert(x, p):
    add (x, p) at the end
```

Time: `O(1)`

### Delete Highest Priority

```text
deletePriority():
    find highest-priority item
    remove it
    shift remaining items if needed
```

Time: `O(n)`

### Peek Highest Priority

```text
peekPriority():
    scan all items and return highest-priority one
```

Time: `O(n)`

## Sorted Array Method

If the array is kept sorted by priority:

- insertion becomes `O(n)`
- deletion from front may become `O(1)`

## Heap-Based Priority Queue

Using a heap:

- insertion: `O(log n)`
- deletion of highest priority: `O(log n)`
- peek: `O(1)`

This is the most common efficient implementation.

## Complexity Summary

| Implementation | Insert | Delete Highest Priority | Peek |
|----------------|--------|-------------------------|------|
| Unsorted Array | `O(1)` | `O(n)` | `O(n)` |
| Sorted Array | `O(n)` | `O(1)` | `O(1)` |
| Heap | `O(log n)` | `O(log n)` | `O(1)` |

## Applications

- CPU scheduling
- printer task handling
- network packet handling
- graph algorithms like Dijkstra and Prim
