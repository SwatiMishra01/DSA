https://leetcode.com/problems/unique-paths/description/


-------------------------------------------
    APPROACH 1->RECURSION   (TLE)
--------------------------------------------
class Solution {
public:

 int f(int i, int j){
    //bse case
    if(i==0 && j==0)
    return 1;
    if(i<0 || j<0)
    return 0;
    int up=f(i-1,j);
    int left=f(i,j-1);
    return up+left;
 }
    int uniquePaths(int m, int n) {
        return f(m-1,n-1);
    }
};



T.C= O( 2^(m*n)]
S.C=S.C=[(n-1)+(m-1)]
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------------------
        APPROACH 2-> MEMOIZATION
  ---------------------------------------------------
  class Solution {
public:

 int f(int i, int j,vector<vector<int>>& dp){
    //bse case
    if(i==0 && j==0)
        return 1;


    if(i<0 || j<0)
        return 0;
    
    if(dp[i][j]!=-1)   // checking stored value
        return dp[i][j];


    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);

    return dp[i][j]=up+left;  //returning as dp
   
 }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1)); //creating vector
        return f(m-1,n-1,dp);
    }
};

  T.C=O(N*M)
  S.C=[(n-1)+(m-1)]+O(m*n)

    
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------
     APPROACH 3-> TABULATION
-----------------------------------------
  class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
     for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            //base case
            if(i==0 && j==0)
            dp[i][j]=1;
           else{
           int up=0;
           int left=0;
            if(i>0) up=dp[i-1][j];
            if(j>0) left=dp[i][j-1];

            dp[i][j]=up+left;
           }
        }
     }

     return dp[m-1][n-1];
    }
};


T.C=O(N*M)
T.C=O(N*M)

----------------------------------------------------------------------------------------------------------------------------------

  ----------------------------------------------
     APPROACH 4-> SPACE OPTIMIZATION
  ------------------------------------------------
  class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        vector<int>curr(n,0);
        for(int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                if(i==0 && j==0)
                curr[j]=1;
                else{
                    int up=0;
                    int left=0;

                    if(i>0) up=prev[j];
                    if(j>0) left=curr[j-1];
                    curr[j]=up+left;
                }
            }
            prev=curr;

        }
        return prev[n-1];
    }
};

 T.C. = O(m × n)
S.C. = O(n + n) = O(n)
