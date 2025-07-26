https://leetcode.com/problems/diameter-of-binary-tree/description/
LEETCODE-543


------------------------------
       BRUTE FORCE
------------------------------
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
    int diameter = 0;  
    int calculateHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        diameter = max(diameter, leftHeight + rightHeight);

 
        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calculateHeight(root);
        return diameter;

    }
};
T.C=O(N^2)
S.C=O(1)


---------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
int height(TreeNode*node,int &diameter){
    if(!node) return 0;
    int lh=height(node->left,diameter);
    int rh=height(node->right,diameter);

    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};
T.C=O(N)
S.C=O(1)
  
