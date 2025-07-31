https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/ 
LEETCODE-1038

  https://leetcode.com/problems/convert-bst-to-greater-tree/description/?envType=problem-list-v2&envId=binary-search-tree
  LEETCODE-538

  (BOTH ARE EXACTLY SAME QUES)
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

 //  ALGORITHM->
 // ->Inorder Traversal 
 // ->Generate Greater Sum Values 
 // ->Update the Tree

class Solution {
public:
void inorder(TreeNode*root,vector<int>&arr){
    //base case
    if(root==NULL) return;
    
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
}

void update(TreeNode*root,vector<int>&updatedValues,int &index){
    if(root==NULL) return;

    update(root->left,updatedValues,index);
    root->val=updatedValues[index++];
    update(root->right,updatedValues,index);
}


    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return root;
        vector<int>arr;
        inorder(root,arr);

        int n=arr.size();
        vector<int>updatedValues(n);
        updatedValues[n - 1] = arr[n - 1];

        for(int i = n - 2; i >= 0; i--) updatedValues[i] = updatedValues[i + 1] + arr[i];
        int index = 0;
        update(root, updatedValues, index);

        return root;

    }
};
