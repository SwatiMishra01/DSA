https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
LEETCODE-1008

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
TreeNode* build(vector<int>& preorder,int &i, int bound){
    if(i==preorder.size() || preorder[i]>bound) return NULL;
    TreeNode*root=new TreeNode(preorder[i++]);
    root->left=build(preorder,i,root->val);
    root->right=build(preorder,i,bound);
    return root;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};
T.C=O(N);
S.C=O(1)
