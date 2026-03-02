# Dijkstra's Algorithm

## Idea Like You Are 10

Dijkstra helps find the shortest path when roads have distances.

It keeps choosing the not-yet-finished node with the smallest known distance.

## Important Rule

Dijkstra works correctly when edge weights are **non-negative**.

## Main Idea

1. Start with source distance `0`
2. Other distances are infinity
3. Repeatedly pick the closest unfinished node
4. Try to improve distances of its neighbors

This improving step is called **relaxation**.

## Algorithm

```text
dijkstra(graph, source):
    for each vertex:
        dist[vertex] = infinity
    dist[source] = 0

    priority queue pq
    insert (0, source)

    while pq is not empty:
        (d, u) = extract minimum

        for each edge (u, v, w):
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                insert (dist[v], v) into pq
```

## Time Complexity

With adjacency list + heap:

`O((V + E) log V)`

## Why?

- heap operations cost about `log V`
- vertices and edge relaxations cause repeated heap work

With a simple array implementation:

`O(V^2)`

## Space Complexity

`O(V + E)`

## Applications

- GPS navigation
- network routing
- game pathfinding
