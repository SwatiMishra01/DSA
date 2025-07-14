https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
LEETCODE-19
  ----------------------------
   BRUTE FORCE APPROACH
  ------------------------------
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //base case
        if(head==NULL)
        return NULL;

        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
          

          //base case
          if(count==n){
            ListNode* newHead=head->next;
            delete(head);
            return newHead;
          }

        int indx=count-n;
        temp=head;

        for(int i = 1; i < indx; i++) {
    temp = temp->next;
}

    ListNode*deleteNode=temp->next;
        temp->next=temp->next->next;
        delete deleteNode;
        return head;


    }
};
T.C=O(len)+O(len-n)
S.C=O(1)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------------------
   OPTIMAL APPROACH
  ----------------------------------------
  class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast ahead by n steps
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is NULL, we need to delete the head
        if (fast == NULL) {
            ListNode* deleteNode = head;
            head = head->next;
            delete deleteNode;
            return head;
        }

        // Move both fast and slow until fast reaches the end
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove slow->next
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;

        return head;
    }
};
T.C=O(N)
S.C=O(1)
