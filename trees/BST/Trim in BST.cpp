https://leetcode.com/problems/trim-a-binary-search-tree/description
LEETCODE-669

--------APPROACH---------
-> If root == NULL, return NULL.

->If root->val < low: discard current node and its left subtree → return trimBST(root->right, low, high)
->If root->val > high: discard current node and its right subtree → return trimBST(root->left, low, high)

Otherwise:
Recursively trim left and right

Return current node


----------------------------------------------------------------------------------------------------------------------------------------------------------------
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return NULL;

        if(root->val<low) return trimBST(root->right,low,high);
        if(root->val>high) return trimBST(root->left,low,high);

        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);


        
        return root;

    }
};
T.C=O(N)
S.C=O(height)
