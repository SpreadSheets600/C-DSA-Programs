# ADT Stack

## Idea Like You Are 10

A stack is like a pile of books.

You can:

- put a book on top
- remove a book from the top

But you cannot remove the book from the middle first.

This rule is called:

```text
LIFO = Last In, First Out
```

## Stack ADT Operations

- `push(x)` : add item on top
- `pop()` : remove top item
- `peek()` or `top()` : see top item
- `isEmpty()` : check if no items exist
- `isFull()` : check if stack is full in array implementation
- `display()` : show all items

## Array Representation

```text
Top
 |
 v
[10]
[20]
[30]
```

If `top = -1`, the stack is empty.

## Algorithms

### Push

```text
push(stack, x):
    if top == MAX - 1:
        overflow
    top = top + 1
    stack[top] = x
```

Time: `O(1)`

### Pop

```text
pop(stack):
    if top == -1:
        underflow
    x = stack[top]
    top = top - 1
    return x
```

Time: `O(1)`

### Peek

```text
peek(stack):
    if top == -1:
        underflow
    return stack[top]
```

Time: `O(1)`

### Is Empty

```text
isEmpty():
    return top == -1
```

Time: `O(1)`

### Is Full

```text
isFull():
    return top == MAX - 1
```

Time: `O(1)`

### Display

```text
display(stack):
    for i from top down to 0:
        print stack[i]
```

Time: `O(n)`

## Complexity Analysis

| Operation | Time |
|-----------|------|
| Push | `O(1)` |
| Pop | `O(1)` |
| Peek | `O(1)` |
| Is Empty | `O(1)` |
| Is Full | `O(1)` |
| Display | `O(n)` |

## Why These Complexities?

- `push`, `pop`, and `peek` only touch the top
- `display` must visit every element

## Space Complexity

- Array stack stores up to `n` items
- total space is `O(n)`

## Advantages

- very simple
- fast insert and delete at one end
- useful in many algorithms

## Disadvantages

- only one end is usable
- array stack has fixed size unless resized
