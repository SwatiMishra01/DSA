https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
LEETCODE-123


----------------------
   RECURSION-TLE
----------------------
class Solution {
    private:
    int f(int indx,int buy, int cap,vector<int>& prices){
         int n=prices.size();
        //base cases
        if(indx==n) return 0;
        if(cap==0) return 0;


        int profit=0;
        if(buy){
            profit=max(-prices[indx]+f(indx+1,0,cap,prices), 0+f(indx+1,1,cap,prices));
        }
        else{
            profit=max(prices[indx]+f(indx+1,1,cap-1,prices), 0+f(indx+1,0,cap,prices));
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        return f(0,1,2,prices);
    }
};
T.C=O(2^N)
S.C=O(N)-> auxially stack space
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------
     MEMOIZATION
  -----------------------
class Solution {
    private:
    int f(int indx,int buy, int cap,vector<int>& prices,vector<vector<vector<int>>>&dp){
         int n=prices.size();
        //base cases
        if(indx==n) return 0;
        if(cap==0) return 0;

        //memoization
        if(dp[indx][buy][cap]!=-1) return dp[indx][buy][cap];


        int profit=0;
        if(buy){
            profit=max(-prices[indx]+f(indx+1,0,cap,prices,dp), 0+f(indx+1,1,cap,prices,dp));
        }
        else{
            profit=max(prices[indx]+f(indx+1,1,cap-1,prices,dp), 0+f(indx+1,0,cap,prices,dp));
        }
        return dp[indx][buy][cap]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0,1,2,prices,dp);
    }
};
T.C=O(2*3*N)
S.C=O(2*3*N)
 -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------
     TABULATION
  -----------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                           -prices[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                           prices[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
    return dp[0][0][2];
       
    }
};
T.C=O(2*3*N)
S.C=O(2*3*N)
 -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------
   SPACE OPTIMIZATION
  --------------------------
  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { // We can buy the stock
                    cur[buy][cap] = max(0 + ahead[0][cap], 
                                        -prices[ind] + ahead[1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap],
                                        prices[ind] + ahead[0][cap - 1]);
                }
            }
        }
        // Update the ahead state with the current state for the next iteration.
        ahead = cur;
    }

    return ahead[0][2];
    }
};
T.C=O(2*3*N)
S.C=O(1)
