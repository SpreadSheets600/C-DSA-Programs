# Visual Comparison Of Graph Algorithms

This file uses Mermaid diagrams to explain graph traversal and search visually.

## Sample Graph

```mermaid
flowchart TD
    A[A] --> B[B]
    A --> C[C]
    B --> D[D]
    B --> E[E]
    C --> F[F]
```

## BFS

```mermaid
flowchart LR
    A[Start A] --> B[Visit A]
    B --> C[Queue B C]
    C --> D[Visit B]
    D --> E[Visit C]
    E --> F[Visit D E F]
```

## DFS

```mermaid
flowchart LR
    A[Start A] --> B[Go to B]
    B --> C[Go to D]
    C --> D[Backtrack]
    D --> E[Go to E]
    E --> F[Backtrack to A]
    F --> G[Go to C then F]
```

## Dijkstra

```mermaid
flowchart TD
    A[Start at source] --> B[Set source distance = 0]
    B --> C[Pick closest unfinished node]
    C --> D[Relax its neighbors]
    D --> E[Update distances]
    E --> F{All done?}
    F -- No --> C
    F -- Yes --> G[Shortest distances ready]
```

## Topological Sort

```mermaid
flowchart TD
    A[Compute indegrees] --> B[Put indegree 0 nodes in queue]
    B --> C[Remove one node]
    C --> D[Add node to answer]
    D --> E[Reduce indegrees of neighbors]
    E --> F{Any new indegree 0 node?}
    F -- Yes --> C
    F -- No --> G[Stop when queue empty]
```

## One-Page Comparison

```mermaid
flowchart TD
    A[Graph Algorithms] --> B[BFS]
    A --> C[DFS]
    A --> D[Dijkstra]
    A --> E[Topological Sort]

    B --> B1[Queue]
    B --> B2[Level by level]

    C --> C1[Stack or recursion]
    C --> C2[Go deep first]

    D --> D1[Priority queue]
    D --> D2[Weighted shortest path]

    E --> E1[DAG only]
    E --> E2[Dependency order]
```
