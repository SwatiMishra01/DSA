https://leetcode.com/problems/minimum-size-subarray-sum/description/
LEETCODE-209
-------------------
   BRUTE FORCE (TLE)
-------------------
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minLength=INT_MAX;
        for(int i=0; i<n; i++){
             int sum=0;
            for(int j=i; j<n; j++){
                 sum+=nums[j];
                 if(sum>=target){
                 minLength=min(minLength,j-i+1);
                 break;
                 }
            }
        }
        if(minLength!=INT_MAX){
        return minLength;
        }
        return 0;
    }
};

T.C=O(N^2)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------------
                SLIDING WINDOW
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

T.C=O(N^2)
S.C=O(1)
