# Doubly Linked List

## Idea Like You Are 10

A doubly linked list is like a chain where each node knows:

- who comes next
- who came before

So you can move both forward and backward.

## Node Structure

```text
[Prev | Data | Next]
```

Example:

```text
NULL <- [10] <-> [20] <-> [30] -> NULL
```

## Operations

### 1. Traversing Forward

```text
traverseForward(head):
    temp = head
    while temp != NULL:
        print temp.data
        temp = temp.next
```

Time: `O(n)`

### 2. Traversing Backward

If you have the tail pointer:

```text
traverseBackward(tail):
    temp = tail
    while temp != NULL:
        print temp.data
        temp = temp.prev
```

Time: `O(n)`

### 3. Insertion At Beginning

```text
insertFront(head, x):
    newNode = create node
    newNode.data = x
    newNode.prev = NULL
    newNode.next = head

    if head != NULL:
        head.prev = newNode
    head = newNode
```

Time: `O(1)`

### 4. Insertion At End

If tail is known:

```text
insertEnd(tail, x):
    newNode = create node
    newNode.data = x
    newNode.next = NULL
    newNode.prev = tail

    if tail != NULL:
        tail.next = newNode
    tail = newNode
```

Time: `O(1)` with tail pointer, otherwise `O(n)`.

### 5. Insertion After A Given Node

```text
insertAfter(node, x):
    if node == NULL:
        return
    newNode = create node
    newNode.data = x
    newNode.next = node.next
    newNode.prev = node

    if node.next != NULL:
        node.next.prev = newNode
    node.next = newNode
```

Time: `O(1)`

### 6. Deletion Of A Given Node

```text
deleteNode(head, node):
    if node == NULL:
        return

    if node.prev != NULL:
        node.prev.next = node.next
    else:
        head = node.next

    if node.next != NULL:
        node.next.prev = node.prev

    delete node
```

Time: `O(1)` if the node is already known.

### 7. Searching

```text
search(head, key):
    temp = head
    while temp != NULL:
        if temp.data == key:
            return found
        temp = temp.next
    return not found
```

Time: `O(n)`

## Complexity Summary

| Operation | Time |
|-----------|------|
| Traverse forward | `O(n)` |
| Traverse backward | `O(n)` |
| Search | `O(n)` |
| Insert at front | `O(1)` |
| Insert at end with tail | `O(1)` |
| Insert after known node | `O(1)` |
| Delete known node | `O(1)` |

## Why It Can Be Better Than Singly Linked List

- easier deletion of a known node
- easy backward traversal
- useful for browser back/forward, undo/redo

## Weakness

- extra pointer memory
- slightly more pointer updates
