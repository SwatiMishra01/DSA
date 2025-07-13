https://leetcode.com/problems/linked-list-cycle-ii/
LEETCODE-142


  ---------------------------------------------
             BRUTE FORCE
  -----------------------------------------------
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
    ListNode *detectCycle(ListNode *head) {
        // Use temp to traverse the linked list
    ListNode* temp = head;
    
    // hashmap to store all visited nodes
    unordered_map<ListNode*, int> mp;
    
    // Traverse the list using temp
    while(temp!=NULL){
        // check if temp has been encountered again
        if(mp.count(temp)!=0){
            // A loop is detected hence return temp
            return temp;
        }
        // store temp as visited
        mp[temp] = 1;
        // iterate through the list
        temp = temp->next;
    }

    // If no loop is detected, return nullptr
    return nullptr;
    }
};
T.C=O(N)
S.C=O(N)
------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
//FCD->floyd cycle detection
ListNode*FCD(ListNode*head){
    //base case
    if(head==NULL)
    return NULL;


ListNode*slow=head;
ListNode*fast=head;


while(fast!=NULL && fast->next!=NULL){
    fast=fast->next->next;
    slow=slow->next;
    if(slow==fast)
    return slow;
}
return NULL;
}
    ListNode *detectCycle(ListNode *head) {
        //base case
    if(head==NULL)
    return NULL;

    ListNode*intersection=FCD(head);
     if (intersection == NULL) return NULL; // ⚡ handle no cycle
    ListNode*slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;

    }
};
T.C=O(N)
S.C=O(1)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  
