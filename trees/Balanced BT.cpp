https://leetcode.com/problems/balanced-binary-tree/
LEETCODE-110

  ----------------------
       BRUTE FORCE
  ----------------------
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
int findH(TreeNode*root){
    if(root==NULL) return 0;

    int lh=findH(root->left);
    int rh=findH(root->right);

    return 1+max(lh,rh);
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int lh=findH(root->left);
        int rh=findH(root->right);

        if(abs(lh-rh)>1) return false;

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        if(!left || !right) return false;

        return true;
    }
};
T.C=O(N^2)
S.C=O(1)

----------------------------------------------------------------------------------------------------------------------------------------------------------------

  ----------------------------
  OPTIMAL APPROACH
  ----------------------------
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
 // the height of the tree
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        // height of the left subtree
        int leftHeight = dfs(root->left);
        if (leftHeight == -1) 
            return -1;

        // height of the right subtree
        int rightHeight = dfs(root->right);
        if (rightHeight == -1) 
            return -1;

        // Check if the difference in height between
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
         return dfs(root) != -1;
    }
};
T.C=O(N)
S.C=O(1)
  
