-------------------------------
      RECURSION-TLE
-----------------------------
  class Solution {
    private:
    int f(int indx, int prev_indx,vector<int>& nums){
        int n=nums.size();
        //base case
        if(indx==n) return 0;
        int len=0;

        //not take
        int len1=0+f(indx+1,prev_indx,nums);
        //take
        int len2 = INT_MIN;
        if(prev_indx==-1 || nums[indx]>nums[prev_indx]){
            len2=1+f(indx+1,indx,nums);
        }
        return len=max(len1,len2);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return f(0,-1,nums);
    }
};
T.C=O(2^N)
S.C=O(N)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------
       MEMOIZATION
  ---------------------
  class Solution {
    private:
    int f(int indx, int prev_indx,vector<int>& nums,vector<vector<int>>&dp){
        int n=nums.size();
        //base case
        if(indx==n) return 0;
         
         //memoization
         if(dp[indx][prev_indx+1]!=-1) return dp[indx][prev_indx+1];

        //not take
        int len1=0+f(indx+1,prev_indx,nums,dp);
        //take
        int len2 = INT_MIN;
        if(prev_indx==-1 || nums[indx]>nums[prev_indx]){
            len2=1+f(indx+1,indx,nums,dp);
        }
        return dp[indx][prev_indx+1]=max(len1,len2);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};
T.C=O(N^2)
S.C=O(N^2)
---------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------
         TABULATION
  ------------------------------
  class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // dp[indx][prev_indx+1] = LIS length starting at indx with prev_indx
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Traverse from back to front
        for (int indx = n - 1; indx >= 0; indx--) {
            for (int prev_indx = indx - 1; prev_indx >= -1; prev_indx--) {

                // Not take
                int len1 = dp[indx + 1][prev_indx + 1];

                // Take
                int len2 = 0;
                if (prev_indx == -1 || nums[indx] > nums[prev_indx]) {
                    len2 = 1 + dp[indx + 1][indx + 1];
                }

                dp[indx][prev_indx + 1] = max(len1, len2);
            }
        }

        return dp[0][0]; // Starting from index 0 with prev_indx = -1
    }
};
T.C=O(N^2)
S.C=O(N^2)
  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        --------------------------------
          USING BINARY SEARCH
        -------------------------------
        class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub; 

        for (int num : nums) {
            // Find the position where num can be placed
            auto it = lower_bound(sub.begin(), sub.end(), num);

            if (it == sub.end()) {
                sub.push_back(num);
            } else {
                // Replace the first element >= num
                *it = num;
            }
        }

        return sub.size(); 
    }
};
T.C=	O(n log n)
S.C=O(N)
