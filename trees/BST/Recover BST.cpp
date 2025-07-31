https://leetcode.com/problems/recover-binary-search-tree/description/
LEETCODE- 99
  -------------------------
       BRUTE FORCE
  -------------------------
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void inorder(TreeNode* root, vector<int>& arr){
        if(root == NULL) return ;
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);

    }
    void makebst(TreeNode* root, vector<int>& arr, int& i){
        if(root == nullptr || i > arr.size()){
            return ;
        }
        makebst(root -> left, arr, i);
        root -> val = arr[i++];
        makebst(root -> right, arr, i);
    }
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        sort(arr.begin(), arr.end());
        int index = 0;
        makebst(root, arr, index);
    }
};
T.C=O(2N)+O(N LOGN)
S.C=O(N)


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------------
      OPTIMAL APPROACH
  -----------------------------------
  

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode*first;
TreeNode*middle;
TreeNode*last;
TreeNode*prev;
void inorder(TreeNode*root){
    if(root==NULL) return;
    inorder(root->left);

    if(prev!=NULL&& (root->val<prev->val)){
        //first violation
        if(first==NULL){
            first=prev;
            middle=root;
        }
        //second violation
        else last=root;
    }


    prev=root;
    inorder(root->right);
}

    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);

    }
};
T.C=O(N)
S.C=O(1)
