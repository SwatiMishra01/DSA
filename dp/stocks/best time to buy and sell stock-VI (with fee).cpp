https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
LEETCODE-714
-----------------------------
       RECURSION-TLE
-----------------------------
class Solution {
    private:
    int f(int indx, int buy,vector<int>& prices,int &fee){
        int n=prices.size();
        if(indx==n) return 0;
        int profit=0;

        if(buy){
                        //take                    //not take
            profit=max(-prices[indx]+f(indx+1,0,prices,fee), 0+f(indx+1,1,prices,fee));

        }
        else{ 
                      //take                    //not take
           profit=max((prices[indx]-fee)+f(indx+1,1,prices,fee), 0+f(indx+1,0,prices,fee));
        }
       return  profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        return f(0,1,prices,fee);
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------
       MEMOIZATION
-----------------------------
class Solution {
    private:
    int f(int indx, int buy,vector<int>& prices,vector<vector<int>>&dp,int &fee){
        int n=prices.size();
        if(indx==n) return 0;
        int profit=0;

        //applying memoization
        if(dp[indx][buy]!=-1) return dp[indx][buy];

        if(buy){
                        //take                    //not take
            profit=max(-prices[indx]+f(indx+1,0,prices,dp,fee), 0+f(indx+1,1,prices,dp,fee));

        }
        else{ 
                      //take                    //not take
           profit=max((prices[indx]-fee)+f(indx+1,1,prices,dp,fee), 0+f(indx+1,0,prices,dp,fee));
        }
       return  dp[indx][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp,fee);
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------
      TABULATION
-----------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        //base case 
      dp[n][0] = dp[n][1] = 0;
      int profit=0;
      for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], prices[ind]-fee + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
    }
      }
      return dp[0][0];
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------
      SPACE OPTIMIZATION
-----------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        // Create two arrays to store the profits ahead of the current position (0 for not holding, 1 for holding)
    vector<long> ahead(2, 0);
    vector<long> cur(2, 0);

   
    ahead[0] = ahead[1] = 0;

    int profit;

    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -prices[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], prices[ind]-fee + ahead[0]);
            }
            cur[buy] = profit;
        }

        ahead = cur; // Update the "ahead" array with the current values
    }

   
    return cur[0];
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
