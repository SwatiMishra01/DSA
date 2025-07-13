https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

----------------------------------------------------
   APPROACH 1-> USING 2 LOOPS AND TRAVERSING (TLE)
----------------------------------------------------
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        //base case 
        if (head==NULL || head->next==NULL)
        return head;
        
        Node*curr=head;
        while(curr!=NULL){
            Node*temp=curr;
            while(temp->next!=NULL){
                if(curr->data==temp->next->data){
                Node*duplicate= temp->next;
                temp->next=temp->next->next;
                delete duplicate;
                    
                }
                else
                temp=temp->next;
            }
             curr=curr->next;
        }
        return head;
       
    }
};
T.C=O(N^2)-> therefore TLE
S.C=O(1);

----------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------------------------
   APPROACH 2-> Using HashSet - O(n) Time and O(n) Space
----------------------------------------------------------
  /*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        //base case 
        if (head==NULL || head->next==NULL)
        return head;
        
        unordered_set<int> hashSet;
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr) {

        // Check if the element is already in the hash table
        if (hashSet.find(curr->data) != hashSet.end()) {

            // Element is present, remove it
            prev->next = curr->next;

            // Delete the curr node
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        else {

            // Element is not present, add it to hash table
            hashSet.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
       
    }
};
T.C=O(N)
S.C=O(N)
