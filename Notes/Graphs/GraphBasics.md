# Graph Basics

## Idea Like You Are 10

Imagine a map of cities.

- each city is a node
- each road is an edge

That map is a graph.

## Basic Terms

### Vertex

A point in the graph.

### Edge

A connection between two vertices.

### Directed Graph

Edges have direction.

```text
A -> B
```

### Undirected Graph

Edges work both ways.

```text
A -- B
```

### Weighted Graph

Edges have cost or distance.

```text
A --5-- B
```

### Path

A sequence of connected vertices.

### Cycle

A path that comes back to the start.

### Degree

How many edges touch a vertex.

## Graph Representations

### Adjacency Matrix

Use a table.

Space: `O(V^2)`

Good when the graph is dense.

### Adjacency List

Store neighbors of each vertex.

Space: `O(V + E)`

Good when the graph is sparse.

## Why Complexity Often Uses `V` And `E`

- `V` = number of vertices
- `E` = number of edges

Graph algorithms usually depend on both.
