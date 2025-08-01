https://leetcode.com/problems/binary-tree-inorder-traversal/description/
LEETCODE-94
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
void inorder(TreeNode* root,vector<int>&ans){
     if(root==NULL) return;
        //left 
        inorder(root->left,ans);
        //root
         ans.push_back(root->val);
        //right
         inorder(root->right,ans);
}

    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>ans;
       inorder(root,ans);
       return ans;
    }
};

--------------------------------------
     ITERATIVE-> USING STACK
--------------------------------------
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>inorder;
        TreeNode*node=root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()==true) break;
                node=st.top();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
    }
};
   
