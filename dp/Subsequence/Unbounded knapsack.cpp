----------------------------------------------------
 APPROACH 1-> RECURSION (TLE)
-------------------------------------------------------

int f(int indx,int wt, vector<int> &weight, vector<int> &profit ){
    //base case
    if(indx==0)
    return (wt/weight[0])*profit[0];

    //exploring all possibilities
    int not_take=0+f(indx-1,wt,weight,profit);
    int take=0;
    if(weight[indx]<=wt)
    take=profit[indx]+f(indx,wt-weight[indx],weight,profit);

    return max(take,not_take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return f(n-1,w,weight,profit);
}


T.C=O(2^n * W)
S.C=O(W)+O(N)
--------------------------------------------------------------------------------------------------------------------------
--------------------------------------------
   APPROACH 2-> MEMOIZATION
--------------------------------------------
int f(int indx,int wt, vector<int> &weight, vector<int> &profit,vector<vector<int>>&dp ){
    //base case
    if(indx==0)
    return (wt/weight[0])*profit[0];

    //memoization
    if(dp[indx][wt]!=-1)
    return dp[indx][wt];

    //exploring all possibilities
    int not_take=0+f(indx-1,wt,weight,profit,dp);
    int take=0;
    if(weight[indx]<=wt)
    take=profit[indx]+f(indx,wt-weight[indx],weight,profit,dp);

    return dp[indx][wt]=max(take,not_take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return f(n-1,w,weight,profit,dp);
}
TC: O(N * W)
SC: O(N * W)+O(N)
----------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------
 APPROACH 3-> TABULATION
------------------------------------
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    //base case
    for(int wt=0; wt<=w; wt++){
        dp[0][wt]=(wt/weight[0])*profit[0];
    }

    //nested loops for indx and wt

    for(int indx=1; indx<n; indx++){
        for(int wt=0; wt<=w; wt++){
            
    //exploring all possibilities
    int not_take=0+dp[indx-1][wt];
    int take=0;
    if(weight[indx]<=wt)
    take=profit[indx]+dp[indx][wt-weight[indx]];

     dp[indx][wt]=max(take,not_take);

        }
    }
    return dp[n-1][w];
}

T.C=O(N * W)
S.C=O(N * W)
 ------------------------------------------------------------------------------------------------------------------------------------------------------------
 ---------------------------------------
  APPROACH 4-> SPACE OPTIMIZATION
---------------------------------------------
 // dp[indx][wt] = max(
//    dp[indx - 1][wt],          // not_take ? previous row
//    profit[indx] + dp[indx][wt - weight[indx]] // take ? same row
// );


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
        vector<int> dp(w + 1, 0);

   // Base case: fill dp[] for item 0
    for (int wt = 0; wt <= w; wt++) {
        dp[wt] = (wt / weight[0]) * profit[0];
    }

    for (int indx = 1; indx < n; indx++) {
        for (int wt = 0; wt <= w; wt++) {
            int not_take = dp[wt];
            int take = 0;
            if (weight[indx] <= wt)
                take = profit[indx] + dp[wt - weight[indx]]; // same dp[] because it's unbounded
            dp[wt] = max(not_take, take);
        }
    }

    return dp[w];
}

T.C=O(N * W)
 S.C=O(N )
