https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTabValue=PROBLEM


--------------------------------------------
  APPROACH 1->BRUTE FORCE
---------------------------------------------
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    
    //base case
    if(head==NULL ||  head->next==NULL)
    return head;

   int count0=0;
   int count1=0;
   int count2=0;

    Node*temp=head;
    while(temp!=NULL){
      //count 0's
        if(temp->data==0)
        count0++;
          //count 1's
        else if(temp->data==1)
        count1++;
          //count 2's
        else
        count2++;

        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
      //fill 0 till count0=0
        if(count0!=0){
        temp->data=0;
        count0--;
        }

     // fill 1 till count1=0
        else if(count1!=0){
        temp->data=1;
        count1--;
        }

      //fill 2 till count2=0
        else if (count2!=0){
        temp->data=2;
        count2--;
        }
           

        temp=temp->next;
    }
    return head;
}
T.C=O(N)
S.C=O(1)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------------------------------------
  APPROACH 2-> By Updating Links of Nodes 
  --------------------------------------------------------------------
  /*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    //base case
    if(head==NULL  || head->next==NULL)
    return head;


    //3 dummy nodes 
    Node*zeroD=new Node(0);
    Node*oneD=new Node(0);
    Node*twoD=new Node(0);

    //3 pointers
    Node*zero=zeroD;
    Node*one=oneD;
    Node*two=twoD;

    Node*curr=head;
    //string values in 3 lists
    while(curr!=NULL){
        if(curr->data==0){
            zero->next=curr;
            zero=zero->next;
        }
        else if(curr->data==1){
            one->next=curr;
            one=one->next;
        }

        else {
          two->next=curr;
          two=two->next;
        }

        curr=curr->next;
    }

 //merging all 3 lists
    if (oneD->next) 
        zero->next = oneD->next;
    else
        zero->next = twoD->next;
  
    one->next = twoD->next;
    two->next = nullptr;

    // Updated head
    head = zeroD->next;
    return head;

}
T.C=O(N)
S.C=O(1)
