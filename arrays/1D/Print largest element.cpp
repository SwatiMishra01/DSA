--------------------------------------------------------------
  APPROACH 1-> BRUTE FORCE (sorting & printing last element)
  -------------------------------------------------------------
  class Solution {
public:
    int largestElement(vector<int>& nums) {
        int n=nums.size();
 sort(nums.begin(),nums.end());
 return nums[n-1];
    }
};

TC=O(N LOG N)
  SC=O(1)
--------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------------
    APPROACH 2-> RECURSION
  ----------------------------------------------
  class Solution {
public:
    int largestElement(vector<int>& nums) {
        int n=nums.size();
        int max = nums[0];
  for (int i = 0; i < n; i++) {
    if (max < nums[i]) {
      max = nums[i];
    }
  }
  return max;
    }
};
Time Complexity: O(N)
Space Complexity: O(1)
