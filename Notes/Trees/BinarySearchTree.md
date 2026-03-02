# Binary Search Tree (BST)

## Idea Like You Are 10

A BST is a binary tree with a special rule:

- left side has smaller values
- right side has larger values

That rule makes searching faster.

## Picture

```text
        50
       /  \
     30    70
    / \   / \
   20 40 60 80
```

## Search

```text
search(root, key):
    if root == NULL or root.data == key:
        return root
    if key < root.data:
        return search(root.left, key)
    else:
        return search(root.right, key)
```

## Insert

```text
insert(root, key):
    if root == NULL:
        return new node(key)
    if key < root.data:
        root.left = insert(root.left, key)
    else if key > root.data:
        root.right = insert(root.right, key)
    return root
```

## Delete

Three cases:

1. node is a leaf
2. node has one child
3. node has two children

For case 3, replace with inorder successor or predecessor.

```text
delete(root, key):
    if root == NULL:
        return NULL

    if key < root.data:
        root.left = delete(root.left, key)
    else if key > root.data:
        root.right = delete(root.right, key)
    else:
        if root.left == NULL:
            return root.right
        if root.right == NULL:
            return root.left

        temp = minimum(root.right)
        root.data = temp.data
        root.right = delete(root.right, temp.data)
    return root
```

## Traversal

Inorder traversal of BST gives sorted order.

## Complexity Analysis

| Operation | Average | Worst |
|-----------|---------|-------|
| Search | `O(log n)` | `O(n)` |
| Insert | `O(log n)` | `O(n)` |
| Delete | `O(log n)` | `O(n)` |

## Why?

- if the tree stays balanced, height is about `log n`
- if it becomes skewed like a chain, height becomes `n`

Example of bad case:

```text
10 -> 20 -> 30 -> 40
```

That is why self-balancing trees are useful.
