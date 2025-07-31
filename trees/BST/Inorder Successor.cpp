https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
----------------------------------
  BRUTE FORCE USING LINEAR SEARCH
-----------------------------------
/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node*root, vector<int>&arr){
        if(root==NULL) return;
        
        inorder(root->left,arr);
         arr.push_back(root->data);
        inorder(root->right,arr);
        return;
    }
    int inOrderSuccessor(Node *root, Node *x) {
        vector<int>arr;
        inorder(root,arr);
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>x->data){ 
                return arr[i];
                
            }
        }
        return -1;
    }
};
T.C=O(N)
S.C=O(N)

--------------------------------
  BRUTE FROCE SUING BINARY SEARCH
  --------------------------------
  /*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node*root, vector<int>&arr){
        if(root==NULL) return;
        
        inorder(root->left,arr);
         arr.push_back(root->data);
        inorder(root->right,arr);
        return;
    }
    int inOrderSuccessor(Node *root, Node *x) {
        vector<int>arr;
        inorder(root,arr);
        int s=0;
        int e=arr.size()-1;
        int ans = -1;
    while(s<=e){
        int mid=s+(e-s)/2;
         if (arr[mid] > x->data) {
                ans = arr[mid];
                e = mid - 1;
            } else 
                s = mid + 1;
    }
        return ans;
    }
};
T.C=O(N LOG N)
S.C=O(N)

--------------------
  BETTER APPROACH
---------------------
  /*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        Node* succ = NULL;
        while (root) {
            if (x->data < root->data) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ ? succ->data : -1;
        
    }
};
T.C=O(N)
S.C=O(1)
