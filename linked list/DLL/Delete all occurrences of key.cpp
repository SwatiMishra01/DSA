https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;

        while (temp != NULL) {
            if (temp->data == x) {
                Node* nextNode = temp->next;

                // If it's head node
                if (temp == *head_ref) {
                    *head_ref = nextNode;
                    if (nextNode)
                        nextNode->prev = NULL;
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next)
                        temp->next->prev = temp->prev;
                }

                delete temp;
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }
    }
};

T.C=O(N)
S.C=O(1)
