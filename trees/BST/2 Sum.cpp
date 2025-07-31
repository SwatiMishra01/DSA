https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
LEETCODE-653


  -------------------------------
  BRUTE FORCE-> USING 2 POINTER
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
void inorder(TreeNode* root,vector<int>&arr){
    if(root==NULL) return;
   //left root right
   inorder(root->left,arr);
   arr.push_back(root->val);
   inorder(root->right,arr);
   return;
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,arr);
        //2 sum logic
   int left = 0, right = arr.size() - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }

        return false;

    }
};
T.C=O(N)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------
    USING BST ITERATOR- next() & befor()
  -----------------------------------------
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
 class BSTIterator{
    private:
    stack<TreeNode*>st;
    //reverse->true->before
    //reverse->false->next
    bool reverse=true;
    public: BSTIterator(TreeNode*root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode*temp=st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
    void pushAll(TreeNode*node){
        for(;node!=NULL;){
            st.push(node);
            if(reverse==true) node=node->right;
            else node=node->left;
        }
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};
T.C=O(N)
S.C=O(height)*2
