# Linked List Comparison

## Big Table

| Structure | Forward Move | Backward Move | Insert Front | Insert End | Delete Front | Delete End | Search |
|-----------|--------------|---------------|--------------|------------|--------------|------------|--------|
| Singly Linked List | Yes | No | `O(1)` | `O(n)` | `O(1)` | `O(n)` | `O(n)` |
| Doubly Linked List | Yes | Yes | `O(1)` | `O(1)` with tail | `O(1)` | `O(1)` if node/tail known | `O(n)` |
| Circular Linked List | Yes, in loop | No by default | `O(1)` with tail | `O(1)` with tail | `O(1)` with tail | `O(n)` | `O(n)` |

## Easy Comparison

### Singly Linked List

- simplest
- one pointer per node
- cannot move backward

### Doubly Linked List

- can move both directions
- easier deletion of known node
- uses more memory

### Circular Linked List

- last node joins back to first
- useful for repeating cycles
- very handy in round-robin systems

## Which One Should You Pick?

Choose **Singly Linked List** if:

- you want the simplest structure
- memory saving matters more

Choose **Doubly Linked List** if:

- you need backward movement
- deletion of a known node should be easy

Choose **Circular Linked List** if:

- the process repeats in cycles
- you want to keep rotating through items

## Linked Lists Vs Arrays

| Feature | Linked List | Array |
|---------|-------------|-------|
| Random access | Slow | Fast |
| Insert/delete in middle after locating node | Easy | Costly |
| Memory layout | Non-contiguous | Contiguous |
| Extra pointer space | Yes | No |
