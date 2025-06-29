
--------------------------------------------
 APPROACH 1-> RECURSION  (TLE)
----------------------------------------------
#include <bits/stdc++.h> 
int f(int indx,int maxWeight,vector<int> &weight,vector<int> &value){
	//base cases
	if(indx==0){
		if(weight[indx]<=maxWeight)
		return value[0];
		else
		return 0;
	}


	//explore all possibilities
	int not_take=0+f(indx-1,maxWeight,weight,value);
	int take=INT_MIN; //since it is max porblem so it will nto choose this path
	if(weight[indx]<=maxWeight)
	take= value[indx]+f(indx-1,maxWeight-weight[indx],weight,value);


	//return max
	return max(take,not_take);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
 return f(n-1,maxWeight,weight,value);
}

TC: O(2^N)
SC: O(N)
----------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------
	APPROACH 2-> MEMOIZATION
---------------------------------------
	#include <bits/stdc++.h> 
int f(int indx,int maxWeight,vector<int> &weight,vector<int> &value,vector<vector<int>>&dp){
	//base cases
	if(indx==0){
		if(weight[indx]<=maxWeight)
		return value[0];
		else
		return 0;
	}

//memoization
if(dp[indx][maxWeight]!=-1)
return  dp[indx][maxWeight];

	//explore all possibilities
	int not_take=0+f(indx-1,maxWeight,weight,value,dp);
	int take=INT_MIN; //since it is max porblem so it will nto choose this path
	if(weight[indx]<=maxWeight)
	take= value[indx]+f(indx-1,maxWeight-weight[indx],weight,value,dp);


	//return max
	return dp[indx][maxWeight]=max(take,not_take);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
 return f(n-1,maxWeight,weight,value,dp);
}

TC: O(N * W)
SC: O(N * W)+O(N)
----------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------
  APPROACH 3->TABULATION
-----------------------------------------
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
 
    // Base Case: fill first row
    for (int w = weight[0]; w <= maxWeight; w++) {
        dp[0][w] = value[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            int not_take = dp[i - 1][w];
            int take = INT_MIN;
            if (weight[i] <= w) {
                take = value[i] + dp[i - 1][w - weight[i]];
            }
            dp[i][w] = max(take, not_take);
        }
    }

    return dp[n - 1][maxWeight];
}
TC: O(N * W)
SC: O(N * W)
-------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------
   APPROACH 4-> SPACE OPTIMIZATION
------------------------------------------------------
	#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
     vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);

    // Base case: initialize prev for item 0
    for (int w = weight[0]; w <= maxWeight; w++) {
        prev[w] = value[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {    //for (int w = maxWeight; w >=0; w--)   this line also works.....why?
            int not_take = prev[w];               //                                      because it only depends on prev row...not previous values
            int take = INT_MIN;
            if (weight[i] <= w) {
                take = value[i] + prev[w - weight[i]];
            }
            curr[w] = max(take, not_take);
        }
        prev = curr; // move to next item
    }

    return prev[maxWeight];
}
TC: O(N * W)
SC: O(W)

--------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------
	APPROACH 5->using a single array
-------------------------------------------------
	#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
     vector<int> prev(maxWeight + 1, 0);

     // Base case: initialize for the first item
    for (int w = weight[0]; w <= maxWeight; w++) {
        prev[w] = value[0];
    }

    for (int i = 1; i < n; i++) {
        // Reverse loop for single array trick
        for (int w = maxWeight; w >= 0; w--) {
            int not_take = prev[w];
            int take = INT_MIN;
            if (weight[i] <= w) {
                take = value[i] + prev[w - weight[i]];
            }
            prev[w] = max(take, not_take);
        }
    }

    return prev[maxWeight];
}
TC = O(N * W)
SC = O(W)
