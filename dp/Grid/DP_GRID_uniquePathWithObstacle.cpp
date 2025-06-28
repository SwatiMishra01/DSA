
CODING NINJAS && LEETCODE
  -> dono problem same h bas ek linke ka frk h jo extra add hui h leetcode vale m


https://www.naukri.com/code360/problems/maze-obstacles_977241?leftPanelTabValue=PROBLEM
-------------------------------------
   APPROACH 1-> RECURSION
------------------------------------
  
int mod=(int)(1e9+7) ;
int f(int i, int j,vector< vector< int> > &mat){

    //standing at starting position(0,0) of the metrix
    if(i==0 && j==0)
    return 1;
   

   //out of the matrix
    if(i<0 || j<0)
    return 0;
   
   //obstacle vla edge case
    if(i>=0 && j>=0 && mat[i][j]==-1)
    return 0;

    int up=f(i-1,j,mat);
    int left=f(i,j-1,mat);

    return (up+left);


}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return f(n-1,m-1,mat);
}

-------------------------------------------------------------------------------------------
  --------------------------------
     APPROACGH 2->N MEMOIZATION
  -----------------------------------

int mod=(int)(1e9+7) ;
int f(int i, int j,vector< vector< int> > &mat,vector<vector<int>>&dp){

    //standing at starting position(0,0) of the metrix
    if(i==0 && j==0)
    return 1;
   

   //out of the matrix
    if(i<0 || j<0)
    return 0;
   
   //obstacle vla edge case
    if(i>=0 && j>=0 && mat[i][j]==-1)
    return 0;
 
 //memoization
    if(dp[i][j]!=-1)
     return dp[i][j];

    int up=f(i-1,j,mat,dp);
    int left=f(i,j-1,mat,dp);

    return dp[i][j]=(up+left)% mod;


}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,mat,dp);
}
---------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------
    APPROACH 3-> TAYBULATION
  -------------------------------------------
  
int mod=(int)(1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    int dp[n][m];
    for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             if(i==0 && j==0)
             dp[i][j]=1;
             else if(mat[i][j]==-1)
             dp[i][j]=0;
             else{
                 int up=0;
                 int left=0;
                 if(i>0)  up= dp[i-1][j];
                 if(j>0)  left=dp[i][j-1];

                 dp[i][j]=(up+left)% mod;
             }

         }
    }
    return dp[n-1][m-1];
}


--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                                                                                                     LEETODE
  --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




LEETCODE-> 63
  https://leetcode.com/problems/unique-paths-ii/description/

  -----------------------------------
     APPROACH 1-> RECURSION   (TLE)
  ----------------------------------
  class Solution {
public:
int f(int i,int j,vector<vector<int>>& obstacleGrid ){
 
 // base case->starting position
 if(i==0 && j==0)
 return 1;

 //out of boundary 
 if(i<0 || j<0)
 return 0;

 //if obstacle present
 if( i>=0 && j>=0 && obstacleGrid[i][j]==1)
 return 0;


 int up=f(i-1,j,obstacleGrid);
 int left=f(i,j-1,obstacleGrid);
 return up+left;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        return f(m-1,n-1,obstacleGrid);
    }
};

--------------------------------------------------------------------------------------------------------------
  ----------------------------
     APPROACH 2-> MEMOIZATION
  -------------------------------
    class Solution {
public:
int f(int i,int j,vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp ){
 
 // base case->starting position
 if(i==0 && j==0)
 return 1;

 //out of boundary 
 if(i<0 || j<0)
 return 0;

 //if obstacle present
 if( i>=0 && j>=0 && obstacleGrid[i][j]==1)
 return 0;

 //memiozation
 if(dp[i][j]!=-1)
 return dp[i][j];


 int up=f(i-1,j,obstacleGrid,dp);
 int left=f(i,j-1,obstacleGrid,dp);
 return dp[i][j]=up+left;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        return f(m-1,n-1,obstacleGrid,dp);
    }
};

----------------------------------------
   APPROACH 3-> TABULATION
  -------------------------------------------
  class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        int dp[m][n];
        //base case
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

            for(int i=0; i<m; i++){
                for(int  j=0 ;j<n; j++){
           if(i==0 && j==0)
          dp[i][j]=1;

           else if(obstacleGrid[i][j]==1)
            dp[i][j]= 0;

           else{
            int up=0; int left=0;
            if(i>0) up=dp[i-1][j];
            if(j>0) left=dp[i][j-1];

             dp[i][j]=up+left;
           }
            }
            }
        return dp[m-1][n-1];
    }
};



