# Breadth-First Search (BFS)

## Idea Like You Are 10

BFS explores a graph layer by layer.

If you start at one node, BFS first visits:

- all close neighbors
- then neighbors of those neighbors
- then the next layer

It works like a spreading ripple in water.

## Data Structure Used

Queue

Because the first discovered node should be processed first.

## Example

```text
A: B C
B: D E
C: F
```

Starting from `A`, BFS order is:

```text
A, B, C, D, E, F
```

## Algorithm

```text
BFS(graph, start):
    mark start as visited
    create empty queue
    enqueue(start)

    while queue is not empty:
        node = dequeue()
        print node

        for each neighbor of node:
            if neighbor not visited:
                mark neighbor visited
                enqueue(neighbor)
```

## Time Complexity

`O(V + E)`

## Why?

- every vertex is visited at most once
- every edge is checked at most once in an adjacency list representation

## Space Complexity

`O(V)`

Because the queue and visited structure may store many vertices.

## Applications

- shortest path in unweighted graphs
- social network levels
- network broadcasting
- web crawling
