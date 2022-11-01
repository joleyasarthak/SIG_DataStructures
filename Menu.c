#include <stdio.h>

void push();
void pop();
void display();

void main(){
	int ch;
	do{
		printf("------------STACK------------");
		printf("\n Press 1 for push: ");
		printf("\n Press 2 for pop: ");
		printf("\n Press 3 for display: ");
		printf("\n Press 4 for exit: ");
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
	printf("\nPush Operation\n");
}
void pop(){
	printf("\nPop Operation\n");
}
void display(){
	printf("\nDisplay Operation\n");
}
