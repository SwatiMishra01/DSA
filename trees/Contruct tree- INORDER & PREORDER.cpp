https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
LEETCODE-105
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
TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,  vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
                // Base case: If the start indices  exceed the end indices, return NULL
                if(preStart > preEnd || inStart > inEnd)
                    return NULL;
                TreeNode* root = new TreeNode(preorder[preStart]);
                
                // Find the index of the current root
                // value in the inorder traversal
                int inRoot = inMap[root->val];
                
                // Calculate the number of
                // elements in the left subtree
                int numsLeft = inRoot - inStart;
        
                root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,  inorder, inStart, inRoot - 1, inMap);
                root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
                return root;
                }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        
        // Populate the map with indices of elements in the inorder traversal
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
 TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1,inMap);
        return root;
    }
};
