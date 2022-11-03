// Link List

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
        printf("\n-----------Link List-----------");
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
        start->add = NULL;
        temp = start;
        printf("\nTo add more elements in the list, press 'Y' ");
        scanf(" %c",&ch);
        while(ch=='Y' || ch=='y')
        {
            printf("\nEnter next value: ");
            scanf("%d",&n);
            New = (struct node *)malloc(sizeof(struct node));
            New->data = n;
            New->add = NULL;
            temp->add = New;
            temp = New;
            printf("\nTo add more elements in the list, press 'Y' ");
            scanf(" %c",&ch);	//space to prevent error
        }
    }
    else
    {
        printf("\nList already created\n");
    }
    
}
void insert()
{
    printf("Insert");
}
void Delete()
{
    printf("Delete");
}
void display()
{
    if(start == NULL)
    {
        printf("\nLink list not created, create a list first\n");
    }
    else
    {
        printf("\n");
        temp = start;
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->add;
        }
        printf("\n");
    }
}

