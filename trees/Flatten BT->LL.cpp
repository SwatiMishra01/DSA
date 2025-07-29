https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
LEETCODE-114

  ---------------------------
      BRUTE FORCE
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
TreeNode*prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->right=prev;
        root->left=NULL;
        prev=root;
        
    }
};
T.C=O(N)
S.C=O(log2N)

------------------------------
  BETTER- USING STACK
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
TreeNode*prev=NULL;
    void flatten(TreeNode* root) {
         if(root == NULL){
            return;
        }
        // Use a stack for
        // iterative traversal.
        stack<TreeNode*> st;
        // Push the root node
        // onto the stack.
        st.push(root);  
        
        // Continue the loop until
        // the stack is empty.
        while (!st.empty()) {  
            // Get the top node from the stack.
            TreeNode* cur = st.top(); 
            // Pop the top node.
            st.pop();  

            if (cur->right != NULL) {
                 // Push the right child
                 // onto the stack.
                st.push(cur->right); 
            }
            
            if (cur->left != NULL) {
                 // Push the left child
                 // onto the stack.
                st.push(cur->left); 
            }

            if (!st.empty()) {
                // Connect the right child to
                // the next node in the stack.
                cur->right = st.top();  
            }
            
            // Set the left child to NULL to
            // form a right-oriented linked list.
            cur->left = NULL;
        }
        
    }
};
T.C & S.C= SAME AS ABOVE

  ----------------------------------
   OPTIMAL USING MORRIS TRAVERSAL
  ------------------------------------
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
    void flatten(TreeNode* root) {
        // Initialize a pointer
        // 'curr' to the root of the tree
        TreeNode* curr = root;

        // Iterate until 'curr'
        // becomes NULL
        while (curr) {
            // Check if the current
            // node has a left child
            if (curr->left) {
                // If yes, find the rightmost
                // node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                // Connect the rightmost node in
                // the left subtree to the current
               //  node's right child
                pre->right = curr->right;

                // Move the entire left subtree to the
                // right child of the current node
                curr->right = curr->left;

                // Set the left child of
                // the current node to NULL
                curr->left = NULL;
            }

            // Move to the next node
            // on the right side
            curr = curr->right;
        }
    }
};
T.C=O(2N)
S.C=O(1)
