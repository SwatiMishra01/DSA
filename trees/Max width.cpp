https://leetcode.com/problems/maximum-width-of-binary-tree/description/
LEETCODE-662
  
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
    int widthOfBinaryTree(TreeNode* root) {
        //base case
         if (!root)   return 0;
         int ans = 0;
         queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
         // Perform level-order traversal
        while (!q.empty()) {
            int size = q.size();
            long long mini = q.front().second;
            long long first, last;

            // Process each node
            // in the current level
            for (int i = 0; i < size; i++) {
                long long cur_id = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();

                // If this is the first node in the level, 
                // update the 'first' variable
                if (i == 0) {
                    first = cur_id;
                }

                // If this is the last node in the level,
                // update the 'last' variable
                if (i == size - 1) {
                    last = cur_id;
                }

                // Enqueue the left child of the 
                // current node with its position
                if (node->left) {
                    q.push({node->left, cur_id * 2 + 1});
                }

                // Enqueue the right child of the
                // current node with its position
                if (node->right) {
                    q.push({node->right, cur_id * 2 + 2});
                }
            }
            ans = max(ans, (int)(last - first + 1));
        }
        return ans;
    }
};
T.C=O(N)
S.C=O(N)
