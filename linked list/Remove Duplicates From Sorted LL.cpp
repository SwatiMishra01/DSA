https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
LEETCODE-83

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
    ListNode* deleteDuplicates(ListNode* head) {
        //base case
        if(head==NULL || head->next==NULL)
        return head;


        ListNode*curr=head;
        while(curr!=NULL){
          if(curr->next!=NULL && curr->val==curr->next->val){
            ListNode*next_next= curr->next->next;
            ListNode*nodeToDelete=curr->next;
            curr->next=next_next;
            delete (nodeToDelete);
          }
          else
          curr=curr->next;
        }
        return head;
        
    }
};


--------------------------------------------------------
  FOLLOW-UP QUES (delete all nodes whch are duplicated)
----------------------------------------------------------
  https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
LEETCODE-82
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
    ListNode* deleteDuplicates(ListNode* head) {
        //base case
        if(head==NULL || head->next==NULL)
        return head;

       //nodes intitialization
       ListNode*dummy=new ListNode(-1);
       dummy->next=head;
       ListNode*curr=head;
       ListNode*prev=dummy;

       while(curr!=NULL && curr->next!=NULL){
        if( curr->val==curr->next->val){
            while(curr->next!=NULL && curr->val==curr->next->val){
                curr=curr->next;
            }
            prev->next=curr->next;
        }
        else
        prev=prev->next;
        curr=curr->next;
       }
       return dummy->next;
    }
};
