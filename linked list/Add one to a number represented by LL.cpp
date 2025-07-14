https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  //function to reverse LL
  
  Node* reverseList(Node* head) {
        
        if(head==NULL || head->next ==NULL)
        return head;

        Node*prev=NULL;
        Node*curr=head;
        Node*forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    
    
    //function to add 1
    
    Node*addOneUtil(Node*head){
        Node*res=head;
        Node*curr=head;
        Node*last=NULL;
        
        int carry=1;
        int sum=0;
        
        while(curr!=NULL){
            // Calculate sum of carry and current node's data
           sum=curr->data+carry;
            carry=(sum>=10) ? 1 :0;
            // Update current node's data to sum modulo 10
            curr->data = sum % 10;
            
            last=curr;
            curr=curr->next;
        }
        
        //if carry is still left we need to add new node
        if(carry==1){
            last->next=new Node(carry);
        }
        return res;
    }
    
    
    
    
    Node* addOne(Node* head) {
       
    // Reverse the linked list
    head = reverseList(head);

    // Add one to the reversed list
    head = addOneUtil(head);

    // Reverse the list again to restore
  	// the original order
    return reverseList(head);
    }
};
