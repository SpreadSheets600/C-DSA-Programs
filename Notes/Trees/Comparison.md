# Trees Comparison

## Big Table

| Tree | Search | Insert | Delete | Main Strength |
|------|--------|--------|--------|---------------|
| Binary Tree | `O(n)` | `O(n)` | `O(n)` | Simple hierarchical structure |
| Threaded Binary Tree | `O(n)` | `O(h)` | `O(h)` | Easier traversal |
| BST | `O(log n)` average, `O(n)` worst | `O(log n)` average, `O(n)` worst | `O(log n)` average, `O(n)` worst | Ordered searching |
| AVL Tree | `O(log n)` | `O(log n)` | `O(log n)` | Guaranteed balance |
| B-Tree | `O(log n)` | `O(log n)` | `O(log n)` | Good for storage systems |
| B+ Tree | `O(log n)` | `O(log n)` | `O(log n)` | Excellent indexing and range scans |

## Easy Comparison

### Binary Tree

- simple
- no search ordering rule

### Threaded Binary Tree

- traversal friendly
- uses empty links cleverly

### BST

- faster than plain binary tree when balanced enough
- can become skewed

### AVL Tree

- stricter balancing
- very good search performance

### B-Tree

- short and wide tree
- designed for disk access

### B+ Tree

- even better for database-style ordered searches
- linked leaves help range queries
