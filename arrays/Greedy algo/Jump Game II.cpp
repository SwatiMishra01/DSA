https://leetcode.com/problems/jump-game-ii/description/
LEETCODE-45


----------------------------------------------
  APPROACH 1-> RECURSION (TLE)
  ------------------------------------------------
  class Solution {
public:
int f(vector<int>& nums, int indx,int jump){
    int n=nums.size();
    if(indx>=n-1)
    return jump;
     
     int mini=INT_MAX;
    for(int i=1; i<=nums[indx]; i++){
        mini=min(mini,f(nums,indx+i,jump+1));
    }
    return mini;
}
    int jump(vector<int>& nums) {
        return f(nums,0,0);
    }
};

T.C=O(N^N)
S.C=O(N)- auxillary stack space


-----------------------------------------------------
   APPROACH 2-> MEMOIZATION
-----------------------------------------------------
  class Solution {
public:
    int f(vector<int>& nums, int indx, int jump, vector<int>& dp) {
        int n = nums.size();
        if (indx >= n - 1) return jump;
        

        //memoization
        if (dp[indx] != -1) return dp[indx] + jump;

        int mini = INT_MAX;

        for (int i = 1; i <= nums[indx]; i++) {
            mini = min(mini, f(nums, indx + i, jump + 1, dp));
        }

        dp[indx] = mini - jump;  // store only the remaining jumps needed from indx

        return mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(nums, 0, 0, dp);
    }
};
T.C=O(N^2)
S.C=O(N^2)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------
  APPROACH 3-> TABULATION
  ---------------------------------------
  class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);

        dp[n - 1] = 0; // last index to end needs 0 jumps

        for (int i = n - 2; i >= 0; i--) {
            int steps = nums[i];
            for (int j = 1; j <= steps && i + j < n; j++) {
                if (dp[i + j] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i + j]);
                }
            }
        }

        return dp[0];
    }
};
T.C=O(N^2)
S.C=O(N)


  
  
