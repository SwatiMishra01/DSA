# https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

--------------------
USING ONLY RECURSION
---------------------

-->this code will run all test cases but wll show time limit exceeded (exponential T.C)

#include <bits/stdc++.h> 

int solveRecursion(vector<int> &num, int x){
    //base case
    if(x==0)
    return 0 ;
    if(x<0)
    return INT_MAX;


    int mini=INT_MAX;
    for(int i=0;i<num.size(); i++){
        int ans=solveRecursion(num, x-num[i]);
        if(ans!=INT_MAX)
        //update mini
        mini=min(mini,1+ans);
    }
    return mini;
}

int minimumElements(vector<int> &num, int x)
{
   int ans=solveRecursion(num,x);
   if(ans==INT_MAX)
   return -1;
}


-------------------------------------------------------------------------------------------------------------------------------
  USING RECURSION + MEMOIZATION
  -------------------------------
  #include <bits/stdc++.h> 

int solveMemiozation(vector<int> &num, int x,vector<int>&dp){
    //base case
    if(x==0)
    return 0 ;
    if(x<0)
    return INT_MAX;

   if(dp[x]!=-1)
   return dp[x];
    int mini=INT_MAX;
    for(int i=0;i<num.size(); i++){
        int ans=solveMemiozation(num, x-num[i],dp);
        if(ans!=INT_MAX)
        //update mini
        mini=min(mini,1+ans);
    }
    dp[x]=mini;
    return mini;
}

int minimumElements(vector<int> &num, int x)
{
   vector<int>dp(x+1,-1);
   int ans=solveMemiozation(num,x,dp);

   if(ans==INT_MAX)
   return -1;
   else
   return ans;
}


---------------------------------------------------------------------------------------------------------------------------------
  TABULATION -BOTTOM UP APPROACH
  ------------------------------

  #include <bits/stdc++.h> 

int solveTabulation(vector<int> &num, int x){
   vector<int>dp(x+1,INT_MAX);
   dp[0]=0;
   for(int i=1; i<=x; i++){
       //i am trying to solve from every amout figure from 1  to x
       for(int j=0; j<num.size(); j++){
           if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
           dp[i]=min(dp[i],1+dp[i-num[j]]);
           }
       }
   }
   if(dp[x]==INT_MAX)
   return -1;


   return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
   return solveTabulation(num,x);
}
