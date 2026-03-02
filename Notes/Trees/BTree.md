# B-Tree

## Idea Like You Are 10

A B-Tree is a balanced search tree where one node can hold many keys, not just one.

This makes it very useful for disks and databases because it reduces how often we must go to storage.

## Main Properties

- a node can have many children
- keys inside a node stay sorted
- all leaves are at the same level
- tree stays balanced

## Why Not Just Use BST?

Disk access is slow.

B-Tree keeps the tree short, so fewer disk reads are needed.

## Search

1. look inside current node
2. if key is found, stop
3. otherwise move to correct child
4. repeat

## Insertion

1. go to correct leaf
2. insert key in sorted order
3. if node overflows, split it
4. move middle key up
5. repeat upward if needed

## Deletion

Deletion is more involved.

Common ideas:

- remove from leaf if possible
- if a node gets too small, borrow from sibling
- or merge with sibling

## Complexity Analysis

| Operation | Time |
|-----------|------|
| Search | `O(log n)` |
| Insert | `O(log n)` |
| Delete | `O(log n)` |

## Why?

The tree remains balanced and very short.

Height is logarithmic in the number of keys.

## Applications

- databases
- file systems
- indexing large records
