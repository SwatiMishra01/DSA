https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool getPath(TreeNode* root, vector<int>&arr, int x){
     if(!root) return false;
     arr.push_back(root->val);
     if(root->val==x) return true;
     
     if(getPath(root->left,arr,x)|| getPath(root->right,arr,x)) return true;
     
     arr.pop_back();
     return false;
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>arr;
    if(A==NULL) return arr;
    getPath(A,arr,B);
    return arr;
}
T.C=O(N)
S.C=O(N)

 ---------------------------------------------
 FOLLOW UP QUES-> ROOT TO ALL LEAF NODES PATH
 ---------------------------------------------
 https://leetcode.com/problems/binary-tree-paths/description/

 
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
void findPath(TreeNode* node, vector<string>& ans, string temp) {
        temp += to_string(node->val);  // Add the current node value to the path
        if (node->left) findPath(node->left, ans, temp + "->");  // Traverse left
        if (node->right) findPath(node->right, ans, temp + "->"); // Traverse right
        if (!node->left && !node->right) ans.push_back(temp);  // Add path if leaf node
    }
    vector<string> binaryTreePaths(TreeNode* root) {
          vector<string> ans;
        if (root) findPath(root, ans, "");  // Start traversal from the root
        return ans;
    }
};
