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
  
