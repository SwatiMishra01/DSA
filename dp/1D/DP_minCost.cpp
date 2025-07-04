# https://leetcode.com/problems/min-cost-climbing-stairs/
---------------------------------------------------------------------------------------------------

   --------------------------------------------------------
                  APPROACH 1-> RECURSION (TLE)
  --------------------------------------------------------
  class Solution {
public:
int solve(vector<int>& cost, int n){
    //base case
    if(n==0)
    return cost[0];
    if(n==1)
    return cost[1];
 //recursion approach
    int ans=min(solve(cost,n-1),solve(cost,n-2))+cost[n];
    return ans;
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=min (solve(cost,n-1), solve(cost,n-2));
        return ans;    }
};


-----------------------------------------------------------------------------------------------------------------------------------------------------------
  
  ---------------------------------------------------------
  APPROACH 2-> RECURSION + MEMIOZATION  (TOP-DOWN APPROACH)
  ---------------------------------------------------------

  
  class Solution {
public:
int solve2(vector<int>& cost,int n,vector<int>&dp){
    //base case
    if(n==0)
    return cost[0];

    if(n==1)
    return cost[1];

    //step 3
    if(dp[n]!=-1)
    return dp[n];

   //step 2
     dp[n]=cost[n]+min(  solve2(cost,n-1,dp)   ,    solve2(cost,n-2,dp)  );
    return dp[n];
}




    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //step 1
       vector<int>dp(n,-1);
       int ans=min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
       return ans;
    }
};
----------------------------------------------------------------------------------------------------------------------------------------------------

  ---------------------------------------------
  APPROACH 3-> TABULATION  (BOTTOM UP APPROACH)
  ---------------------------------------------
  class Solution {
public:
int solve3(vector<int>& cost, int n){
    //step 1 -> creation of dp array
    vector<int>dp(n+1);

    //step 2 -> base case analyze
    dp[0]=cost[0];
    dp[1]=cost[1];

    //step 3-> 
    //0 & 1 case handled...bacha kya? 2 to n-1 cases
    for(int i=2; i<n; i++){
        dp[i]=cost[i]+ min(dp[i-1],dp[i-2]);
        
    }
    return min(dp[n-1],dp[n-2]);

}



    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       return solve3(cost,n);
    }
};
------------------------------------------------------------------------------------------------------------------

       

  
