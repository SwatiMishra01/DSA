https://leetcode.com/problems/house-robber-iii/
LEETCODE-337

  ------------------------
       RECURSION
  ------------------------
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
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        
        //case 1-> robbing root
        int rob_root=root->val;
        if(root->left){
          rob_root+=rob(root->left->left);
         rob_root+=rob(root->left->right);
        }
        if(root->right){
          rob_root+=rob(root->right->left);
          rob_root+=rob(root->right->right);
        }
        //case 2->skipping root
        int skip_root=rob(root->left)+rob(root->right);


    return max(rob_root,skip_root);
    }
};
T.C=O(2^n)
S.C=O(h)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------
       MEMOIZATION
  ---------------------------
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
    unordered_map<TreeNode*, int> memo;
    
    int robHelper(TreeNode* root) {
        if (!root) return 0;
        
        if (memo.count(root)) return memo[root];
        
        // Case 1: Rob this node
        int rob_root = root->val;
        if (root->left) {
            rob_root += robHelper(root->left->left) + robHelper(root->left->right);
        }
        if (root->right) {
            rob_root += robHelper(root->right->left) + robHelper(root->right->right);
        }
        
        // Case 2: Skip this node
        int skip_root = robHelper(root->left) + robHelper(root->right);
        
        // Memoize and return
        return memo[root] = max(rob_root, skip_root);
    }
    
public:
    int rob(TreeNode* root) {
        return robHelper(root);
    }
};
T.C=O(n)
S.C=O(n+h)≈O(n)
