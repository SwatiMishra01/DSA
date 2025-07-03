https://leetcode.com/problems/find-the-duplicate-number/description/
leetcode-287

  --------------
  USING SORTING
  --------------
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans=-1;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      ans= nums[i];
    }
    }
    return ans;
  }
};
T.C=O(N LOG N)+O(N)
S.C=O(1)

  -----------------
  USING FREQ ARRAY
  ----------------
  class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans=-1;
   vector<int> freq(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (freq[nums[i]] == 0) 
      freq[nums[i]] += 1;
     else 
     ans= nums[i];
  
    }
    return ans;
  }
};
T.C=O(N)
S.C=O(N)



  
