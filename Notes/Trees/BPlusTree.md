# B+ Tree

## Idea Like You Are 10

A B+ Tree is like a B-Tree, but it stores actual record access mainly in the leaf nodes.

Internal nodes mostly guide the search.

Leaves are often linked together, which makes range searching very fast.

## Main Properties

- balanced multiway tree
- internal nodes store guide keys
- leaf nodes store data entries
- leaves are linked in order

## Search

1. start at root
2. move down using guide keys
3. reach a leaf
4. find the key there

## Insertion

1. insert key into correct leaf
2. if leaf overflows, split it
3. copy separator upward
4. continue if parent overflows

## Deletion

1. remove key from leaf
2. if underflow happens, borrow or merge
3. update parent separators if needed

## Complexity Analysis

| Operation | Time |
|-----------|------|
| Search | `O(log n)` |
| Insert | `O(log n)` |
| Delete | `O(log n)` |
| Range Search | very efficient |

## Why B+ Tree Is So Popular

- all data appears in leaves
- leaf links make ordered scanning easy
- great for database indexes

## B-Tree Vs B+ Tree Quick Idea

- B-Tree: data may appear in internal and leaf nodes
- B+ Tree: search path goes to leaves, and leaves are linked
