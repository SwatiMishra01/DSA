https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/
LEETCODE-3217
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto i:nums)    mp[i]++;
        ListNode* temp=head;
        ListNode* prev=head;

        while(temp!=nullptr){
            if(mp[temp->val]>0){

                //if head element is deleted
                if(prev==temp){
                    if(head==temp) head=head->next;

                    //move temp & prev
                    temp=temp->next;
                    prev=temp;
                }else {
                    temp=temp->next;
                    prev->next=temp;
                }
            }
            else {
                prev=temp;
                temp=temp->next;

            }
        }

        return head;
        
    }
};©leetcode
