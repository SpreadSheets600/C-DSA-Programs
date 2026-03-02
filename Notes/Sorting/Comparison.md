# Sorting Comparison

## Big Table

| Algorithm | Best Time | Average Time | Worst Time | Extra Space | Main Idea |
|-----------|-----------|--------------|------------|-------------|-----------|
| Bubble Sort | `O(n)` | `O(n^2)` | `O(n^2)` | `O(1)` | Swap neighbors again and again |
| Insertion Sort | `O(n)` | `O(n^2)` | `O(n^2)` | `O(1)` | Insert each item into the sorted part |
| Selection Sort | `O(n^2)` | `O(n^2)` | `O(n^2)` | `O(1)` | Repeatedly choose the smallest |
| Quick Sort | `O(n log n)` | `O(n log n)` | `O(n^2)` | `O(log n)` average stack | Split around a pivot |
| Merge Sort | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(n)` | Split, sort halves, merge |
| Heap Sort | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(1)` | Use a heap to remove largest repeatedly |

## Which One Is Easiest?

Usually:

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
6. Heap Sort

Heap Sort is often harder to picture because of the heap tree idea.

## Which One Is Fastest In Real Life?

There is no single winner for every situation, but usually:

- **Quick Sort** is very fast on average
- **Merge Sort** is very dependable
- **Heap Sort** is good when you want `O(n log n)` without extra array memory
- **Insertion Sort** is great for very small or nearly sorted lists

## Child-Friendly Comparison

### Bubble Sort

- Very easy
- Very slow
- Good for learning

### Insertion Sort

- Feels like sorting cards in your hand
- Good for small or almost sorted lists

### Selection Sort

- Simple idea
- Always does lots of checking

### Quick Sort

- Usually very fast
- Can become bad if pivot choice is poor

### Merge Sort

- Always nicely fast
- Needs extra memory

### Heap Sort

- Always nicely fast
- Harder to understand than Merge Sort or Quick Sort

## Why `O(n^2)` Is Slower Than `O(n log n)`

Imagine `n = 1000`.

- `n^2 = 1000000`
- `n log n` is much smaller

So when the list gets big, `O(n log n)` algorithms usually win by a lot.

## Simple Race Analogy

```text
Small race:
Insertion Sort can do okay

Big race:
Bubble / Selection / Insertion fall behind
Quick / Merge / Heap move ahead
```

## Quick Picking Guide

Choose **Bubble Sort** if:

- you are learning basics

Choose **Insertion Sort** if:

- the array is small
- the array is nearly sorted

Choose **Selection Sort** if:

- you want a simple method with few swaps

Choose **Quick Sort** if:

- you want strong average performance

Choose **Merge Sort** if:

- you want guaranteed fast time
- stability matters

Choose **Heap Sort** if:

- you want guaranteed fast time
- and low extra memory
