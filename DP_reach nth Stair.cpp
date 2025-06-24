# https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

     WITHOUT DP
     -----------
// this will show time limit exceeded as it needs to do recursion again and again
------------------------------------------------------------------------------------------------------------------------------

#define MOD 1000000007
#include <bits/stdc++.h> 

int solve(long long nStairs, int i){ //i=current stairs
//base case
if(i==nStairs)
    return 1;
 if(i>nStairs)
 return 0;
    return (solve(nStairs,i+1))+(solve(nStairs,i+2)) % MOD;
}
int countDistinctWays(int nStairs) {
    int ans=solve(nStairs,0);
    return ans;
}





--------------------------------------------------------------------------------------------------------------------------------------
                                                        USING TABULATION


     class Solution {
public:
    int climbStairs(int n) {
        if(n==0 ||  n==1){
        return 1;
        }

     vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
       }
        return dp[n];
    }
};
  
