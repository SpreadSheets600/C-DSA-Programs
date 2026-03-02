# Stacks And Queues Comparison

## Main Rule

| Structure | Rule |
|-----------|------|
| Stack | Last In, First Out |
| Queue | First In, First Out |
| Priority Queue | Highest priority first |

## Operation Comparison

| Structure | Insert | Delete | Peek |
|-----------|--------|--------|------|
| Stack | `push` at top | `pop` from top | top element |
| Simple Queue | `enqueue` at rear | `dequeue` from front | front element |
| Circular Queue | `enqueue` at rear with wrap-around | `dequeue` from front with wrap-around | front element |
| Priority Queue | insert by priority rule | remove highest-priority item | highest-priority item |

## Time Complexity Table

| Structure | Insert | Delete | Peek |
|-----------|--------|--------|------|
| Stack | `O(1)` | `O(1)` | `O(1)` |
| Simple Queue | `O(1)` | `O(1)` | `O(1)` |
| Circular Queue | `O(1)` | `O(1)` | `O(1)` |
| Priority Queue (unsorted array) | `O(1)` | `O(n)` | `O(n)` |
| Priority Queue (heap) | `O(log n)` | `O(log n)` | `O(1)` |

## When To Use What

Choose **Stack** if:

- last inserted item should come out first
- you are dealing with recursion, undo, brackets, or expressions

Choose **Simple Queue** if:

- first entered item should leave first
- array waste is not a problem

Choose **Circular Queue** if:

- you want efficient reuse of array space

Choose **Priority Queue** if:

- some items must be handled before others
