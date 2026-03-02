# Simple Queue

A simple queue is the normal queue implemented using an array or linked list.

## Array Representation

Use two variables:

- `front`
- `rear`

Example:

```text
Index: 0   1   2   3   4
Data : 10  20  30  _   _
        ^       ^
      front    rear
```

## Operations

### Enqueue

```text
enqueue(x):
    if rear == MAX - 1:
        overflow
    if front == -1:
        front = 0
    rear = rear + 1
    queue[rear] = x
```

Time: `O(1)`

### Dequeue

```text
dequeue():
    if front == -1 or front > rear:
        underflow
    x = queue[front]
    front = front + 1
    return x
```

Time: `O(1)`

### Peek Front

```text
peekFront():
    return queue[front]
```

Time: `O(1)`

### Display

```text
display():
    for i from front to rear:
        print queue[i]
```

Time: `O(n)`

## Complexity Summary

| Operation | Time |
|-----------|------|
| Enqueue | `O(1)` |
| Dequeue | `O(1)` |
| Peek Front | `O(1)` |
| Display | `O(n)` |

## Weakness

After several dequeues, the front moves right and free spots on the left cannot be reused easily in the simple array version.

This waste is called false overflow.
