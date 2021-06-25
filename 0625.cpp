#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node_t;

node_t* create_node(int val){
	node_t* node=(node_t*)malloc(sizeof(node_t));
	
	node->val=val;
	node->next=NULL;
	
}

void add_last_node(node_t* head, int val){
	while(head->next){
		head=head->next;
	} 
	
	head->next=create_node(val);	
}

void delete_first_node(node_t** head){
	node_t* tmp= *head;
	(*head)=tmp->next;
	
	free(tmp); 
}

void delete_current_node(node_t** head,int val){
	node_t* tmp= *head;
	node_t* prev;
	
	for(int i=0;i<val-1;i++){
		prev=tmp;
		tmp=tmp->next;
	}
	
	prev->next=tmp->next;
	free(tmp);
}


void print_linked_list(node_t* head){
	while(head){
		printf("%d, ",head->val);
		head=head->next;
	} 
	
	printf("\n");
}

int main(int argc, char *argv[]){
	
	node_t* head=create_node(10);
	
	add_last_node(head,1);
	add_last_node(head,2);
	add_last_node(head,3);
	add_last_node(head,4);
	add_last_node(head,5);
	add_last_node(head,6);
	add_last_node(head,7);
	print_linked_list(head);
	
	delete_first_node(&head);
	print_linked_list(head);
	
	delete_current_node(&head,3);
	print_linked_list(head);
	
	delete_current_node(&head,1);
	print_linked_list(head);		
	
	getchar();
	return 0;
} 
