https://leetcode.com/problems/subtree-of-another-tree/description/
LEETCODE-572

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
bool ans = false;

bool match(TreeNode * root, TreeNode *subRoot) {
  if (root && subRoot) {
    bool a = match(root -> left, subRoot -> left);
    bool b = match(root -> right, subRoot -> right);

    if ((root -> val == subRoot -> val) && a && b)
      return true;
    else
      return false;
  } else if (!root && !subRoot) return true;
  else return false;
}

void inorder(TreeNode * root, TreeNode * subRoot) {
  if (root) {
    inorder(root -> left, subRoot);
    bool x = match(root, subRoot);
    if (x) ans = 1;
    inorder(root -> right, subRoot);
  }
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        inorder(root, subRoot);
  return ans;
    }
};
