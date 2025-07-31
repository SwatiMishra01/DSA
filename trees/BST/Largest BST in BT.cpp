https://www.geeksforgeeks.org/problems/largest-bst/1

-----------------------
  BRUTE FORCE
-----------------------
  /* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  //VALID BST function
    bool isValidBst(Node *root, int minValue, int maxValue) {
    if (!root)
        return true;
    if (root->data >= maxValue || root->data <= minValue)
        return false;
    return isValidBst(root->left, minValue, root->data) && 
           isValidBst(root->right, root->data, maxValue);
}


// Returns size of a tree
int size(Node *root) {
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

    int largestBst(Node *root) {
      // If tree is empty
    if (!root)
        return 0;
    
    // If whole tree is BST
    if (isValidBst(root, INT_MIN, INT_MAX)) 
        return size(root);
  
    // If whole tree is not BST
    return max(largestBst(root->left), 
               largestBst(root->right));
        
    }
};
T.C=O(N*N)
S.C=O(N)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------
        OPTIMAL
  ---------------------------
  /* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// Information about the subtree: Minimum value,
// Maximum value, and Size of the largest BST
class BSTInfo {
  public:
    int min;
    int max;
    int mxSz;

    BSTInfo(int mn, int mx, int sz) {
        min = mn;
        max = mx;
        mxSz = sz;
    }
};

class Solution {
  public:
    // Function to determine the largest BST in the binary tree
BSTInfo largestBSTBT(Node *root) {
    if (!root)
        return BSTInfo(INT_MAX, INT_MIN, 0);

    BSTInfo left = largestBSTBT(root->left);
    BSTInfo right = largestBSTBT(root->right);

    // Check if the current subtree is a BST
    if (left.max < root->data && right.min > root->data) {
        return BSTInfo(min(left.min, root->data), 
                       max(right.max, root->data), 1 + left.mxSz + right.mxSz);
    }

    return BSTInfo(INT_MIN, INT_MAX, max(left.mxSz, right.mxSz));
}

// Function to return the size of the largest BST
    int largestBst(Node *root) {
        return largestBSTBT(root).mxSz;
        
    }
};
T.C=O(N)
S.C=O(N)
