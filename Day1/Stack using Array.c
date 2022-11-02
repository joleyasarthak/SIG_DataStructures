#include <stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE] , top = -1;

void push();
void pop();
void display();

void main(){
	int ch;
	do{
		printf("\n-----------STACK-----------");
		printf("\n Press 1 for push operation:");
		printf("\n Press 2 for pop operation: ");
		printf("\n Press 3 for display operation: ");
		printf("\n Press 4 for exit");
		printf("\nEnter your choice: ");
		scanf("%d" , &ch);
		switch(ch){
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: break;
			default: printf("\nEnter Valid Choice.\n"); break;
		}
	}
	while(ch != 4);
}

void push(){
	int n; 
	if(top == MAXSIZE){
		printf("\nStack Overflow\n");
	}
	else{
		printf("Enter a Value: ");
		scanf("%d" , &n);
		top++;
		stack[top] = n;
	}
}
void pop(){
	int item;
	if(top == -1){
		printf("\nStack Underflow\n");
	}
	else{
		printf("\nDeleted Data: %d\n" , stack[top]);
		top--;
	}
}
void display(){
	int i;
	if(top == -1){
		printf("\nStack Underflow\n");
	}
	else{
		printf("\n");
		for(i = 0; i <= top; i++){
			printf("%d  " , stack[i]);
		}
		printf("\n");
	}
}
