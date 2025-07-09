https://leetcode.com/problems/binary-subarrays-with-sum/description/
LEETCODE-930

  -----------------
   OPTIMAL SOLUTION
  ------------------
  class Solution {
public:
 int f(vector<int>& nums, int goal){
    int l=0;
    int cnt=0;
    int sum=0;

    for(int r=0; r<nums.size(); ++r){
        sum+=nums[r];
        while(l<=r && sum>goal){
            sum-=nums[l];
            l++;
        }
        cnt+=(r-l+1);
    }
    return cnt;
 }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // edge case
        return f(nums, goal) - f(nums, goal - 1);
    }
};

T.C=O(N)
S.C=O(1)
