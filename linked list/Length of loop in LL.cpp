https://www.naukri.com/code360/problems/find-length-of-loop_8160455
https://www.geeksforgeeks.org/problems/find-length-of-loop/1

--------------------------------------------------
  APPROACH 1-> HASHMAP
---------------------------------------------------
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    // Hashmap to store visited
    // nodes and their timer values
    unordered_map<Node*, int> visitedNodes; 
    
    // Initialize pointer to
    // traverse the linked list
    Node* temp = head; 
    
    // Initialize timer to track
    // visited nodes
    int timer = 0; 

    // Traverse the linked list till
    // temp reaches nullptr
    while (temp != NULL) {
        
        // If revisiting a node return
        // the difference of timer values
        if (visitedNodes.find(temp) != visitedNodes.end()) {
            // Calculate the length of the loop
            int loopLength = timer - visitedNodes[temp];
            
            // Return the length of the loop
            return loopLength; 
        }
        // Store the current node and
        // its timer value in the hashmap
        visitedNodes[temp] = timer;
        
        // Move to the next node
        temp = temp->next;
        
         // Increment the timer
        timer++;
    }

    // If traversal is completed and
    // we reach the end of the list (null)
    // means there is no loop
    return 0;

}
T.C=O(2N)
S.C=O(N)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------------
   APPROACH 2->TORTOISE & HARE ALGO
  ----------------------------------------------
  /*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  
    // Helper function to find length of loop
    int findLength(Node* slow, Node* fast) {
        int cnt = 1;
        fast = fast->next;
        
        while (slow != fast) {
            cnt++;
            fast = fast->next;
        }
        
        return cnt;
    }
    
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop using Floyd’s cycle detection
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;     
            fast = fast->next->next;

            if (slow == fast) {
                return findLength(slow, fast);
            }
        }

        // Step 2: No loop found
        return 0;
    }
};
T.C=O(2N)
S.C=O(1)
