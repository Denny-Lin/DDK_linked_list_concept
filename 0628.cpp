#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node_t;

int add_last_node(node_t** head, int val){
	node_t* node=(node_t*)malloc(sizeof(node_t));		
	node->val=val;	
	node->next=NULL;
	
	if(*head==NULL){ 
		*head=node;
	}
	else{		
		node_t* tmp=*head;
		
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}  
		
		tmp->next=node;			
	}
}

void delete_node(node_t** head, int val){
	node_t* tmp=NULL;
	
	if((*head)->val==val){
		tmp=*head;
		*head=(*head)->next;
		free(tmp);
	}
	else{
		node_t* current=*head;
		
		while(current->next != NULL){			
			if(current->next->val == val){
				tmp=current->next;
				current->next=current->next->next;
				free(tmp);
				break;
			}
			
			current=current->next;
		}
	}
	
}

void print_linked_list(node_t* head){
	while(head){
		printf("%d, ",head->val);
		head=head->next;
	}
	
	printf("\n");
} 

int main(){	
	node_t* head=NULL;
	
	add_last_node(&head, 10);
	add_last_node(&head, 5);
	add_last_node(&head, 8);
	add_last_node(&head, 9);
	add_last_node(&head, 3);
	add_last_node(&head, 7);
	add_last_node(&head, 1);	
	print_linked_list(head);
	
	delete_node(&head, 10);	
	print_linked_list(head);
		
	delete_node(&head, 5);	
	print_linked_list(head);
	
	delete_node(&head, 1);	
	print_linked_list(head);
	
	delete_node(&head, 10000);	
	print_linked_list(head);
	
	return 0;
} 
