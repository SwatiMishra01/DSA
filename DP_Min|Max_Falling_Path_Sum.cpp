https://leetcode.com/problems/minimum-falling-path-sum/description/

--------------------------------------------
  APPROACH 1-> RECURSION   (TLE)
-------------------------------------------
class Solution {
public:

  int n, m;
   int f(int i,int j,vector<vector<int>>& matrix){
    //base cases

    //if it exceeds last column
    if(j<0 || j>=m)
    return INT_MAX;  //quki ques min nikalna h max likhenge taaki ye parh choose na kre
                     // agar max nikalne ka ques hota then we write INT_MIN taki ye path     
                     // choose na kre


    //first row reached
    if(i==0)
    return matrix[0][j];


        int s=f(i-1,j,matrix);
        int diagonal_left=f(i-1,j-1,matrix);
        int diagonal_right=f(i-1,j+1,matrix);

        return matrix[i][j]+min(s,min(diagonal_left,diagonal_right));

   }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        //row
         n=matrix.size();
        //col
         m=matrix[0].size();
        int mini=INT_MAX;
        for(int j=0; j<m; j++){
            mini=min(f(n-1,j,matrix),mini);
        }
        return mini;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------------
     APPROACH 2-> MEMOIZATION
  ------------------------------------------------
  class Solution {
public:

  int n, m;
   int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
    //base cases

    //if it exceeds last column
    if(j<0 || j>=m)
    return INT_MAX;  //quki ques min nikalna h max likhenge taaki ye parh choose na kre
                     // agar max nikalne ka ques hota then we write INT_MIN taki ye path     
                     // choose na kre


    //first row reached
    if(i==0)
    return matrix[0][j];

    //memoization
    if(dp[i][j]!=-1)
    return dp[i][j];


        int s=f(i-1,j,matrix,dp);
        int diagonal_left=f(i-1,j-1,matrix,dp);
        int diagonal_right=f(i-1,j+1,matrix,dp);

        return dp[i][j]=matrix[i][j]+min(s,min(diagonal_left,diagonal_right));

   }

    int minFallingPathSum(vector<vector<int>>& matrix) {
       
        //row
         n=matrix.size();
        //col
         m=matrix[0].size();
          //dp
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mini=INT_MAX;
        for(int j=0; j<m; j++){
            mini=min(f(n-1,j,matrix,dp),mini);
        }
        return mini;
    }
};
