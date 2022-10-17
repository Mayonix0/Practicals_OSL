#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;

void insert(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));

    link->data = data;
    link->next = head;
    head = link;
}

void delete(int pos)
{
    struct node *ptr = head;
    if(head == NULL){
        printf("List is empty.\n");
    }
    else if(pos == 0){
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
    else{
        struct node *prev;
        for(int i = 0; i < pos; i++){
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        free(ptr);
    }   
}

void display()
{
    struct node *temp = head;
    
    while(temp!=NULL){
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
}

void main()
{
    int n,i,ele,pos;
    printf("Enter the number of elements in the list:");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter the element %d:",i);
        scanf("%d", &ele);
        insert(ele);
    }

    int ch=0;
    while(ch != 4)
    {
        printf("\nEnter 1 to insert, 2 to delete, 3 to display, 4 to exit program\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                printf("\nEnter the element: ");
                scanf("%d", &ele);
                insert(ele);
                break;
            }

            case 2:
            {
                printf("\nEnter the position in the list to delete: ");
                scanf("%d",&pos);
                delete(pos);
                break;
            }

            case 3:
            {
                printf("The current list is: \n");
                display();
                break;
            }

            case 4:
            {
                exit(0);
            }
        }
    }
}