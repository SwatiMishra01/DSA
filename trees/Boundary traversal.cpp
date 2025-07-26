https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
  public:
  
    bool isLeaf(Node* node) {
        return node->left == NULL && node->right == NULL;
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    void addLeafs(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeafs(root->left, res);
        if (root->right) addLeafs(root->right, res);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (root == NULL) return res;

        if (!isLeaf(root)) res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeafs(root, res);
        addRightBoundary(root, res);

        return res;
    }
};
T.C=O(N)
S.C=O(N)
