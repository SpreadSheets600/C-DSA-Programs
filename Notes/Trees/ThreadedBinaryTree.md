# Threaded Binary Tree

## Idea Like You Are 10

In a normal binary tree, many child pointers are empty.

A threaded binary tree uses some of those empty pointers to point to the next node in traversal order.

This helps traversal happen without stack or recursion in some cases.

## Simple Idea

In an **inorder threaded tree**:

- if a node has no right child
- its right pointer may point to its inorder successor

That special pointer is called a **thread**.

## Why Use It?

- easier traversal
- less need for recursion stack

## Inorder Traversal Idea

```text
inorderThreaded(root):
    go to leftmost node
    while current != NULL:
        visit current
        if current has thread:
            current = current.right
        else:
            current = leftmost node of current.right
```

## Operations

### Traversal

Time: `O(n)`

### Search

Time: `O(n)`

### Insertion

Insertion must carefully update:

- normal child links
- thread links

Time: usually `O(h)` after reaching the place, where `h` is tree height.

### Deletion

Deletion is more complex because threads must be fixed.

Time: usually `O(h)` plus thread adjustment work.

## Complexity Summary

| Operation | Time |
|-----------|------|
| Traversal | `O(n)` |
| Search | `O(n)` |
| Insert | `O(h)` |
| Delete | `O(h)` |

## Main Advantage

Traversal becomes more efficient in terms of auxiliary space.

## Space Note

Traversal can be done with `O(1)` extra space in the threaded approach.
