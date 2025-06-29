https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0
LLETCODE-322

----------------------------------
  APPROACH 1-> RECURSION (TLE)
----------------------------------
  #include <bits/stdc++.h>
int f(int indx,int  target, vector<int>&num){
    //base case
    if(indx==0){
        if(target%num[0]==0)
        return target/num[0];
        else 
        return 1e9;
    }

    //exploring all possibilites
     int not_take=0+f(indx-1,target,num);
     int take= INT_MAX; //since a min problem so taking max
     if(num[indx]<=target){
         take=1+f(indx,target-num[indx],num);
     }

     return min(take,not_take);
} 
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
   int ans = f(n-1, x, num);
     if (ans >= 1e9) return -1;
     return ans;
}

TC = O(2^n * target)
SC = O(target)
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------

  ---------------------------
   APPROACH 2-> MEMOIZATION
  ---------------------------
    #include <bits/stdc++.h>
int f(int indx,int  target, vector<int>&num,vector<vector<int>>&dp){
    //base case
    if(indx==0){
        if(target%num[0]==0)
        return target/num[0];
        else 
        return 1e9;
    }

    //applying memoization
    if(dp[indx][target]!=-1)
    return dp[indx][target];

    //exploring all possibilites
     int not_take=0+f(indx-1,target,num,dp);
     int take= INT_MAX; //since a min problem so taking max
     if(num[indx]<=target){
         take=1+f(indx,target-num[indx],num,dp);
     }

     return dp[indx][target]= min(take,not_take);
} 
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
   int ans = f(n-1, x, num,dp);
     if (ans >= 1e9) return -1;
     return ans;
}

TC = O(n * target)
SC = O(n * target) + O(target)


  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  -----------------------------------
   APPROACH 3-> TABULATION
  ------------------------------------
    #include <bits/stdc++.h>


int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    // DP table banao: dp[indx][target] = minimum coins to make 'target' using coins[0...indx]
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    // Base case: sirf pehla coin available hai
    for (int t = 0; t <= x; t++)
    {
        if (t % num[0] == 0)
            dp[0][t] = t / num[0]; // agar divisible hai toh coins ka count
        else
            dp[0][t] = INT_MAX;    // nahi ban sakta toh infinity
    }

    // DP loops: baki coins ke liye
    for (int indx = 1; indx < n; indx++)
    {
        for (int t = 0; t <= x; t++)
        {
            // Option 1: current coin na lo
            int not_take = dp[indx - 1][t];

            // Option 2: current coin lo (agar possible ho)
            int take = INT_MAX;
            if (num[indx] <= t && dp[indx][t - num[indx]] != INT_MAX)
            {
                take = 1 + dp[indx][t - num[indx]];
            }

            // Minimum coins dono options mein se
            dp[indx][t] = min(take, not_take);
        }
    }

    // Final answer
    int ans = dp[n - 1][x];
    if (ans >= INT_MAX)
        return -1;  // agar ban nahi sakta toh -1
    return ans;
}
TC = O(n * target)
SC=O(n * target)
