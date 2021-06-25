# DDK_linked_list_concept
I talk about what the tricks of double pointer are in linked list.

* we can code linked_list in a few minitues.
* The rules are bellow:
  1. Think the structure of the node.
      ```C
      typedef struct node{
        int val;
        struct node* next;
      }node_t;
      ```
  2. Think a function to add node, such as, node_t* head = create_node(1); .
  3. Think a function to print node, such as, print_linked_list(head); .
  4. Think how to use this function to extend to the other functions, ex, delete_first, \_last, ... .
  5. Let us focus on the function of delete_first_node().
  6. We need to repalce the address of the head_node with the address of next node of head.  
  7. Because "node_t* head" means "head is a pointer to node_t".
  8. This "head" saves the first memory address of the structure "node_t". 
  9. We use "* " to get the data(value or address) from the "head".
  10. so the sample code could be below: 
  <br></br>
  ```C
  void delete_first_node(node_t* head){
    //if(head==NULL) return;
    
    *head=*(head->next);
    //We can "not" free the address of the "original head" from main(). 
    //Because we do not know the address that main() puts the "head" on.
    //Main() should free() itself.
  }
  
  delete_first_node(head);
  ```
* Smart people use the trick below:<br>  
![image](https://user-images.githubusercontent.com/67073582/123205707-f86a0480-d4ec-11eb-8286-1bb575cbf1ca.png) <br>

* We can see that delete_first_node() gets the value 2008, but what we want to do is to change the value which is on the address #4020.
* delete_first_node() gets the value but putting on the local address #???? which is not #4020. 

* So... we are smart, we coulud change the code to:
 ```C
 void delete_first_node(node_t** head) {
    node* tmp = *head;
    *head = (*head)->next; 
    free(tmp); 
}

delete_first_node(&head);
```
or
 ```C
 void delete_first_node(node_t* &head) {
    node* tmp = head;
    head = head->next;   
    free(tmp); 
}

delete_first_node(head);
```
* This trick means we get the address of head, not the value it stores.
* The other concept is all of them are "called by value"; if a teacher say "called by address", you can just leave the classroom.<br>

* Next, if we want to delete the second, third or fourth node, we can do below:
 ```C
void delete_current_node(node_t** head,int val){
	node_t* tmp= *head;
  //We use tmp to traverse.
	node_t* prev;
	
	for(int i=0;i<val-1;i++){
		prev=tmp;
		tmp=tmp->next;
	}
	
	prev->next=tmp->next;
	free(tmp);
}

delete_current_node(&head,3);
```

  

