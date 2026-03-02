# Binary Tree

## Idea Like You Are 10

A binary tree is a tree where each node can have:

- no child
- one child
- or two children

The two sides are called:

- left child
- right child

## Picture

```text
        A
       / \
      B   C
     / \   \
    D   E   F
```

## Types Of Binary Trees

### Full Binary Tree

Every node has either 0 or 2 children.

### Complete Binary Tree

All levels are full except maybe the last, and the last fills from left to right.

### Perfect Binary Tree

All internal nodes have 2 children and all leaves are at the same level.

### Balanced Binary Tree

Tree height stays fairly small.

## Operations

### Traversals

#### Preorder

Root, Left, Right

```text
preorder(node):
    if node == NULL:
        return
    visit node
    preorder(node.left)
    preorder(node.right)
```

#### Inorder

Left, Root, Right

```text
inorder(node):
    if node == NULL:
        return
    inorder(node.left)
    visit node
    inorder(node.right)
```

#### Postorder

Left, Right, Root

```text
postorder(node):
    if node == NULL:
        return
    postorder(node.left)
    postorder(node.right)
    visit node
```

#### Level Order

Uses queue.

```text
levelOrder(root):
    if root == NULL:
        return
    enqueue(root)
    while queue not empty:
        node = dequeue()
        visit node
        if node.left != NULL:
            enqueue(node.left)
        if node.right != NULL:
            enqueue(node.right)
```

### Insertion In General Binary Tree

One common method inserts at the first empty place in level order.

```text
insert(root, x):
    newNode = create node
    if root == NULL:
        root = newNode
        return

    enqueue(root)
    while queue not empty:
        temp = dequeue()
        if temp.left == NULL:
            temp.left = newNode
            return
        else:
            enqueue(temp.left)

        if temp.right == NULL:
            temp.right = newNode
            return
        else:
            enqueue(temp.right)
```

### Deletion In General Binary Tree

One common method:

1. find node to delete
2. find deepest rightmost node
3. copy deepest node's data
4. delete deepest node

## Complexity Analysis

| Operation | Time |
|-----------|------|
| Traversal | `O(n)` |
| Search | `O(n)` |
| Insert (level order) | `O(n)` |
| Delete | `O(n)` |

## Why?

In a normal binary tree there is no ordering rule like BST.

So you may need to inspect many nodes.
