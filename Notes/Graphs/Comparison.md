# Graph Algorithms Comparison

## Big Table

| Algorithm | Purpose | Main Data Structure | Time |
|-----------|---------|---------------------|------|
| BFS | Visit level by level | Queue | `O(V + E)` |
| DFS | Visit deep first | Stack / Recursion | `O(V + E)` |
| Dijkstra | Shortest path with non-negative weights | Priority Queue | `O((V + E) log V)` |
| Topological Sort | Order tasks in DAG | Queue / Indegree | `O(V + E)` |

## Easy Comparison

### BFS

- best for nearest nodes in unweighted graphs
- explores by layers

### DFS

- best for deep exploration
- useful for recursion-style graph problems

### Dijkstra

- best for weighted shortest path
- slower than BFS because of priority queue work

### Topological Sort

- not a path algorithm
- best for dependency ordering

## When To Use

Choose **BFS** if:

- graph is unweighted
- shortest number of edges matters

Choose **DFS** if:

- you need traversal, cycle checks, or components

Choose **Dijkstra** if:

- edges have non-negative weights
- shortest weighted path is needed

Choose **Topological Sort** if:

- tasks have dependencies
- graph is a DAG
