#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

typedef struct node* NODE; 

NODE getnode();
NODE insert_beg(NODE first, int ele);
NODE insert_end(NODE first, int ele);
NODE display(NODE first);


void main(){
	
	int choice, ele;
	NODE first = NULL;
	
	
	do{
		printf("1. Insert at the front. 2. Insert at end. 3. Display. 5. Exit\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
			printf("ENTER THE ELEMENT TO INSERT AT THE BEGINNING\n");
			scanf("%d", &ele);
			
			first = insert_beg(first, ele);
			break;
			
			case 2:
			printf("ENTER THE ELEMENT TO INSERT AT THE END\n");
			scanf("%d", &ele);
			
			first = insert_end(first, ele);
			break;
			
			case 3:
			first = display(first);
			break;
		}
	}while(choice !=5);
}

NODE getnode(){
	NODE cr_node = (NODE)malloc(sizeof(struct node));
	cr_node->next = NULL;
	return cr_node;
}

NODE insert_beg(NODE first, int ele){
	
	NODE temp = getnode();
	temp-> val =ele;
	
	if(first == NULL){
		first = temp;
	}
	else{
		temp->next = first;
		first = temp;
	}
	
	return first;
}


NODE insert_end(NODE first, int ele){

	NODE temp = getnode();
	temp->val = ele;
	NODE curr = first;

	
	if(first == NULL){
		first = temp;
	}
	else{
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next = temp;
	}
	return first;
}

NODE display(NODE first){
	NODE temp = first;
	
	if(first == NULL){
		printf("LIST EMPTY\n");
	}
	
	while(temp->next != NULL){
		printf("%d\n", temp->val);
		temp = temp->next;
	}
	printf("%d\n", temp->val);
	
	return first;
}
