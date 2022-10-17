#include <stdio.h>
#include <stdlib.h>
#define size 5
int queue[size] = {'a', 'a', 'a', 'a', 'a'};
int front = -1;
int rear = -1;
int i;

void insert()
{
    int temp;
    printf("Enter the value to be inserted in the queue: ");
    scanf("%d", &temp);
    if((front == 0 && rear == 4) || (front == rear+1))
        printf("\nOverflow\n");
    else
    {
        if(rear == -1)
        {
            front = 0;
            rear = 0;
        }

        else if(rear == 4)
            rear = 0;

        else
            rear++;

        queue[rear] = temp;
        printf("\nItem inserted\n");
    }
}

void delete()
{
    int t;

    if(front == -1)
        printf("\nUnderflow\n");
    
    else
    {
        t = queue[front];
        queue[front] = 'a';

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }

        else if(front == 4)
        {
            front = 0;
        }

        else
            front++;

        printf("\nItem deleted\n", t);
    }
    
}

void show()
{
    printf("\nThe status is:\n");
    for (i = 0; i < 5; i++)
    {
        if(queue[i] == 'a')
            printf("_ ");
        else
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    label:;
    int choice;
    printf("Enter 1 to insert, 2 to delete, 3 to show status, 4 to exit program\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: 
        {
            insert();
            break;
        }

        case 2: 
        {
            delete();
            break;
        }

        case 3: 
        {
            show();
            break;
        }

        case 4: 
        {
            exit(0);
        }
    }

    goto label;

    return 0;
}