#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;
int isfull()
{
    if (rear == SIZE - 1)
        return 1;
    else
        return 0;
}
void enqueue(int data)
{
    int r;
    r = isfull();
    if (r != 1)
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = data;
        }
        else
        {
            queue[++rear] = data;
        }
    }
    else
    {
        printf("Queue Is Full");
    }
}
int isempty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int dequeue()
{
    int a;
    a = isempty();
    if (a == 1)
    {
        return -1;
    }
    else
    {
        int data = queue[front];
        front++;
        return data;
    }
}
void display()
{
    int i;
    if (isempty())
    {
        printf("The Queue Is Empty\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
int main()
{
    do
    {
        int ch, data, p;
        printf("\n---Queue Menu--\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Your Data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            p = dequeue();
            if (p != -1)
            {
                printf("%d Is Deleted From The Queue", p);
            }
            else
            {
                printf("Queue Is Empty");
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid");
        }
    } while (1);
    return 0;
}
