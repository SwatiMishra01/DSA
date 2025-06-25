https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
---------------------------------------
  APPROACH 1-> USING RECURSION  (TLE)
---------------------------------------
long long int countDerangements(int n) {
    //base case
    if(n==1)
    return 0;
    if(n==2)
    return 1;

    int ans=(n-1)*(countDerangements(n-1)+countDerangements(n-2));
    return ans;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-----------------------------------------------
   APPROACH 2-> MEMIOZATION
------------------------------------------------
#include<vector>
# define MOD 1000000007
long long int solve(int n, vector<long long int>& dp){
//base case
    if(n==1)
    return 0;
    if(n==2)
    return 1;
 if(dp[n]!=-1)
 return dp[n];
    dp[n]=(  ((n-1)% MOD)*( (solve(n-1,dp)% MOD) +(  solve(n-2,dp)% MOD)  ))% MOD;
    return dp[n];
}

long long int countDerangements(int n) {
    vector<long long int> dp(n+1,-1);
    return solve(n,dp);
}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

----------------------------------------------
  APPROACH 3-> USING TABULATION
----------------------------------------------
#include<vector>
# define MOD 1000000007
long long int solve(int n){
    vector<long long int> dp(n+1,0);
//base case
   dp[1]=0;
   dp[2]=1;
for(int i=3; i<=n; i++){
    //  dp[i]=(  ((n-1)% MOD)*( 
    //     (solve(n-1,dp)% MOD) +
    //     (  solve(n-2,dp)% MOD)  )  )% MOD;

    long long int first=dp[i-1]% MOD;
    long long int second=dp[i-2]% MOD;
    long long int sum= (first+second)% MOD;
    long long int ans=((i-1)*sum)% MOD;
    dp[i]=ans;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    
    return solve(n);
}
