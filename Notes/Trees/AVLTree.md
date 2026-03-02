# AVL Tree

## Idea Like You Are 10

An AVL tree is a BST that keeps itself balanced.

It does not allow one side to become much taller than the other.

## Balance Rule

For every node:

```text
balance factor = height(left) - height(right)
```

Allowed values:

- `-1`
- `0`
- `1`

If the balance factor goes outside that range, the tree rotates to fix itself.

## Rotations

### LL Rotation

Right rotation

### RR Rotation

Left rotation

### LR Rotation

Left then right rotation

### RL Rotation

Right then left rotation

## Insert

1. Insert like BST
2. Update heights
3. Check balance factor
4. Rotate if needed

## Delete

1. Delete like BST
2. Update heights
3. Rebalance using rotations

## Complexity Analysis

| Operation | Time |
|-----------|------|
| Search | `O(log n)` |
| Insert | `O(log n)` |
| Delete | `O(log n)` |

## Why?

AVL keeps height near `log n`, so operations travel only along a short root-to-leaf path.

## Main Advantage

Faster worst-case searching than a plain BST.

## Tradeoff

Insert and delete are more complex because rotations may be needed.
