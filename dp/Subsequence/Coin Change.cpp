https://leetcode.com/problems/coin-change/description/
LEETCODE-322

  -----------------------------
         RECURSION
  -----------------------------
  class Solution {
public:
   int f(int indx,int  target, vector<int>&coins){
    //base case
    if(indx==0){
        if(target%coins[0]==0)
        return target/coins[0];
        else 
        return 1e9;
    }
    
    //exploring all possibilites
     int not_take=0+f(indx-1,target,coins);
     int take= INT_MAX; //since a min problem so taking max
     if(coins[indx]<=target){
         take=1+f(indx,target-coins[indx],coins);
     }

     return  min(take,not_take);
}
    int coinChange(vector<int> &coins, int amount) {
          int n=coins.size();        
   int ans = f(n-1, amount, coins);
     if (ans >= 1e9) return -1;
     return ans; 
    }
};
T.C=O(2n⋅target)
S.C=O(target)->recursion stack

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------
          MEMOIZATION
  ------------------------------
  class Solution {
public:
   int f(int indx,int  target, vector<int>&coins,vector<vector<int>>&dp){
    //base case
    if(indx==0){
        if(target%coins[0]==0)
        return target/coins[0];
        else 
        return 1e9;
    }
    
    //applying memoization
    if(dp[indx][target]!=-1)
    return dp[indx][target];

    //exploring all possibilites
     int not_take=0+f(indx-1,target,coins,dp);
     int take= INT_MAX; //since a min problem so taking max
     if(coins[indx]<=target){
         take=1+f(indx,target-coins[indx],coins,dp);
     }

     return dp[indx][target]= min(take,not_take);
}
    int coinChange(vector<int> &coins, int amount) {
          int n=coins.size();
          vector<vector<int>>dp(n,vector<int>(amount+1,-1));
   int ans = f(n-1, amount, coins,dp);
     if (ans >= 1e9) return -1;
     return ans; 
    }
};
T.C=O(n⋅amount)
S.C=O(n⋅amount)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------
        TABULATION
  -----------------------------
  class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0; // base case: 0 coins to make amount 0

        for (int i = 0; i < n; i++) {
            for (int t = coins[i]; t <= amount; t++) {
                dp[t] = min(dp[t], 1 + dp[t - coins[i]]);
            }
        }

        return dp[amount] >= 1e9 ? -1 : dp[amount];
    }
};
T.C=O(n * amount)
S.C=O(n * amount)
  
