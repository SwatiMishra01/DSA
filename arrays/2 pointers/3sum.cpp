https://leetcode.com/problems/3sum/description/
LEETCODE-15
  class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> result;
        int n = nums.size();
    
    // Sort the array to handle duplicates and use two-pointer technique
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
        
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicates for left and right pointers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++; 
                right--;
            } 
            else if (sum < 0) {
                left++; // Move left pointer to increase sum
            } 
            else {
                right--; // Move right pointer to decrease sum
            }
        }
    }
    
    return result;
    }
};
