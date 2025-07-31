https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
LEETCODE-1305

  --------------------
     BRUTE FORCE
  --------------------
  
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

void preorder(TreeNode*root,vector<int>&res){
    if(root==NULL) return;
    res.push_back(root->val);
    preorder(root->left,res);
    preorder(root->right,res);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;
        preorder(root1,res);
        preorder(root2,res);
        sort(res.begin(),res.end());
        return res;
    }
};
T.C=O(N LOGN)
S.C=O(N)
