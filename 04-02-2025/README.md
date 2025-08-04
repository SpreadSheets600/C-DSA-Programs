# Programming Exercises - August 08, 2025

## Exercise 1 : Global Stack Operations

**Qestion:** Write a program to perform operations of stack.

**Sollution:** [View Code](GlobalStack.cpp)

```cpp
#include <stdlib.h>
#include <stdio.h>
#define MAX 3

int stack[MAX];
int top = -1;

int isfull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push()
{
    int x, m;
    m = isfull();

    if (m == 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter The Element To Push : ");
        scanf("%d", &x);

        top++;
        stack[top] = x;

        printf("%d Pushed To Stack\n", x);
    }
}

void pop()
{
    int item, m;

    m = isempty();

    if (m == 1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int item = stack[top];
        top--;

        printf("Popped Element %d\n", item);
    }
}

void display()
{
    int i;
    printf("Displaying Stack : \n");

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choise, m;

    while (1)
    {
        printf("\n*** Stack Menu ***");
        printf("\n\n1. Check If Empty\n2. Check If Full\n3. Push\n4. Pop\n5. Display\n6. Exit");
        printf("\n\nEnter Your Choise (1 - 6) : ");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            m = isempty();

            if (m == 1)
            {
                printf("\nStack Is Empty\n");
            }
            break;

        case 2:
            m = isfull();

            if (m == 1)
            {
                printf("\nStack Is Full\n");
            }
            else
            {
                printf("\nStack Is Not Full\n");
            }
            break;

        case 3:
            push();
            break;

        case 4:
            pop();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("\nWrong Choice");
        }
    }
    return 0;
}
```

### OUTPUT 1

```bash
*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 3
Enter The Element To Push : 4
4 Pushed To Stack

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 3
Enter The Element To Push : 5
5 Pushed To Stack

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 3
Enter The Element To Push : 6
6 Pushed To Stack

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 5
Displaying Stack : 
6 5 4 

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 4
Popped Element 6

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 6

```

## Exercise 2 : Local Stack Operations

**Qestion:** Write a program to perform operations of stack.

**Sollution:** [View Code](LocalStack.cpp)

```cpp
# include <stdlib.h>  
# include <stdio.h>  

int isfull(int top, int max)
{
    if (top == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int isempty(int top)
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int *top, int max, int stack[]) {
    int x;
    
    if (isfull(*top, max)) {
        printf("Stack Overflow\n");
        
    } else {
        printf("Enter The Element To Push : ");
        scanf("%d", &x);
        
        (*top)++; 
        stack[*top] = x;
        
        printf("%d Pushed To Stack\n", x);
    }
}

void pop(int *top, int stack[]) {
    int item;
    
    if (isempty(*top)) {
        printf("Stack Underflow\n");
        
    } else {
        item = stack[*top];
        (*top)--; 
        
        printf("Popped Element %d\n", item);
    }
}

void display(int top, int stack[])
{
    int i;
    printf("Displaying Stack : \n");

    if (isempty(top))
    {
        printf("Stack Is Empty\n");
        return;
    }

    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main()
{
    int choise, m, max;

    printf("Enter The Max Size Of Stack : ");
    scanf("%d", &max);

    int stack[max];
    int top = -1;

    while (1)
    {
        printf("\n*** Stack Menu ***");
        printf("\n\n1. Check If Empty\n2. Check If Full\n3. Push\n4. Pop\n5. Display\n6. Exit");
        printf("\n\nEnter Your Choise (1 - 6) : ");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            m = isempty(top);

            if (m == 1)
            {
                printf("\nStack Is Empty\n");
            }
            else
            {
                printf("\nStack Is Not Empty\n");
            }
            break;

        case 2:
            m = isfull(top, max);

            if (m == 1)
            {
                printf("\nStack Is Full\n");
            }
            else
            {
                printf("\nStack Is Not Full\n");
            }
            break;

        case 3:
            push(&top, max, stack);
            break;

        case 4:
            pop(&top, stack);
            break;

        case 5:
            display(top, stack);
            break;

        case 6:
            exit(0);

        default:
            printf("\nWrong Choice\n");
        }
    }
    return 0;
}
```

### OUTPUT 2

```bash
Enter The Max Size Of Stack : 3

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 3
Enter The Element To Push : 4
4 Pushed To Stack

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 3
Enter The Element To Push : 5
5 Pushed To Stack

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 3
Enter The Element To Push : 6
6 Pushed To Stack

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 5
Displaying Stack : 
6 5 4 

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 4
Popped Element 6

*** Stack Menu ***

1. Check If Empty
2. Check If Full
3. Push
4. Pop
5. Display
6. Exit

Enter Your Choise (1 - 6) : 6

```
