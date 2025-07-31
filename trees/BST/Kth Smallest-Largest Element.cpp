https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
LEETCODE-230

  ----------------------------
       BRUTE FORCE
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
//INORDER-> left root right
void inorder(TreeNode*root,vector<int>&arr){
    if(root==NULL) return;
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
    return;

}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,arr);
        // sort(arr.begin(),arr.end()); inorder is already sorted so no need to do this it will just occupy extra space (but if use pre/post-make sure to sort)
        return arr[k-1];
        
    }
};
T.C=O(N)
S.C=O(N)

  NOTE-> YOU CAN DO LAREGST LIKE THIS ALSO 

---------------------------
  OPTIMAL APPROACH
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
public:
int count=0;
int ans=-1;
//INORDER-> left root right
void inorder(TreeNode*root,int k){
    if(root==NULL || count>=k) return;
    inorder(root->left,k);
    count++;
    if(count==k){
        ans=root->val;
        return ;
    }
    inorder(root->right,k);

}
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
        
    }
};
T.C=O(N)
S.C=O(1)
