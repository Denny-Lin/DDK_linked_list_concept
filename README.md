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
  ```C
  void delete_first_node(node_t* head){
    if(head==NULL) return;
    
    node_t* tmp=head;

    tmp=tmp->next;
    free(head);
    *head=*tmp;
  }
  ```
  

