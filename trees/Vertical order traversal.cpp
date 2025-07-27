https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
LEETCODE-987
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        // Queue to store {node, {horizontal_distance, level}} which is key here  .  we definitely need that
        queue<pair<TreeNode*, pair<int, int>>> q;
        // Nested map: {HD -> {level -> multiset of values}}

        //we use multiset so that the elements are ordered as well as contains repitations
        map<int, map<int,multiset<int>>> nodes;

        
        q.push({root, {0, 0}}); // Root at HD=0, Level=0
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            
            int hd = pos.first, level = pos.second;
            nodes[hd][level].insert(node->val);

            if (node->left) q.push({node->left, {hd - 1, level + 1}});
            if (node->right) q.push({node->right, {hd + 1, level + 1}});
        }
        vector<vector<int>> ans;
        for (auto &[hd,levels] : nodes) {
            vector<int> col;
            //auto &[hd, levels]: This is structured binding that unpacks the key-value pair from the map.
//auto& ensures you're accessing the elements by reference, not making copies.
//hd becomes an alias for the map's key (e.g., horizontal distance).
//levels becomes an alias for the corresponding vector of values.
            for (auto &[level, values] : levels) {
                col.insert(col.end(), values.begin(), values.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
T.C: O(N * log2N * log2N * log2N)
-> Postorder Traversal performed using BFS as a time complexity of O(N) as we are visiting each and every node once.
-> Multiset Operations to insert overlapping nodes at a specific vertical and horizontal level also takes O(log2N) complexity.
-> Map operations involve insertion and retrieval of nodes with their vertical and level as their keys. Since there are two nested maps, the total time complexity becomes O(log2N)*O(log2N).

S.C: O(N + N/2) 
-> The map for storing nodes based on their vertical and level information occupies an additional space complexity of O(N) as it stores all N nodes of the Binary Tree.
-> The queue for breadth first traversal occupies a space proportional to the maximum level of the tree which can be O(N/2) in the worst case of a balanced tree.
