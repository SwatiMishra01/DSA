https://www.naukri.com/code360/problems/subset-sum-equals-k_1550954?leftPanelTabValue=PROBLEM

---------------------------------------------
   APPROACH 1-> RECURSION   (TLE)
---------------------------------------------
#include <bits/stdc++.h> 
int f(int i, int target,vector<int> &arr){
    // base cases
    if(target==0)
    return true;


    if(i==0)
    return (arr[0]==target);

    bool not_take= f(i-1,target,arr);
    bool take=false;
    if(target>=arr[i])
    take=f(i-1,target-arr[i],arr);


    return (take || not_take);

}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1,k,arr); 
 
}
T.C= O(2^n)
S.C=O(n)
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  ------------------------------------------------
     APPROACH 2-> MEMOIZATION
  ------------------------------------------------
  
  #include <bits/stdc++.h> 
int f(int i, int target,vector<int> &arr,vector<vector<int>>&dp){
    // base cases
    if(target==0)
    return true;


    if(i==0)
    return (arr[0]==target);

    if(dp[i][target]!=-1)
    return dp[i][target];

    bool not_take= f(i-1,target,arr,dp);
    bool take=false;
    if(target>=arr[i])
    take=f(i-1,target-arr[i],arr,dp);


    return dp[i][target]=(take || not_take);

}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp); 
 
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------
     APPROACH 3-> TABULATION
  ----------------------------------------
  #include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base Case 1: target == 0 -> always true
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base Case 2: first element
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool not_take = dp[i - 1][target];
            bool take = false;
            if (target >= arr[i])
                take = dp[i - 1][target - arr[i]];

            dp[i][target] = take || not_take;
        }
    }

    return dp[n - 1][k];
}

T.C=O(N*K)
S.C=O(N*K)
