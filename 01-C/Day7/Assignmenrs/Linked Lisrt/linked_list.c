#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

static node* createNode(void);
node *head = NULL;

static node* createNode(void){
	
	return (node*)malloc(sizeof(node));
}



void addNode(s32 value){
	node* new = createNode();
	new->data = value;
	new->next_node = NULL;
	
	if(head == NULL){
		head = new;
	}
	
	else{
		node *temp = head;
		
		while(temp->next_node != NULL){
			temp = (temp->next_node);
		}
		
		temp->next_node = new;
	}
	
	
}



void printLinkedList(void){
	
	if(head == NULL){
		printf("Linked list is empty....!!!");
	}
	
	else{
		u32 i=0;
		node *temp = head;
		while(temp != NULL){
			i++;
			printf("\nNode number -%d = %d", i, temp-> data);
			temp = (temp->next_node);
		}
		
	}
	
}




void deleteNode(s32 value){	
	if(head == NULL) return; //empty list
	
	
	while(head->data == value){ //keep deleting the top of the list
		/*Only one node on the list*/
		if (head->next_node == NULL) head = NULL;
		
		/*Multiple nodes on the list*/
		else head = head->next_node;				


		if (head == NULL) return;
	}
	
	node *prev = head;	
	node *current = prev->next_node;
	
	while(current->next_node != NULL){
		if(current->data == value){
			prev->next_node = current->next_node;
			free(current);
		}
		prev = prev->next_node;
		current = prev->next_node;
	}
	
}