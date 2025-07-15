https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
LEETCODE-2095

  --------------------------------------------
   APPROACH 1-> BRUTE FORCE
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
    ListNode* deleteMiddle(ListNode* head) {
        //base case
        if(head==NULL || head->next==NULL)
        return NULL;
        
        ListNode*temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        //node before midddle
         int prev=n/2;
        temp=head;
        while(temp!=NULL){
            prev--;
            if(prev==0){
                ListNode*middle=temp->next;
                //change links of node before middle to after middle
                temp->next=temp->next->next;
                delete middle;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};
T.C=O(N)+O(N/2)~ O(N)
S.C=O(1)
------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------------------------
  APPROACH 2->Tortoise and Hare Algorithm (slow/fast ptrs)
--------------------------------------------------------------
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
    ListNode* deleteMiddle(ListNode* head) {

        //base case
        if(head==NULL || head->next==NULL)
        return NULL;
        ListNode*slow=head;
        ListNode*fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*prev=slow;
        ListNode*middle=slow->next;
        //changing link
        prev->next=prev->next->next;
        delete middle;
     return head;
    }
  
};
T.C=O(N/1)~O(N)
S.C=O(1)
