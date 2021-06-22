#include<stdio.h>
#include<stdlib.h>



//node
typedef struct node{
	int val;
	struct node* next;
	
}node_t;


node_t* create_node(int val){
	node_t* node=(node_t*)malloc(sizeof(node_t));
	node->val=val;
	node->next=NULL;
	
	return node;
} 

void add_node(node_t* head,int val){
	node_t* node = create_node(val);
	
	while(head->next){
		head=head->next;
	}
	
	head->next=node;
} 

void delete_node(node_t* head){
	while(head->next->next){
		head=head->next;
	}
	
	head->next=NULL;
	//free(head->next->next);
} 

void delete_specific_node(node_t* head,int num){
	while(head->next->next){
		head=head->next;
	}
	
	
	free(head->next);
	head->next=NULL;
	
} 

void print_linked_list(node_t* head){
	while(head){
		printf("%d,",head->val);
		
		head=head->next;
	}
} 


int main(){
	node_t* head=create_node(1);
	add_node(head,2);
	add_node(head,3);
	add_node(head,4);
	add_node(head,5);
	add_node(head,6);
	add_node(head,7);

	delete_node(head);
	
	print_linked_list(head);


	//printf("\nHello World!\n");
	
	getchar();
	return 0;
} 
