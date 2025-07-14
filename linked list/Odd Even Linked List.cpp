https://leetcode.com/problems/odd-even-linked-list/description/
LEETCODE-328
 1️⃣ Odd & Even Pointers:
Ek odd pointer odd position ke nodes ko track karega, aur ek even pointer even position ke nodes ko.
Saath hi, evenHead ko store karo taaki end me odd list ke baad even list attach kar sako.
  
2️⃣ Re-link Nodes:
-> Odd ko agle odd node se link karo.
-> Even ko agle even node se link karo.
-> Dono ko aage badhate raho jab tak even ya even->next NULL nahi ho jaaye.

3️⃣ Merge Lists:
Odd list ke end me even list (evenHead) ko attach karo.

  class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save head of even list

        while (even != NULL && even->next != NULL) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};

T.C=O(N)
S.C=O(1)
