#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node_t;

node_t* creat_node(int val){
	node_t* node=(node_t*)malloc(sizeof(node_t));
	node->val=val;
	node->next=NULL;
	
	return node;
}

void add_last_node(node_t* head,int val){
	while(head->next){
		head=head->next;
	}
	
	node_t* node=creat_node(val);
	head->next=node;
}

void delete_first_node(node* &head) {
    node *tobedeleted = head;
    head = head->next;   // head is the next element
    free(tobedeleted);  // delete the old head
}
//delete_first_node(head);

/*
void delete_first_node(node** head) {
    node *tobedeleted = *head;
    *head = (*head)->next;   // head is the next element
    free(tobedeleted);  // delete the old head
}
*/
//delete_first_node(&head);


void delete_current_node(node_t* head,int val){

	if(head==NULL) return ;

	if(val-2<0){
		delete_first_node(head);
		return ;
	}

	for(int i=0;i<val-2;i++){//until prev node
		head=head->next;
		
		if(head->next==NULL){//over length
			return;
		}
	}
		
	node_t* tmp=head->next;//the node you want to delete
		
	head->next=head->next->next;//next node
	
	free(tmp);
}

void delete_last_node(node_t* head){
	while(head->next->next){
		head=head->next;
	}
	
	free(head->next);
	head->next=NULL;
}

void print_linked_list(node_t* head){
	while(head){
		printf("%d, ",head->val);
		head=head->next;
	}
	
	printf("\n");
}

int main(){
 	node_t* head=creat_node(10);
 	
 	add_last_node(head,1);
 	add_last_node(head,2);
 	add_last_node(head,3);
 	add_last_node(head,4);
 	add_last_node(head,5);
 	add_last_node(head,6);
 	add_last_node(head,7);
 	
 	delete_last_node(head);
 	delete_last_node(head);
 	
 	delete_first_node(head);
 	delete_first_node(head);
 	
 	print_linked_list(head);
 	
	delete_current_node(head,2); 
 	
 	print_linked_list(head); 
	  
 	delete_current_node(head,6);//test over length 
 	
 	print_linked_list(head);
 	

	getchar();
	return 0;
} 
