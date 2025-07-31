https://leetcode.com/problems/validate-binary-search-tree/description/
LEETCODE-98
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
bool f(TreeNode*root, long long minVal ,long long maxVal){
    if(root==NULL) return true;
    if(root->val >=maxVal || root->val<=minVal) return false;

    return f(root->left,minVal,root->val) && f(root->right,root->val,maxVal);
}
    bool isValidBST(TreeNode* root) {
        return f(root,LLONG_MIN, LLONG_MAX);
    }
};
T.C=O(N)
S.C=O(1)
