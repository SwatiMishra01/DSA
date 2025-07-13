https://leetcode.com/problems/copy-list-with-random-pointer/description/
LEETCODE-138

----------------------------------
  APPROACH 1-> UNORDERD MAP
------------------------------------

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*temp=head;
        unordered_map<Node*,Node*>mpp;
        //step-1-> clone the values 
        while(temp!=NULL){
            Node*newNode=new Node(temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }

        temp=head;
        while(temp!=NULL){
            Node*copyNode=mpp[temp];
        // copy next pointers
            copyNode->next=mpp[temp->next];
            //copy random pointers
            copyNode->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};
T.C=O(2N)~O(N)
S.C=O(N)


-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------------------------
   APPROACH 2-> insert it in between the original node
  ---------------------------------------------------------
  /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
// Function to insert a copy of each
// node in between the original nodes
void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        // Create a new node with the same data
        Node* copy = new Node(temp->val);  
        
        // Point the copy's next to
        // the original node's next
        copy->next = nextElement;  
        
        // Point the original
        // node's next to the copy
        temp->next = copy;         

        // Move to the next original node
        temp = nextElement;         
    }
}

// Function to connect random
// pointers of the copied nodes
void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        // Access the copied node
        Node* copyNode = temp->next;    
        
        // If the original node
        // has a random pointer
        if(temp->random){   
             // Point the copied node's random to the
             // corresponding copied random node
            copyNode->random = temp->random->next; 
        }
        else{
             // Set the copied node's random to
             // null if the original random is null
            copyNode->random = NULL;   
        }
        
         // Move to the next original node
        temp = temp->next->next;   
    }
}

// Function to retrieve the
// deep copy of the linked list
Node* getDeepCopyList(Node* head){
    Node* temp = head;
     // Create a dummy node
    Node* dummyNode = new Node(-1);   
    // Initialize a result pointer
    Node* res = dummyNode;             

    while(temp != NULL){
        // Creating a new List by
        // pointing to copied nodes
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the
        // initial state of the original linked list
        temp->next = temp->next->next;
        temp = temp->next;
    }
    
     // Return the deep copy of the
     // list starting from the dummy node
    return dummyNode->next;   
}
    Node* copyRandomList(Node* head) {
        // If the original list
    // is empty, return null
    if(!head) return nullptr;   
    
     // Step 1: Insert copy of
     // nodes in between
    insertCopyInBetween(head); 
    // Step 2: Connect random
    // pointers of copied nodes
    connectRandomPointers(head);  
    // Step 3: Retrieve the deep
    // copy of the linked list
    return getDeepCopyList(head); 
    }
};
T.C=O(3N)
S.C=O(N)
  
