https://leetcode.com/problems/permutations/description/
LEETCODE-46
  
---------------------
  BRUTE FORCE-RECURSION
---------------------
  class Solution {
public:
void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector < vector < int >> ans;
      vector < int > ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, ans, freq);
      return ans;
    }
};
T.C=O(N! x N)
S.C=O(N)


  ------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------
  OPTIMAL- WITH BACKTRACKING
  ----------------------------
  class Solution {
public:
void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector < vector < int >> ans;
      recurPermute(0, nums, ans);
      return ans;
    }
};
T.C=O(N! X N)
S.C=O(1)
