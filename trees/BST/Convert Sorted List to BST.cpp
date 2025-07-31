https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
LEETCODE-109
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);

   //determine middle node as root by using tortoise hare algo
        ListNode*slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

   //making middle node as root
        TreeNode*root=new TreeNode(slow->val);
        prev->next=NULL; //breaking link
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);

        return root;
        
    }
};
T.C=O(N log N)
S.C=O(1)
