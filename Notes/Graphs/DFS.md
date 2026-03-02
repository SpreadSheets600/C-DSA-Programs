# Depth-First Search (DFS)

## Idea Like You Are 10

DFS goes as deep as possible on one path before coming back.

It is like exploring a maze:

- pick one path
- keep walking
- if stuck, come back
- try another path

## Data Structure Used

- recursion stack
- or an explicit stack

## Example

```text
A: B C
B: D E
C: F
```

One possible DFS order from `A`:

```text
A, B, D, E, C, F
```

## Recursive Algorithm

```text
DFS(graph, node):
    mark node as visited
    print node

    for each neighbor of node:
        if neighbor not visited:
            DFS(graph, neighbor)
```

## Time Complexity

`O(V + E)`

## Why?

- every vertex is visited once
- every edge is explored once in adjacency list form

## Space Complexity

`O(V)`

Because recursion or stack can grow with the number of vertices.

## Applications

- cycle detection
- connected components
- topological sort
- maze solving
