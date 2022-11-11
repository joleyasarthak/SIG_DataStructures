// Circular Link List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *add;
};
struct node *start=NULL,*temp,*New,*prev,*next;

void create();
void insert();
void Delete();
void display();

void main()
{
    int ch;
    do
    { 
        printf("\n-----------Circular Link List-----------");
        printf("\nPress 1 For Create Operation");
        printf("\nPress 2 For Insert Operation");
        printf("\nPress 3 For Delete Operation");
        printf("\nPress 4 For Display Operation");
        printf("\nPress 5 For exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:create();break;
            case 2:insert();break;
            case 3:Delete();break;
            case 4:display();break;
            case 5:break;
            default:printf("\nInvalid Choice\n");
        }
    }
    while(ch!=5);
}

void create()
{
    int n;
    char ch;
    if(start == NULL)
    {
        printf("\nEnter First value: ");
        scanf("%d",&n);
        start = (struct node *)malloc(sizeof(struct node));
        start->data = n;
        start->add = start;
        temp = start;
        printf("\nTo add more elements in the list, press 'Y' ");
        scanf(" %c",&ch);
        while(ch=='Y' || ch=='y')
        {
            printf("\nEnter next value: ");
            scanf("%d",&n);
            New = (struct node *)malloc(sizeof(struct node));
            New->data = n;
            New->add = start;
            temp->add = New;
            temp = New;
            printf("\nTo add more elements in the list, press 'Y' ");
            scanf(" %c",&ch);
        }
    }
    else
    {
        printf("\nCircular List already created\n");
    }
    
}
void insert()
{
    int n,position,count=0,i=1;
    if(start == NULL)
    {
        printf("\nCircular Link list not created, create a list first\n");
    }
    else
    {
        printf("\nEnter A Value: ");
        scanf("%d",&n);
        New = (struct node *)malloc(sizeof(struct node));
        New->data = n;
        New->add = start;
        printf("\nEnter a Position of new Node: ");
        scanf("%d",&position);
        
        if(position==1)
        {
            temp=start;
            while(temp->add!=start)
            {
                temp = temp->add;
            }
            temp->add = New;
            start = New;
        }
        else
        {
            temp = start;
            do
            {
                count++;
                temp = temp->add;
            }
            while(temp!=start);
            
            if(position>count+1)
            {
                printf("Invalid Position, it cannot be more than %d",count+1);
            }
            else if(position==count+1)
            {
                temp=start;                     // temp = 1111
                while(temp->add != start)
                {
                    temp = temp->add;
                }
                temp->add = New;
            }
            else
            {
                next = start;
                while(i<position)           // position = 3
                {                           // i = 3
                    prev = next;            // prev = 1011
                    next = next->add;       // next = 1234
                    i++;
                }
                prev->add = New;
                New->add = next;
            }
        }
    }
}
void Delete()
{
    int count=0,i=1,position;
    if(start == NULL)
    {
        printf("\nCircular Link list not created, create a list first\n");
    }
    else
    {
        printf("Enter a Position for Deletion: ");
        scanf("%d",&position);
        
        if(position == 1)
        {
            temp = start;
            while(temp->add!=start)
            {
                temp = temp->add;
            }
            temp->add = start->add;
            
            temp=start;
            start = start->add;
            printf("\nDeleted Data = %d\n",temp->data);
            free(temp);
        }
        else
        {
            temp=start;
            do
            {
                temp = temp->add;
                count++;
            }
            while(temp!=start);
            
            if(position > count)
            {
                printf("\nInvalid Position, it cannot be more than %d\n",count);
            }
            else if(position == count)
            {
                temp = start;
                while(temp->add != start)
                {
                    prev = temp;                    // prev = 1234
                    temp = temp->add;               // temp = 1111
                }
                printf("\nDeleted Data = %d\n",temp->data);
                free(temp);
                prev->add = start;        
            }
            else
            {
                next = start;
                while(i<position)
                {
                    prev = next;            // prev = 1011
                    next = next->add;       // next = 1111
                    i++;                    // i= 3
                }
                temp = next;                // temp = 1234;
                next = next->add;
                printf("\nDeleted Data = %d\n",temp->data);
                free(temp);
                prev->add = next;        
            }
        }
    }
}
void display()
{
    if(start == NULL)
    {
        printf("\nCircular Link list not created, create a list first\n");
    }
    else
    {
        printf("\n");
        temp = start;
        do
        {
            printf("%d  ",temp->data);
            temp=temp->add;
        }
        while(temp!=start);
        printf("\n");
    }
}
