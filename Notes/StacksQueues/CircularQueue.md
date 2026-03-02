# Circular Queue

## Idea Like You Are 10

Imagine seats arranged in a circle.

After the last seat, you come back to the first seat.

That is how a circular queue works.

It reuses free spaces.

## Why It Is Better Than Simple Queue

In a simple queue, removed spaces in front may get wasted.

In a circular queue, rear can wrap around and use them again.

## Representation

```text
0 -> 1 -> 2 -> 3 -> 4
^                   |
|___________________|
```

## Full And Empty Conditions

Queue is empty when:

```text
front == -1
```

Queue is full when:

```text
(rear + 1) % MAX == front
```

## Algorithms

### Enqueue

```text
enqueue(x):
    if (rear + 1) % MAX == front:
        overflow

    if front == -1:
        front = rear = 0
    else:
        rear = (rear + 1) % MAX

    queue[rear] = x
```

Time: `O(1)`

### Dequeue

```text
dequeue():
    if front == -1:
        underflow

    x = queue[front]

    if front == rear:
        front = rear = -1
    else:
        front = (front + 1) % MAX

    return x
```

Time: `O(1)`

### Display

```text
display():
    if front == -1:
        return

    i = front
    while true:
        print queue[i]
        if i == rear:
            break
        i = (i + 1) % MAX
```

Time: `O(n)`

## Complexity Summary

| Operation | Time |
|-----------|------|
| Enqueue | `O(1)` |
| Dequeue | `O(1)` |
| Front | `O(1)` |
| Rear | `O(1)` |
| Display | `O(n)` |

## Main Advantage

Better memory usage than a simple array queue.
