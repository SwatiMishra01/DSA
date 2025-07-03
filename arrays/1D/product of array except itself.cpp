
leetcode-
  class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int> result(n, 1);

    // Step 1: Calculate the prefix product for each element
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    // Step 2: Calculate the suffix product and update the result array
    int suffix = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffix *= nums[i + 1];
        result[i] *= suffix;
    }

    return result;
    }
};
T.C=O(N)
S.C=O(N)

  -------------------------
    OPTIMAL
  --------------------------
  class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // 1. Compute prefix products in result array
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        // 2. Compute suffix product on the fly and multiply
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};
T.C=O(N)
S.C=O(1) //result output array doesn’t count.
