# Visual Comparison Of Stacks And Queues

This file uses Mermaid diagrams to explain stacks and queues visually.

## Stack

```mermaid
flowchart TD
    A[Top: 30] --> B[20]
    B --> C[10]
```

`push` and `pop` happen at the top.

## Queue

```mermaid
flowchart LR
    A[Front] --> B[10]
    B --> C[20]
    C --> D[30]
    E[Rear] --> D
```

Insertion happens at rear. Deletion happens at front.

## Circular Queue

```mermaid
flowchart LR
    A[0] --> B[1]
    B --> C[2]
    C --> D[3]
    D --> E[4]
    E --> A
```

Rear wraps around to reuse free space.

## Priority Queue

```mermaid
flowchart TD
    A[Items] --> B[A priority 3]
    A --> C[B priority 1]
    A --> D[C priority 2]
    C --> E[Leaves first]
```

The highest-priority item is served first.

## Infix To Postfix Using Stack

```mermaid
flowchart LR
    A[Read A] --> B[Output A]
    B --> C[Read +]
    C --> D[Push +]
    D --> E[Read B]
    E --> F[Output B]
    F --> G[Read *]
    G --> H[Push *]
    H --> I[Read C]
    I --> J[Output C]
    J --> K[Pop *]
    K --> L[Pop +]
    L --> M[Postfix: A B C * +]
```

## Postfix Evaluation

```mermaid
flowchart LR
    A[2] --> B[Push 2]
    B --> C[3]
    C --> D[Push 3]
    D --> E[4]
    E --> F[Push 4]
    F --> G[*]
    G --> H[Pop 4 and 3, multiply, push 12]
    H --> I[+]
    I --> J[Pop 12 and 2, add, push 14]
```

## One-Page Comparison

```mermaid
flowchart TD
    A[Linear Structures] --> B[Stack]
    A --> C[Queue]
    A --> D[Circular Queue]
    A --> E[Priority Queue]

    B --> B1[LIFO]
    B --> B2[Push and Pop at top]

    C --> C1[FIFO]
    C --> C2[Front and Rear]

    D --> D1[FIFO]
    D --> D2[Wrap-around array]

    E --> E1[Priority based]
    E --> E2[Not just arrival order]
```
