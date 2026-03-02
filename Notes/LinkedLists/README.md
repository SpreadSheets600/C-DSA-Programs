# Linked Lists

A linked list is a way to store data where each item points to the next item.

Think of it like a treasure hunt:

- one box stores a value
- and also stores a clue telling you where the next box is

Unlike arrays, linked lists do not need all items to sit next to each other in memory.

## Files In This Folder

- [Singly Linked List](./SinglyLinkedList.md)
- [Linked Stack And Queue](./LinkedStackQueue.md)
- [Header Nodes](./HeaderNodes.md)
- [Doubly Linked List](./DoublyLinkedList.md)
- [Circular Linked List](./CircularLinkedList.md)
- [Comparison](./Comparison.md)
- [Visual Comparison](./VisualComparison.md)

## Main Types

| Type | Main Idea |
|------|-----------|
| Singly Linked List | Each node points to the next node |
| Doubly Linked List | Each node points to both next and previous |
| Circular Linked List | Last node points back to the first |

## Why Use Linked Lists?

- Easy insertion and deletion when you already know the position
- Memory does not need to be continuous
- Useful for stacks, queues, playlists, undo systems, and round-robin tasks

## Main Weakness

To reach the middle, you usually must walk step by step from the start.

That makes searching and random access slower than arrays.

## See Also

For side-by-side differences, read [Comparison](./Comparison.md).

For diagram-heavy notes, read [Visual Comparison](./VisualComparison.md).
