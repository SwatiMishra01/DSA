https://leetcode.com/problems/sort-list/description/
LEETCODE-148
------------------------------
  APPROACH 1->BRUTE FORCE
------------------------------
  STEP 1-> copy values of LL in array
  STEP 2-> sort the array
  STEP 3-> copy sorted values of array in LL back

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
    ListNode* sortList(ListNode* head) {
        //base case
     if (head == NULL) return head;

//arr creation
     vector<int>arr;
     ListNode*temp=head;

     //copying values of LL to array
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        //sorting array
        sort(arr.begin(),arr.end());

      //copying sorted array values back to LL
        temp=head;
            for(int i=0; i<arr.size(); i++){
                temp->val=arr[i];
             temp=temp->next;
             }
        return head;
        
    }
};
T.C=O(N)+O(N LOGN)
S.C=O(N)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------------------
   APPROACH 2-> MERGE SORT
  --------------------------------------------------

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

// Function to merge two sorted linked lists
ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to find the middle of a linked list
ListNode* findMiddle(ListNode* head){
    // If the list is empty or has only one node
    // the middle is the head itself
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Initializing slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head->next;

    // Move the fast pointer twice as fast as the slow pointer
    // When the fast pointer reaches the end, the slow pointer
    // will be at the middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // Find the middle of the list using the findMiddle function
    ListNode* middle = findMiddle(head);
    
    // Divide the list into two halves
    ListNode* right = middle->next;
    middle->next = nullptr;
    ListNode* left = head;
    
    // Recursively sort the left and right halves
    left = sortList(left);
    right = sortList(right);
    
    // Merge the sorted halves using the mergeTwoSortedLinkedLists function
    return mergeTwoSortedLinkedLists(left, right);
    }
};
T.C=O(N log N)
S.C=O(1)
