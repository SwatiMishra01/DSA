https://leetcode.com/problems/intersection-of-two-linked-lists/description/
LEETCODE-160

    --------------------------------------------
     APPROACH 1-> USINH HASHMAP
    --------------------------------------------
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

T.C=O(N1*map)+O(N2*map)
S.C=O(N1)->if you store values of LL 1 otherwise O(N2) if store LL2 values

------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------
     APPROACH 2-> USING DIFFERENCE IN LENGTH
--------------------------------------------------------------
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
//function to calculate length of LL
int traverse(ListNode*head){
  ListNode*temp=head;
  int len=0;
  while(temp!=NULL){
    len++;
    temp=temp->next;
  }
  return len;
}

//function to calculation collisionpoint considering (small LL, big LL, diff)
ListNode*collisionPoint(ListNode*head1,ListNode*head2,int diff){
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    for(int i=0; i<diff; i++){
        temp2=temp2->next;
    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1==temp2)
        return temp1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;

}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int N1=traverse(headA);
        int N2=traverse(headB);
        if(N1<N2){ //LL2 is bigger and it has to move N2-N1 distance first
                   //  to align and then compare simultaneously
         return  collisionPoint(headA,headB,N2-N1);
        }
        else{
          return collisionPoint(headB,headA,N1-N2);
        }

        return NULL;
        
    }
};
T.C=O(N1)+O(N2)+O(diff) +O(N1)->the shortest LL coz it it will be traversed till null if no internsection
T.C~O(N1+2N2)
S.C=O(1)

    ----------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------
    APPROACH 3-> OPTIMISED 
--------------------------------------------
    
-> Take two dummy nodes for each list. Point each to the head of the lists.
-> Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.

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
        ListNode* d1 = headA;
    ListNode* d2 = headB;
    
    while(d1 != d2) {
        d1 = d1 == NULL? headB:d1->next;
        d2 = d2 == NULL? headA:d2->next;
    }
    
    return d1;
    }
};
T.C=O(2*max(length of list1,length of list2))
S.C=O(1)
    
