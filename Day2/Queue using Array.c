#include <stdio.h>
#define MAXSIZE 10
int q[MAXSIZE] , rear = -1 , front = 0;

void insert();
void Delete();
void display();

void main(){
	int ch;
	do{
		printf("\n--------------QUEUE--------------");
		printf("\n Press 1 for insert operation: ");
		printf("\n Press 2 for delete operation: ");
		printf("\n Press 3 for display operation: ");
		printf("\n Press 4 for exit");
		printf("\nEnter your choice: ");
		scanf("%d" , &ch);
		switch(ch){
			case 1: insert(); break;
			case 2: Delete(); break;
			case 3: display(); break;
			case 4: break;
			default: printf("\nEnter Valid Choice.\n"); break;
		}
	}
	while(ch != 4);
}

void insert(){
	int n; 
	if(rear == MAXSIZE){
		printf("\nStack Overflow\n");
	}
	else{
		printf("Enter a Value: ");
		scanf("%d" , &n);
		rear++;
		q[rear] = n;
	}
}
void Delete(){
	int item;
	if(front > rear){
		printf("\nQueue Underflow\n");
	}
	else{
		printf("\nDeleted Data: %d\n" , q[front]);
		front++;
	}
}
void display(){
	int i;
	if(front > rear){
		printf("\nQueue Underflow\n");
	}
	else{
		printf("\n");
		for(i = front; i <= rear; i++){
			printf("%d  " , q[i]);
		}
		printf("\n");
	}
}
