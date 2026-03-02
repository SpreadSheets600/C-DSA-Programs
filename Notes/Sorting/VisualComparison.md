# Visual Comparison Of Sorting Algorithms

This file uses **Mermaid diagrams** to show how different sorting algorithms work.

If your Markdown viewer supports Mermaid, these diagrams will render as flowcharts.

## Bubble Sort

Idea: compare neighbors and swap if they are in the wrong order.

```mermaid
flowchart LR
    A[5 3 8 1] --> B[Compare 5 and 3]
    B --> C[Swap]
    C --> D[3 5 8 1]
    D --> E[Compare 5 and 8]
    E --> F[No Swap]
    F --> G[Compare 8 and 1]
    G --> H[Swap]
    H --> I[3 5 1 8]
```

## Insertion Sort

Idea: take one new item and insert it into the correct place in the sorted part.

```mermaid
flowchart LR
    A[Sorted: 5 | Unsorted: 3 8 1] --> B[Take 3]
    B --> C[Insert before 5]
    C --> D[Sorted: 3 5 | Unsorted: 8 1]
    D --> E[Take 8]
    E --> F[Insert after 5]
    F --> G[Sorted: 3 5 8 | Unsorted: 1]
```

## Selection Sort

Idea: find the smallest item and place it in front.

```mermaid
flowchart LR
    A[5 3 8 1] --> B[Find smallest]
    B --> C[Smallest is 1]
    C --> D[Swap with first element]
    D --> E[1 3 8 5]
    E --> F[Repeat on remaining part]
```

## Quick Sort

Idea: choose a pivot, split into smaller and bigger parts, then sort both sides.

```mermaid
flowchart TD
    A[5 3 8 1 4] --> B[Choose pivot 5]
    B --> C[Smaller: 3 1 4]
    B --> D[Pivot: 5]
    B --> E[Bigger: 8]
    C --> F[Choose pivot 3]
    F --> G[1]
    F --> H[3]
    F --> I[4]
    G --> J[1 3 4]
    H --> J
    I --> J
    J --> K[1 3 4 5 8]
    D --> K
    E --> K
```

## Merge Sort

Idea: split into halves, sort each half, then merge them back together.

```mermaid
flowchart TD
    A[5 3 8 1] --> B[5 3]
    A --> C[8 1]
    B --> D[5]
    B --> E[3]
    C --> F[8]
    C --> G[1]
    D --> H[3 5]
    E --> H
    F --> I[1 8]
    G --> I
    H --> J[1 3 5 8]
    I --> J
```

## Heap Sort

Idea: build a max-heap, remove the largest item, and repeat.

```mermaid
flowchart TD
    A[4 10 3 5 1] --> B[Build Max Heap]
    B --> C[Top is 10]
    C --> D[Swap 10 with last]
    D --> E[Fix heap]
    E --> F[Top is next largest]
    F --> G[Repeat]
```

## One-Page Comparison

```mermaid
flowchart TD
    A[Sorting Algorithms] --> B[Bubble Sort]
    A --> C[Insertion Sort]
    A --> D[Selection Sort]
    A --> E[Quick Sort]
    A --> F[Merge Sort]
    A --> G[Heap Sort]

    B --> B1[Swap neighbors]
    B --> B2[Usually O(n^2)]

    C --> C1[Insert into sorted part]
    C --> C2[Good for small or nearly sorted data]

    D --> D1[Pick smallest each round]
    D --> D2[Always O(n^2)]

    E --> E1[Split around pivot]
    E --> E2[Average O(n log n)]
    E --> E3[Worst O(n^2)]

    F --> F1[Split and merge]
    F --> F2[Always O(n log n)]
    F --> F3[Needs extra memory]

    G --> G1[Use max-heap]
    G --> G2[Always O(n log n)]
    G --> G3[In-place]
```

## Speed Ladder

```mermaid
flowchart LR
    A[Usually Slower] --> B[Bubble]
    B --> C[Selection]
    C --> D[Insertion]
    D --> E[Heap]
    E --> F[Merge]
    F --> G[Quick]
    G --> H[Usually Faster]
```

Note: this is a simple learning picture, not a perfect rule for every case.
