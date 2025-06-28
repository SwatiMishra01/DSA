
#  https://www.naukri.com/code360/problems/frog-jump_3621012
--------------------------------------------
    APPROACH-1 -> RECURSION   TLE
--------------------------------------------

#include <bits/stdc++.h> 
int f(int indx, vector<int> &heights){
    if(indx==0)
    return 0;

    int left= f(indx-1,heights)+abs(heights[indx]-heights[indx-1]);
    int right=INT_MAX;
    if(indx >1)
    right= f(indx-2,heights)+abs(heights[indx]-heights[indx-2]);
    return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    return f(n-1,heights);
}



--------------------------------------------------------------------------------------------------------------------------------

    ------------------------------------------------
         APPROACH 2-> MEMOIZATION
    -----------------------------------------------
    #include <bits/stdc++.h> 
int f(int indx, vector<int> &heights,vector<int>&dp){
    if(indx==0)
    return 0;
 if(dp[indx]!=-1)
 return dp[indx];

    int left= f(indx-1,heights,dp)+abs(heights[indx]-heights[indx-1]);
    int right=INT_MAX;
    if(indx >1)
    right= f(indx-2,heights,dp)+abs(heights[indx]-heights[indx-2]);
    return dp[indx]= min(left,right);
}
int frogJump(int n, vector<int> &heights){
    vector<int>dp(n+1,-1);
    return f(n-1,heights,dp);
}
---------------------------------------------------------------------------------------------------------------------------------------------


    --------------------------------------
      APPROACH 3-> TABULATION METHOD
    -------------------------------------

    #include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights){
   vector<int>dp(n,0);
   dp[0]=0;
   for(int i=1; i<n; i++){
       int first_steps=dp[i-1]+abs(heights[i]-heights[i-1]);
       int second_step=INT_MAX;
       if(i>1)
       second_step=dp[i-2]+abs(heights[i]-heights[i-2]);

       dp[i]=min(first_steps,second_step);
   }
 return dp[n-1];
}

