https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

-----------------------------------------
  APPROACH 1-> BRUTE FORCE  using array
------------------------------------------
STEP 1-> store bottoms= wise data in array
STEP 2-> sort array
STEP 3-> create new LL from sorted array and return
  
  /* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  //function to convert array into LL
  Node*convert(vector<int>&arr){
      Node*dummy=new Node(-1);
      Node*temp=dummy;
      for(int i=0; i<arr.size(); i++){
          temp->bottom=new Node(arr[i]);
          temp=temp->bottom;
      }
      return dummy->bottom;
  }
  
  
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        //step 1-> push in array
        vector<int>arr;
        while(root!=NULL){
        Node*temp=root;
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp=temp->bottom;
        }
        root=root->next;
        }
        
        //step 2->sort array
        sort(arr.begin(),arr.end());
        
        //step3->convert array to LL
        return convert(arr);
        
    }
};
T.C=O(2 n*m + n log n)~ O(n log n)
S.C=O(2 n*m)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------
 APPPROACH 2-> MERGE Sorted LL concept
--------------------------------------------------------
  /* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  Node* merge(Node* list1, Node* list2){
    // Create a dummy node as a
    // placeholder for the result
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->bottom = list1;
            res = list1;
            list1 = list1->bottom;
        }
        else{
            res->bottom = list2;
            res = list2;
            list2 = list2->bottom;
        }
        res->next = NULL;
    }

    // Connect the remaining
    // elements if any
    if(list1){
        res->bottom = list1;
    } else {
        res->bottom = list2;
    }

    // Break the last node's
    // link to prevent cycles
    if(dummyNode->bottom){
        dummyNode->bottom->next = NULL;
    }

    return dummyNode->bottom;
}
  
  
  
  
  
  
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
       // If head is null or there 
    // is no next node, return head
    if(root == NULL || root->next == NULL){
        return root;
    }

    // Recursively flatten the
    // rest of the linked list
    Node* mergedHead = flatten(root->next);
    root = merge(root, mergedHead);
    return root;
        
    }
};
T.C=O(N*M)
S.C=O(1)
