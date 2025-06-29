https://leetcode.com/problems/coin-change-ii/description/?envType=problem-list-v2&envId=dynamic-programming
LEETCODE -518

--------------------------------
 APPROACH 1-> RECURSION (TLE)
-------------------------------
class Solution {
public:

int f(int indx, int target, vector<int>&coins){
    //base cases
    if(indx==0){
        if(target%coins[0]==0)
        return 1;
        else
        return false;
    }

    //explorinf all possible paths
    int not_take=f(indx-1,target,coins);
    int take=0;
    if(coins[indx]<=target)
    take=f(indx,target-coins[indx],coins);


    return take+not_take;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return f(n-1,amount,coins);
    }
};

TC: O(2^n * target)  
 SC: O(n) + O(target)
---------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------
  APPROACH 2-> MEMOIZATION
  --------------------------------------
  class Solution {
public:

int f(int indx, int target, vector<int>&coins,vector<vector<int>>&dp){
    //base cases
    if(indx==0){
        if(target%coins[0]==0)
        return 1;
        else
        return false;
    }

    //memoization
    if(dp[indx][target]!=-1)
    return dp[indx][target];

    //explorinf all possible paths
    int not_take=f(indx-1,target,coins,dp);
    int take=0;
    if(coins[indx]<=target)
    take=f(indx,target-coins[indx],coins,dp);


    return dp[indx][target]= take+not_take;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};
TC: O(n * target)  
SC: O(n * target) + O(n)
--------------------------------
  APPROACH 3-> TABULATION
  ------------------------------

  class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //base cases
        for(int t=0; t<=amount; t++){
            dp[0][t]=(t%coins[0]==0);
        }

        //nested loops for changing parameters
        for(int indx=1; indx<n; indx++){
            for(int t=0; t<=amount; t++){

                //recursiopn
    long not_take=dp[indx-1][t];
    long take=0;
    if(coins[indx]<=t)
    take=dp[indx][t-coins[indx]];


    dp[indx][t]= take+not_take;
            }
        }
        return dp[n-1][amount];
    }
};
TC: O(n * target)  
SC: O(n * target)
----------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------
   APPROACH 4-> SPACE OPTIMIZATION
  -------------------------------------
  class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);

        // Base case: using only coins[0]
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) prev[t] = 1;
        }

        // Tabulation with space optimization
        for (int indx = 1; indx < n; indx++) {
            vector<int> curr(amount + 1, 0);
            for (int t = 0; t <= amount; t++) {
                long not_take = prev[t];
                long take = 0;
                if (coins[indx] <= t)
                    take = curr[t - coins[indx]];

                curr[t] = take + not_take;
            }
            prev = curr;
        }

        return prev[amount];
    }
};

 TC: O(n * target)  
 SC: O(target)
