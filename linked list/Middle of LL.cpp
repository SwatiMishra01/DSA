----------------------------
  APPROACH 1
----------------------------
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
class Solution {
public:

int getLength(ListNode* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode*temp=head;
        int len=getLength(head);
        while(count<len/2){
            count++;
            temp=temp->next;
        }
        return temp;


    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------------
       OPTIMISED SOLUTION- SLOW & FAST PTRS
  --------------------------------------------
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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next == NULL)
        return head;
        ListNode*slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL)
            fast=fast->next;

            slow=slow->next;
        }
        return slow;
    }
};
  
  
