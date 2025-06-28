https://leetcode.com/problems/minimum-path-sum/description/

--------------------------------------------
    APPROACH 1->RECURSION   (TLE)
---------------------------------------------
class Solution {
public:

int f(int i, int j, vector<vector<int>>&grid){
    //base cases

    //if it goes out of boundary
    if(i<0 || j<0)
    return 1e9; //itni badi value dedo ki vo isko select hi na kre

    //starting position
    if(i==0 && j==0)
    return grid[i][j];

    int up= f(i-1,j,grid)+grid[i][j];
    int left=f(i,j-1,grid)+grid[i][j];

    return min(up,left);
}


    int minPathSum(vector<vector<int>>& grid) {
        //row size
        int n=grid.size();
        //col size
        int m=grid[0].size();

        return f(n-1,m-1,grid);
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------------------
     APPROACH 2->MEMOIZATION
  ------------------------------------------------
  class Solution {
public:

int f(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp){
    //base cases

    //if it goes out of boundary
    if(i<0 || j<0)
    return 1e9; //itni badi value dedo ki vo isko select hi na kre

    //starting position
    if(i==0 && j==0)
    return grid[i][j];

    //applying memoization
    if(dp[i][j]!=-1)
    return dp[i][j];

    int up= f(i-1,j,grid,dp)+grid[i][j];
    int left=f(i,j-1,grid,dp)+grid[i][j];

    return dp[i][j]=min(up,left);
}


    int minPathSum(vector<vector<int>>& grid) {
        //row size
        int n=grid.size();
        //col size
        int m=grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(n-1,m-1,grid,dp);
    }
};
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------
     APPROACH 3-> TABULATION
  -------------------------------------
  class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
    int m=grid[0].size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){

            if(i==0 && j==0)            
              dp[i][j]=grid[i][j];

              else{

              int up=grid[i][j];
              if(i>0)  up+=dp[i-1][j];
              else up+=1e9;   //no path-out of boundary

              int left=grid[i][j];
              if(j>0) left+=dp[i][j-1];
              else left+=1e9;  //no path-out of boundary

                dp[i][j]=min(up,left);
              }
       }
       
   }
   return dp[n-1][m-1];
    }
};
