https://leetcode.com/problems/binary-tree-postorder-traversal/
LEETCODE-145
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
void postorder(TreeNode*root,vector<int>&ans){
    if(root==NULL) return ;
    //left
    postorder(root->left,ans);
    //right
    postorder(root->right,ans);
    //root
    ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};
