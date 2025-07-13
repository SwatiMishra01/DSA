//  Function to insert node at tail in the linked list
Node*insertAtTail(Node*head, int val){
  Node*newNode=new Node(val);
  if(head==NULL)
    return newNode;
  Node*temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=newNode;
  return head;
}
