https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
LEETCODE-309

-----------------------------------
         RECURSION-TLE
-------------------------------------
class Solution {
     private:
    int f(int indx, int buy,vector<int>& prices){
        int n=prices.size();
        if(indx>=n) return 0;
        int profit=0;

        if(buy){
                        //take                    //not take
            profit=max(-prices[indx]+f(indx+1,0,prices), 0+f(indx+1,1,prices));

        }
        else{ 
                      //take                    //not take
           profit=max(prices[indx]+f(indx+2,1,prices), 0+f(indx+1,0,prices));
        }
       return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
          int n=prices.size();
        return f(0,1,prices);
    }
};


  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------
         MEMOIZATION
-------------------------------------
class Solution {
     private:
    int f(int indx, int buy,vector<int>& prices,vector<vector<int>>&dp){
        int n=prices.size();
        if(indx>=n) return 0;
        int profit=0;

        //applying memoization
        if(dp[indx][buy]!=-1) return dp[indx][buy];

        if(buy){
                        //take                    //not take
            profit=max(-prices[indx]+f(indx+1,0,prices,dp), 0+f(indx+1,1,prices,dp));

        }
        else{ 
                      //take                    //not take
           profit=max(prices[indx]+f(indx+2,1,prices,dp), 0+f(indx+1,0,prices,dp));
        }
       return  dp[indx][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
          int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};


  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------
         TABULATION
-------------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
      
      int profit=0;
      for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], prices[ind] + dp[ind + 2][0]);
            }

            dp[ind][buy] = profit;
    }
      }
      return dp[0][0];
    }
};


  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------
         SPACE OPTIMIZATION
-------------------------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
    
    // Initialize three arrays to track the maximum profit for buying and selling
    vector<int> cur(2, 0);       // Current maximum profit
    vector<int> front1(2, 0);    // Maximum profit one step ahead
    vector<int> front2(2, 0);    // Maximum profit two steps ahead
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + front1[0], -prices[ind] + front1[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + front1[1], prices[ind] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        // Update the 'front1' and 'front2' arrays with current values
        front2 = front1;
        front1 = cur;
    }
    
    return cur[0];
    }
};

  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
