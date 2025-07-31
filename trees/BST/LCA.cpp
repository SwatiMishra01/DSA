https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
LEETCODE-235
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
        if(root== NULL) return NULL;
        int curr=root->val;
        if(curr<p->val && curr<q->val) return lowestCommonAncestor(root->right,p,q);
        if(curr>p->val && curr> q->val) return lowestCommonAncestor(root->left,p,q);

        return root;
    }
};
T.C=O(N)
S.C=O(1)
