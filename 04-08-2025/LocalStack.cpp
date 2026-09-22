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
