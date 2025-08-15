https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
LEETCODE-2130

  -----------------------------------------------------
  APPROACH 1-> STORING ELEMENTS IN ARRAY THEN 2 POINTER
  ------------------------------------------------------

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }

       int maxi=0;
       int i=0;
       int j=arr.size()-1;
            while(i<j){
                int sum=arr[i]+arr[j];
                if(sum>maxi) maxi=sum;
                i++;
                j--;
            }
            return maxi;
    }
};
T.C=O(N)
S.C=O(N)

--------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------
     USING STACKS
  ------------------------
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
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode*temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }

        int n=st.size();
        ListNode*curr=head;
        int count=1;
        int maxi=0;
        while(count<=n/2){
          maxi=max(maxi,curr->val+st.top());
          st.pop();
          curr=curr->next;
          count++;
        }
        return maxi;
    }
};
T.C=O(N)
S.C=O(N)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------
   REVERSING HALF LL
  --------------------
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
    int pairSum(ListNode* head) {
         // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // now prev = head of reversed second half

        // Step 3: Calculate max twin sum
        int maxi = 0;
        ListNode* first = head;
        ListNode* second = prev; // reversed half
        while (second) { // second half length = first half length
            maxi = max(maxi, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxi;
    }
};
