https://leetcode.com/problems/minimum-size-subarray-sum/description/
LEETCODE-209

  -------------------------------------------
         2 POINTERS+ PREFIX SUM
  -------------------------------------------
  class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int l=0;
        int sum=0;
        for(int r=0; r<n; r++){
            sum+=nums[r];
            while(sum>=target){
                sum-=nums[l];
                ans=min(ans,r-l+1);
                l++;
            }

        }
        if(ans!=INT_MAX)
        return ans;


        return 0;
        
    }
};
T.C=O(N)
S.C=O(1)
