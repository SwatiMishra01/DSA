https://leetcode.com/problems/unique-binary-search-trees/description
LEETCODE-96

// Step 1: Initialize an array to store results
// Step 2: Loop through each number of nodes from 2 to n
// Step 3: Initialize a variable to calculate the total number of trees
// Step 4: Loop through each possible root position
// Step 5: Calculate the number of BSTs for the current root
// Step 6: Store the result for the current number of nodes

class Solution {
public:
    int numTrees(int n) {
        //step-1
        vector<int> uniqTree(n + 1, 1);

         //step-2
        for (int nodes = 2; nodes <= n; nodes++) {
        //step-3
            int total = 0;
        //step-4
            for (int root = 1; root <= nodes; root++) {
        //step-5
                total += uniqTree[root - 1] * uniqTree[nodes - root];
            }
            //step-6
            uniqTree[nodes] = total;
        }

        return uniqTree[n];
    }
};
T.C=O(N*N)
S.C=O(N)
