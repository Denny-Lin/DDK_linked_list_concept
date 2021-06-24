# DDK_linked_list_sample
It is a sample linked list.

* we can code linked_list in a few minitues.
* The rules are bellow:
  1. Think the node structure.
  2. Think a function to add node, such as, node_t* head = create_node(1);.
  3. Think a function to print node, such as, print_linked_list(head);.
  4. Think how to use this function to extend to the other functions, ex, delete first, last, .
  5. Let us focus on the function of delete_first_node.
  6. We need to repalce the address of the head_node with the address of head'next_node.  
  7. Because "node_t* head" means "head is a pointer to node_t".
  8. This "head" save the first memory address of the structure "node_t". 
  9. We use "* " to get the data(value or address) from the "head".
  10. ...
  ```C
  void delete_first_node(node_t* head){
    //if(head==NULL) return;
    
    node_t* tmp=head;

    tmp=tmp->next;
    free(head);
    *head=*tmp;
  }
  
  delete_first_node(head);
  ```
* Smart people use the trick below:<br>  
![image](https://user-images.githubusercontent.com/67073582/123205707-f86a0480-d4ec-11eb-8286-1bb575cbf1ca.png) <br>

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


  

