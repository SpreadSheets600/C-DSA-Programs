# Stack Applications: Expression Conversion And Evaluation

Stacks are very useful in expressions like:

```text
A + B * C
```

They help with:

- expression conversion
- expression evaluation
- matching brackets
- recursion and function calls

## Types Of Expressions

### Infix

Operator is between operands.

```text
A + B
```

### Prefix

Operator comes before operands.

```text
+ A B
```

### Postfix

Operator comes after operands.

```text
A B +
```

## Why Prefix And Postfix Are Helpful

They avoid confusion about brackets and operator priority.

For example:

```text
A + B * C
```

In postfix:

```text
A B C * +
```

Now the order is clear.

## Infix To Postfix

### Main Idea

1. Read expression left to right
2. Send operands directly to output
3. Put operators on stack
4. Pop higher-priority operators before pushing lower-priority ones
5. Pop all remaining operators at the end

### Algorithm

```text
infixToPostfix(expr):
    create empty stack
    for each symbol in expr:
        if symbol is operand:
            add to output
        else if symbol is '(':
            push to stack
        else if symbol is ')':
            while top of stack is not '(':
                pop from stack to output
            pop '('
        else if symbol is operator:
            while stack not empty and precedence(top) >= precedence(symbol):
                pop from stack to output
            push symbol

    while stack not empty:
        pop from stack to output
```

### Complexity

Time: `O(n)`

Why:

- each symbol is pushed or popped at most once

Space: `O(n)`

## Infix To Prefix

One common method:

1. reverse infix expression
2. swap `(` and `)`
3. convert to postfix
4. reverse result

### Complexity

Time: `O(n)`

Space: `O(n)`

## Postfix Evaluation

### Main Idea

1. Read from left to right
2. If operand, push it
3. If operator, pop two operands
4. apply operation
5. push result back

### Algorithm

```text
evaluatePostfix(expr):
    create empty stack
    for each symbol in expr:
        if symbol is operand:
            push symbol
        else:
            b = pop()
            a = pop()
            result = a operator b
            push result
    return pop()
```

### Example

```text
2 3 4 * +
```

Process:

```text
push 2
push 3
push 4
* => 3 * 4 = 12
push 12
+ => 2 + 12 = 14
```

Answer: `14`

### Complexity

Time: `O(n)`

Space: `O(n)`

## Prefix Evaluation

### Main Idea

Read from right to left.

If operand, push it.

If operator, pop two values, apply operator, push result.

### Algorithm

```text
evaluatePrefix(expr):
    create empty stack
    for each symbol from right to left:
        if symbol is operand:
            push symbol
        else:
            a = pop()
            b = pop()
            result = symbol applied to a and b
            push result
    return pop()
```

### Complexity

Time: `O(n)`

Space: `O(n)`

## Other Applications Of Stacks

- function call management
- undo and redo
- browser backtracking
- depth-first search
- balancing parentheses

## Quick Summary

| Task | Time | Space |
|------|------|-------|
| Infix to Postfix | `O(n)` | `O(n)` |
| Infix to Prefix | `O(n)` | `O(n)` |
| Postfix Evaluation | `O(n)` | `O(n)` |
| Prefix Evaluation | `O(n)` | `O(n)` |
