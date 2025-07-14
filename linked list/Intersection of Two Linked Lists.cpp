https://leetcode.com/problems/intersection-of-two-linked-lists/description/
LEETCODE-160

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>mpp;
        ListNode*temp1=headA;
        while(temp1!=NULL){
         mpp[temp1]=1;
         temp1=temp1->next;
        }


        ListNode*temp2=headB;
        while(temp2!=NULL){
            if(mpp.find(temp2)!=mpp.end())
            return temp2;

            temp2=temp2->next;
        }
        return NULL;
        
    }
};
