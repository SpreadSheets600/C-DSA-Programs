# Circular Linked List

## Idea Like You Are 10

In a circular linked list, the last node does not point to `NULL`.

Instead, it points back to the first node.

So the list forms a circle.

## Picture

```text
Head
 |
 v
[10|*] -> [20|*] -> [30|*]
  ^                       |
  |_______________________|
```

## Why Use It?

- useful when data must repeat in rounds
- useful in round-robin scheduling
- good for circular queues and playlists

## Operations

### 1. Traversing

Stop when you come back to the head.

```text
traverse(head):
    if head == NULL:
        return
    temp = head
    do:
        print temp.data
        temp = temp.next
    while temp != head
```

Time: `O(n)`

### 2. Searching

```text
search(head, key):
    if head == NULL:
        return not found

    temp = head
    do:
        if temp.data == key:
            return found
        temp = temp.next
    while temp != head

    return not found
```

Time:

- Best: `O(1)`
- Worst: `O(n)`

### 3. Insertion At Beginning

One common method uses a tail pointer.

If `tail` is known, then `head = tail.next`.

```text
insertFront(tail, x):
    newNode = create node
    newNode.data = x

    if tail == NULL:
        tail = newNode
        newNode.next = newNode
        return

    newNode.next = tail.next
    tail.next = newNode
```

Time: `O(1)` with tail pointer.

### 4. Insertion At End

```text
insertEnd(tail, x):
    insertFront(tail, x)
    tail = tail.next
```

Time: `O(1)` with tail pointer.

### 5. Insertion After A Given Node

```text
insertAfter(node, x):
    newNode = create node
    newNode.data = x
    newNode.next = node.next
    node.next = newNode
```

Time: `O(1)`

### 6. Deletion From Beginning

```text
deleteFront(tail):
    if tail == NULL:
        return

    head = tail.next

    if head == tail:
        delete head
        tail = NULL
        return

    tail.next = head.next
    delete head
```

Time: `O(1)`

### 7. Deletion From End

```text
deleteEnd(tail):
    if tail == NULL:
        return

    head = tail.next

    if head == tail:
        delete tail
        tail = NULL
        return

    temp = head
    while temp.next != tail:
        temp = temp.next

    temp.next = tail.next
    delete tail
    tail = temp
```

Time: `O(n)`

Why: you must find the node before the tail.

### 8. Deletion Of A Given Key

```text
deleteKey(tail, key):
    if tail == NULL:
        return

    prev = tail
    curr = tail.next

    do:
        if curr.data == key:
            if curr == prev:
                delete curr
                tail = NULL
                return

            prev.next = curr.next

            if curr == tail:
                tail = prev

            delete curr
            return

        prev = curr
        curr = curr.next
    while curr != tail.next
```

Time: `O(n)`

## Complexity Summary

| Operation | Time |
|-----------|------|
| Traverse | `O(n)` |
| Search | `O(n)` |
| Insert at front with tail | `O(1)` |
| Insert at end with tail | `O(1)` |
| Insert after known node | `O(1)` |
| Delete front with tail | `O(1)` |
| Delete end | `O(n)` |
| Delete given key | `O(n)` |

## Extra Notes

Circular linked lists are often easier to manage when a tail pointer is kept.

Without a tail pointer, some operations become slower.
