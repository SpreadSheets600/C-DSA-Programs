# Singly Linked List

## Idea Like You Are 10

A singly linked list is like a chain of train cars.

Each car has:

- some data
- a link to the next car

The last car points to `NULL`, which means "no more cars".

## Representation In Memory

Each node stores:

```text
[Data | Next]
```

Example:

```text
Head
 |
 v
[10|*] -> [20|*] -> [30|NULL]
```

Important:

- nodes may be stored in different memory places
- the links connect them logically

So memory may look like this:

```text
Address 100: [20 | 500]
Address 320: [10 | 100]
Address 500: [30 | NULL]

Head = 320
```

Even though the nodes are not next to each other in memory, the list still works.

## Basic Operations

### 1. Traversing

Move from node to node until `NULL`.

```text
traverse(head):
    temp = head
    while temp != NULL:
        print temp.data
        temp = temp.next
```

Time: `O(n)`

Why: in the worst case you visit every node once.

### 2. Searching

Check nodes one by one until the value is found or the list ends.

```text
search(head, key):
    temp = head
    while temp != NULL:
        if temp.data == key:
            return found
        temp = temp.next
    return not found
```

Time:

- Best: `O(1)`
- Worst: `O(n)`

Why:

- best case: key is at the head
- worst case: key is at the end or not present

### 3. Insertion At Beginning

Create a new node and make it the new head.

```text
insertFront(head, x):
    newNode = create node
    newNode.data = x
    newNode.next = head
    head = newNode
```

Time: `O(1)`

Why: only pointer updates are needed.

### 4. Insertion At End

Walk to the last node, then attach the new node.

```text
insertEnd(head, x):
    newNode = create node
    newNode.data = x
    newNode.next = NULL

    if head == NULL:
        head = newNode
        return

    temp = head
    while temp.next != NULL:
        temp = temp.next
    temp.next = newNode
```

Time: `O(n)`

Why: you may need to walk through the whole list.

### 5. Insertion After A Given Node

```text
insertAfter(node, x):
    if node == NULL:
        return
    newNode = create node
    newNode.data = x
    newNode.next = node.next
    node.next = newNode
```

Time: `O(1)` if the node is already known.

### 6. Deletion From Beginning

```text
deleteFront(head):
    if head == NULL:
        return
    temp = head
    head = head.next
    delete temp
```

Time: `O(1)`

### 7. Deletion From End

```text
deleteEnd(head):
    if head == NULL:
        return
    if head.next == NULL:
        delete head
        head = NULL
        return

    temp = head
    while temp.next.next != NULL:
        temp = temp.next
    delete temp.next
    temp.next = NULL
```

Time: `O(n)`

Why: you must reach the second last node.

### 8. Deletion Of A Given Key

```text
deleteKey(head, key):
    if head == NULL:
        return
    if head.data == key:
        temp = head
        head = head.next
        delete temp
        return

    temp = head
    while temp.next != NULL and temp.next.data != key:
        temp = temp.next

    if temp.next == NULL:
        return

    target = temp.next
    temp.next = target.next
    delete target
```

Time:

- Best: `O(1)`
- Worst: `O(n)`

## Complexity Summary

| Operation | Time |
|-----------|------|
| Traverse | `O(n)` |
| Search | `O(n)` |
| Insert at front | `O(1)` |
| Insert at end | `O(n)` |
| Insert after known node | `O(1)` |
| Delete from front | `O(1)` |
| Delete from end | `O(n)` |
| Delete given key | `O(n)` |

## Space Complexity

Each node stores:

- data
- one pointer

Total list space: `O(n)`

Extra working space for normal operations: `O(1)`

## Advantages

- Easy insert/delete at front
- Dynamic size
- No need for contiguous memory

## Disadvantages

- No direct access like arrays
- Extra memory for pointer
- One-way movement only
