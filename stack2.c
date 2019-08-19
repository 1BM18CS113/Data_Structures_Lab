#include<stdio.h>

void push(int stack[], int);
int pop(int stack[]);
void display(int stack[]);

int top = -1;
int stack[3];

void main(){
	
	int choice, num;
	
	do{
		
		printf("*****************************************************\n");
		printf("Enter 1 to push, 2 to pop, 3 to display, 5 to exit\n");
		printf("*****************************************************\n");
		fflush(stdin);
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
			printf("Enter the number to push\n");
			fflush(stdin);
			scanf("%d", &num);
			push(stack, num);
			break;
			
			case 2:
			pop(stack);
			break;
			
			case 3:
			display(stack);
			break;
			
			default:
			printf("INVALID CHOICE\n");
		}
	}while(choice !=5);
}

void push(int s[], int num){
	
	if(top >=2){
		printf("Stack Overflow\n");
	}
	
	else{
		top++;
		s[top] = num;		
		printf("PUSH SUCCESFUL\n");
	}
}

int pop(int s[]){
	
	if(top == -1){
		printf("STACK UNDERFLOW\n");
	}
	
	else{
		printf("POP SUCCESSFUL : %d\n", s[top]);
		top--;
		return s[top+1];
	}
}

void display(int s[]){
	int i;
	if(top == -1){
		printf("STACK EMPTY! PUSH FIRST\n");
	}
	else{
		printf("Displaying the Full Stack\n");
		for(i=0; i<=top;i++){
			printf("%d", s[i]);
		}
	}
}