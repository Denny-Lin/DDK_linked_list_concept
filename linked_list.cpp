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
	
	return node;
} 
 
void add_last_node(node_t* head, int val){
	while(head->next){
		head=head->next;
	}
	
	head->next=create_node(val); 
} 

void delete_first_node(node_t* head){
	node_t* tmp=tmp->next;
	
	if(head==NULL) return;

	free(tmp);
	*head=*tmp;
}
 
void delete_last_node(node_t* head){
	if(head==NULL) return;
	
	while(head->next->next){
		head=head->next;
	}
	
	free(head->next);
	head->next=NULL; 
} 

void delete_current_node(node_t* head,int val){	
	if(head==NULL) return;

	node_t* prev;
	node_t* prev_next_next;
	
	for(int i=0;i<val-1;i++){//until prev <- val
		head=head->next;
	}
	
	prev=head;
	prev_next_next=head->next->next;
	
	free(head->next);
	
	prev->next=prev_next_next;
	
} 

int get_linked_list_length(node_t* head){
	int len=0;
	
	while(head){
		
		len++;
		
		head=head->next;
	}
	
	printf("len=%d\n",len);
	
	return len;	
} 

 
void print_linked_list(node_t* head){
	while(head){
		
		printf("%d, ",head->val);
		
		head=head->next;
	}
	printf("\n");
} 
 
int main(){
 	
 	node_t* head=create_node(10);
 	 	
 	print_linked_list(head);
 	
 	add_last_node(head,5);
 	add_last_node(head,4);
 	add_last_node(head,3);
 	add_last_node(head,2);
 	add_last_node(head,1);
 	add_last_node(head,0);

 	print_linked_list(head);
 	
 	delete_last_node(head);
 	
 	print_linked_list(head);
 	
 	delete_first_node(head);
 	
 	print_linked_list(head);
 	
 	int middle=get_linked_list_length(head)/2;//len is even ->chose sencond  4/2=2, 0123, 012
 	
 	printf("middle=%d\n",middle);
 	
 	delete_current_node(head,middle);
 	
 	print_linked_list(head);
 	
 	middle=get_linked_list_length(head)/2;//again
 	
 	printf("middle=%d\n",middle);
 	
 	delete_current_node(head,middle);
 	
 	print_linked_list(head);
 	
	getchar();
	return 0;
} 
