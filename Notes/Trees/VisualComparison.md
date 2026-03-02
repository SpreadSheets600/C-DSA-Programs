# Visual Comparison Of Trees

This file uses Mermaid diagrams to explain tree structures visually.

## Binary Tree

```mermaid
flowchart TD
    A[A] --> B[B]
    A --> C[C]
    B --> D[D]
    B --> E[E]
    C --> F[F]
```

## BST

```mermaid
flowchart TD
    A[50] --> B[30]
    A --> C[70]
    B --> D[20]
    B --> E[40]
    C --> F[60]
    C --> G[80]
```

Left side is smaller. Right side is larger.

## AVL Tree

```mermaid
flowchart TD
    A[30] --> B[20]
    A --> C[40]
    B --> D[10]
    C --> E[50]
```

The tree keeps itself balanced using rotations.

## Threaded Binary Tree

```mermaid
flowchart LR
    A[10] --> B[5]
    A --> C[15]
    B -.thread.-> A
```

The dotted thread shows a special pointer used for traversal.

## B-Tree

```mermaid
flowchart TD
    A["[20 | 40]"] --> B["[5 | 10]"]
    A --> C["[25 | 30]"]
    A --> D["[50 | 60]"]
```

One node can store multiple keys.

## B+ Tree

```mermaid
flowchart TD
    A["[20 | 40]"] --> B["Leaf [5 | 10]"]
    A --> C["Leaf [20 | 30]"]
    A --> D["Leaf [40 | 50 | 60]"]
    B -.linked leaves.-> C
    C -.linked leaves.-> D
```

Leaves are linked for fast ordered scanning.

## One-Page Comparison

```mermaid
flowchart TD
    A[Trees] --> B[Binary Tree]
    A --> C[Threaded Binary Tree]
    A --> D[BST]
    A --> E[AVL]
    A --> F[B-Tree]
    A --> G[B+ Tree]

    B --> B1[At most 2 children]
    C --> C1[Traversal helper threads]
    D --> D1[Left smaller, right larger]
    E --> E1[Balanced BST]
    F --> F1[Multi-key storage tree]
    G --> G1[Linked leaves]
```
