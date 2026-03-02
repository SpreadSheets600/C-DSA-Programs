# Visual Comparison Of Linked Lists

This file uses Mermaid diagrams to compare linked list structures and operations.

## Singly Linked List

```mermaid
flowchart LR
    A[Head] --> B[10]
    B --> C[20]
    C --> D[30]
    D --> E[NULL]
```

Each node only knows the next node.

## Doubly Linked List

```mermaid
flowchart LR
    A[NULL] <--> B[10]
    B <--> C[20]
    C <--> D[30]
    D <--> E[NULL]
```

Each node knows both previous and next.

## Circular Linked List

```mermaid
flowchart LR
    A[10] --> B[20]
    B --> C[30]
    C --> A
```

The last node points back to the first node.

## Insert At Front In Singly Linked List

```mermaid
flowchart LR
    A[New 5] --> B[10]
    B --> C[20]
    C --> D[30]
```

Only a few pointer changes are needed, so it is `O(1)`.

## Delete Front In Singly Linked List

```mermaid
flowchart LR
    A[Head] --> B[10]
    B --> C[20]
    C --> D[30]

    E[After Delete] --> F[20]
    F --> G[30]
```

## Linked Stack

```mermaid
flowchart LR
    A[Top] --> B[30]
    B --> C[20]
    C --> D[10]
    D --> E[NULL]
```

Push and pop happen at the top, so both are `O(1)`.

## Linked Queue

```mermaid
flowchart LR
    A[Front] --> B[10]
    B --> C[20]
    C --> D[30]
    D --> E[NULL]
    F[Rear] --> D
```

Enqueue at rear and dequeue at front are both `O(1)` when front and rear are stored.

## One-Page Comparison

```mermaid
flowchart TD
    A[Linked Lists] --> B[Singly]
    A --> C[Doubly]
    A --> D[Circular]

    B --> B1[One next pointer]
    B --> B2[Simple]
    B --> B3[No backward move]

    C --> C1[Prev and next pointers]
    C --> C2[Move both directions]
    C --> C3[More memory]

    D --> D1[Last links to first]
    D --> D2[Good for cycles]
    D --> D3[Useful with tail pointer]
```
