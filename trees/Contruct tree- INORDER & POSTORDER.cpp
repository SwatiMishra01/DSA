
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
LEETCODE-106
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
 TreeNode* helper( vector<int>& inorder, int istart, int iend, vector<int>& postorder, int pstart, int pend, map<int,int>&mp){
    if(istart>iend || pstart>pend) return NULL;
    TreeNode* root= new TreeNode(postorder[pend]);
    int inRoot=mp[postorder[pend]];
    int numsLeft=inRoot-istart;

    root->left=helper(inorder,istart,inRoot-1,
                      postorder,pstart,pstart+numsLeft-1,mp);
    root->right=helper(inorder,inRoot+1,iend,
                       postorder,pstart+numsLeft,pend-1,mp);
                       return root;
 }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        
        map<int,int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        return helper(inorder,0,inorder.size()-1,
                      postorder,0,postorder.size()-1,mp);
    }
};
