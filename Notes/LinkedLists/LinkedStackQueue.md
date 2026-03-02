# Linked Representation Of Stack And Queue

Linked lists can be used to build stacks and queues.

## Linked Stack

A stack follows:

```text
LIFO = Last In, First Out
```

Like a pile of plates.

### Representation

Use the head of the linked list as the top of the stack.

```text
Top
 |
 v
[30|*] -> [20|*] -> [10|NULL]
```

### Stack Operations

#### Push

Insert at the front.

```text
push(top, x):
    newNode = create node
    newNode.data = x
    newNode.next = top
    top = newNode
```

Time: `O(1)`

#### Pop

Delete from the front.

```text
pop(top):
    if top == NULL:
        underflow
    temp = top
    top = top.next
    delete temp
```

Time: `O(1)`

#### Peek

Read the front node.

Time: `O(1)`

## Linked Queue

A queue follows:

```text
FIFO = First In, First Out
```

Like people standing in a line.

### Representation

Keep two pointers:

- `front`
- `rear`

```text
Front                         Rear
 |                              |
 v                              v
[10|*] -> [20|*] -> [30|NULL]
```

### Queue Operations

#### Enqueue

Insert at the rear.

```text
enqueue(front, rear, x):
    newNode = create node
    newNode.data = x
    newNode.next = NULL

    if rear == NULL:
        front = rear = newNode
        return

    rear.next = newNode
    rear = newNode
```

Time: `O(1)`

#### Dequeue

Delete from the front.

```text
dequeue(front, rear):
    if front == NULL:
        underflow

    temp = front
    front = front.next

    if front == NULL:
        rear = NULL

    delete temp
```

Time: `O(1)`

## Complexity Summary

| Structure | Operation | Time |
|-----------|-----------|------|
| Stack | Push | `O(1)` |
| Stack | Pop | `O(1)` |
| Stack | Peek | `O(1)` |
| Queue | Enqueue | `O(1)` |
| Queue | Dequeue | `O(1)` |
| Queue | Front | `O(1)` |

## Why Linked Lists Work Well Here

- insertion/deletion at ends can be done with pointer updates
- no fixed size is required
- overflow happens only when memory is full
