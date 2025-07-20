https://leetcode.com/problems/4sum/description/
LEETCODE-18
  
class Solution {
public:
    // Helper function to find the remaining 2 numbers in the quadruplet
    void twoSum(vector<int>& nums, int targetSum, int first, int second, vector<vector<int>>& quads) {
        int start = second + 1;
        int end = nums.size() - 1;

        while (start < end) {
            long long sum = (long long)nums[first] + nums[second] + nums[start] + nums[end];

            if (sum == targetSum) {
                // Found a valid quadruplet
                quads.push_back({nums[first], nums[second], nums[start], nums[end]});
                start++;
                end--;

                // Skip duplicates for the 3rd element
                while (start < end && nums[start] == nums[start - 1]) {
                    start++;
                }

                // Skip duplicates for the 4th element
                while (start < end && nums[end] == nums[end + 1]) {
                    end--;
                }

            } else if (sum < targetSum) {
                // Increase sum by moving start forward
                start++;
            } else {
                // Decrease sum by moving end backward
                end--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quads;

        // Sort array to make skipping duplicates and two-pointer logic work
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // First number
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate first numbers
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Second number
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate second numbers
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Call helper for remaining 2 numbers
                twoSum(nums, target, i, j, quads);
            }
        }

        return quads;
    }
};
