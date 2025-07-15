https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
 --------------------------------------------
   APPROACH 1->BRUTE FOFRCE
----------------------------------------------

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
      Node*temp1=head;
      vector<pair<int,int>>arr;
      while(temp1!=NULL){
          Node*temp2=temp1->next;
          while(temp2!=NULL && temp1->data+temp2->data <=target){
              if(temp1->data+temp2->data==target)
              arr.push_back({temp1->data,temp2->data});
              temp2=temp2->next;
          }
          temp1=temp1->next;
      }
      return arr;
    }
};
T.C=O(N^2)
S.C=O(N)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------------
    APPROACH 2-> LEFT & RIGHT POINTERS
  ---------------------------------------------
1-> Find left = head, right = tail
2-> Loop while left != right and right->next != left
    - If left->data + right->data == target → add pair, move both pointers.
    - If sum < target → move left forward.
    - If sum > target → move right backward.

  // User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
         vector<pair<int, int>> res;

        // 1. Find tail node
        Node* right = head;
        while (right->next != NULL) {
            right = right->next;
        }

        Node* left = head;

        // 2. Two-pointer approach
        while (left != right && right->next != left) {
            int sum = left->data + right->data;

            if (sum == target) {
                res.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return res;
        
    }
};
T.C=O(N)
S.C=O(1)
(SC = O(1) auxiliary + O(K) output)
