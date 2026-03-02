# ADT Queue

## Idea Like You Are 10

A queue is like a line of people waiting for tickets.

The person who comes first gets served first.

This rule is called:

```text
FIFO = First In, First Out
```

## Queue ADT Operations

- `enqueue(x)` : insert at rear
- `dequeue()` : remove from front
- `front()` : see front item
- `rear()` : see rear item
- `isEmpty()` : check if queue has no items
- `isFull()` : check if queue is full in array implementation
- `display()` : show items

## Picture

```text
Front                     Rear
 |                          |
 v                          v
[10] [20] [30] [40]
```

## Basic Algorithms

### Enqueue

```text
enqueue(queue, x):
    if queue is full:
        overflow
    rear = rear + 1
    queue[rear] = x
```

### Dequeue

```text
dequeue(queue):
    if queue is empty:
        underflow
    x = queue[front]
    front = front + 1
    return x
```

### Front

```text
front(queue):
    if queue is empty:
        underflow
    return queue[front]
```

### Rear

```text
rear(queue):
    if queue is empty:
        underflow
    return queue[rear]
```

## Complexity Analysis

| Operation | Time |
|-----------|------|
| Enqueue | `O(1)` |
| Dequeue | `O(1)` |
| Front | `O(1)` |
| Rear | `O(1)` |
| Is Empty | `O(1)` |
| Is Full | `O(1)` |
| Display | `O(n)` |

## Problem In Simple Array Queue

If front moves forward again and again, empty spaces at the beginning get wasted.

That is why circular queue is useful.
