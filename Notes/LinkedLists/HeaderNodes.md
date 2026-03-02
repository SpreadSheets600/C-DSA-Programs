# Header Nodes

A header node is a special extra node placed at the beginning of a linked list.

It may:

- store no actual user data
- store metadata like count of nodes
- help simplify insertion and deletion

## Simple Picture

```text
Header -> [10|*] -> [20|*] -> [30|NULL]
```

The header is not treated like a normal data node.

## Why Use A Header Node?

- avoids special cases at the beginning of the list
- can store length information
- makes algorithms cleaner

## Example: Insert At Beginning With Header

Without header:

- changing the head needs special handling

With header:

```text
insertFront(header, x):
    newNode = create node
    newNode.data = x
    newNode.next = header.next
    header.next = newNode
```

Time: `O(1)`

## Example: Delete First Data Node

```text
deleteFront(header):
    if header.next == NULL:
        return
    temp = header.next
    header.next = temp.next
    delete temp
```

Time: `O(1)`

## Complexity

Header nodes do not change the big-O complexity much.

They mainly make edge cases easier to handle.

## Good Use Cases

- lists with many insert/delete operations
- implementations where cleaner code matters
- circular lists with sentinel-style design
