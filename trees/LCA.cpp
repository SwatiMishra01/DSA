https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
LEETCODE-236
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL || root==p || root==q) return root;

        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);

        //result
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;

    }
};
T.C=O(N)
S.C=O(N)
