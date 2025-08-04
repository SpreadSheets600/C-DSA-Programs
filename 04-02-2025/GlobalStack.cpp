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
