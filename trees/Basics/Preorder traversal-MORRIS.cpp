https://leetcode.com/problems/binary-tree-preorder-traversal/description/
LEETCODE-144
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
    vector<int> preorderTraversal(TreeNode* root) {
        //root -> left -> right
        vector<int> preorder;
        TreeNode*curr = root;
        while(curr){
            preorder.push_back(curr -> val);
            if(curr -> left){
                //connect right most to root
                TreeNode*prev = curr->left;
                while(prev -> right){
                    prev = prev -> right;
                }
                TreeNode* temp = curr;
                prev -> right = curr->right;
                curr = curr -> left;
                temp -> left = NULL;
            }else{
                // preorder.push_back(curr->val);
                curr = curr -> right;
            }
        }
        return preorder;
    }
};
