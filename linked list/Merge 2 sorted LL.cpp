https://leetcode.com/problems/merge-two-sorted-lists/description/
LEETCODE-21
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //base case
        if(!list1)
        return list2;

        if(!list2)
        return list1;


        //choosing head
        ListNode*head=(list1->val <= list2->val) ? list1 : list2;

        //changing both lists current posittion
        ListNode*curr1= (head==list1)?list1->next: list1;
        ListNode*curr2=(head==list2)? list2->next: list2;

        ListNode*tail=head;


        //merging both lists
        while(curr1 && curr2){
            if(curr1->val <= curr2->val){
                tail->next= curr1;
                curr1=curr1->next;
            }
            else{
                tail->next=curr2;
                curr2=curr2->next;
            }
            tail=tail->next;
        }
        tail->next=curr1? curr1 :curr2; // If curr1 is not nullptr, then assign tail->next = curr1. Otherwise, assign tail->next = curr2.
        return head;
    }
};
