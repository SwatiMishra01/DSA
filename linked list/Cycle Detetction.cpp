https://leetcode.com/problems/linked-list-cycle/description/
LEETCODE-141

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

  ------------------
   slow & fast ptrs
-----------------------------
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //base case
        if(head==NULL)
        return false;


        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast)
        return true;
        
    }
    return false;
}
};
