https://leetcode.com/problems/palindrome-linked-list/description/
LEETCODE-234

  -----------------------------------------
         APPROACH 1-> USING ARRAY
  -----------------------------------------

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
int checkPallindrome(vector<int>&arr){
    int s=0;
    int e=arr.size()-1;
    while(s<=e){
    if(arr[s]!=arr[e]){
    return false;
    }
    s++;
    e--;
    }
    return true;
}
    bool isPalindrome(ListNode* head) {
        ListNode*temp=head;
        vector<int>arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        return checkPallindrome(arr);
        
    }
};
T.C: O(2 * N)~ O(N) This is because we traverse the linked list twice:
S.C=O(N)

  -------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------------------------------------------
  APPROACH 2->reversing only half & comparing the first and second halves
-----------------------------------------------------------------------------
  class Solution {
public:
    ListNode* Mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Step 1: Find middle
        ListNode* middle = Mid(head);

        // Step 2: Reverse second half
        middle->next = reverse(middle->next);

        // Step 3: Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle->next;

        while (head2 != NULL) {
            if (head1->val != head2->val) {
                // Restore before returning false
                middle->next = reverse(middle->next);
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4: Restore list
        middle->next = reverse(middle->next);

        return true;
    }
};

T.C=O(2N)~O(N)
S.C=O(1)
