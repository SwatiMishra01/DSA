https://www.naukri.com/code360/problems/minimal-cost_8180930?utm_source=chatgpt.com&leftPanelTabValue=PROBLEM

--------------------------------------------------------
  APPROACH 1 -> RECURSION    (TLE)
---------------------------------------------------------

int solve(int indx, int k, vector<int> &height){
    //base case
    if(indx==0)
    return 0;

    int min_steps=INT_MAX;
    for(int j=1; j<=k; j++){
        // fs= solve(indx-1)+abs(heights[indx]-heights[indx-1])
        if(indx-j>=0){
        int jump=solve(indx-j,k,height)+abs(height[indx]-height[indx-j]);
        min_steps=min(min_steps,jump);
        }
    }
    return min_steps;
    
}

int minimizeCost(int n, int k, vector<int> &height){
    return solve(n-1,k,height);
}

---------------------------------------------------------------------------------------------------------------------------------

  ---------------------------------------------
   APPROACH 2-> MEMOIZATION
  ---------------------------------------------

  int solve(int indx, int k, vector<int> &height,vector<int>dp){
   if(indx==0)
   return 0;

    int min_steps=INT_MAX;
    if(dp[indx]!=-1)
    return dp[indx];
    for(int j=1; j<=k; j++){
        // fs= solve(indx-1)+abs(heights[indx]-heights[indx-1])
        if(indx-j>=0){
        int jump=solve(indx-j,k,height,dp)+abs(height[indx]-height[indx-j]);
        min_steps=min(min_steps,jump);
        }
    }
    return dp[indx]=min_steps;
    
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n+1,-1);
    return solve(n-1,k,height,dp);
}
----------------------------------------------------------------------------------------------------------------------------------------------

  -----------------------------------------
    APPROACH 3-> TABULATION                               T.C=O(n*k)   S.C=O(n)
  ------------------------------------------

  
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n,0);
  dp[0]=0;
 
for(int i=1; i<n; i++){
   int min_steps=INT_MAX;
   for(int j=1; j<=k; j++){
     if(i-j>=0){
        int jump=dp[i-j]+abs(height[i]-height[i-j]);
        min_steps=min(min_steps,jump);
        }
    }
    dp[i]=min_steps;
    }
    return dp[n-1];
}

--------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------------------
           SPACE OPTIMIZATION
  -----------------------------------------

  //NOTE:✅  This works only when k = 2, since you just need last 2 values.

int minimizeCost(int n, int k, vector<int> &height) {
    if (n == 1) return 0;

    int prev = 0;  // dp[i-1]
    int prev2 = 0; // dp[i-2]
    int curr = 0;

    for (int i = 1; i < n; i++) {
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        int jumpTwo = INT_MAX;
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        curr = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = curr;
    }

    return curr;
}
