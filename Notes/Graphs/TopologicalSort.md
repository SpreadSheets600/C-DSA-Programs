# Topological Sort

## Idea Like You Are 10

Sometimes one job must happen before another.

Example:

- wear socks before shoes
- finish homework before playing games

Topological sort gives an order that respects these rules.

It only works on a **Directed Acyclic Graph (DAG)**.

## Example

```text
Study -> Exam
Practice -> Exam
Exam -> Result
```

One valid order:

```text
Study, Practice, Exam, Result
```

## Kahn's Algorithm

```text
topologicalSort(graph):
    compute indegree of every node
    put all nodes with indegree 0 into queue

    while queue is not empty:
        u = dequeue()
        print u

        for each neighbor v of u:
            indegree[v] = indegree[v] - 1
            if indegree[v] == 0:
                enqueue(v)
```

## Time Complexity

`O(V + E)`

## Why?

- compute indegrees using all edges
- visit every vertex once
- process every edge once

## Applications

- job scheduling
- course planning
- dependency resolution
