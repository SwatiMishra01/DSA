https://leetcode.com/problems/triangle/description/

-----------------------------------------
    APPROACH 1-> RECURSION    (TLE)
----------------------------------------
class Solution {
public:

int f(int i,int j,vector<vector<int>>& triangle,int n){
    //base case->reached last row? return value where reached
    if(i==n-1)
    return triangle[n-1][j];

    int down=triangle[i][j]+f(i+1,j,triangle,n);
    int diagonal=triangle[i][j]+f(i+1,j+1,triangle,n);

    return min(down,diagonal);

}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        return f( 0,0,triangle,n);
    }
};


T.C=O(2^summation of 1+2+3+----+n-1))
S.C=O(N)

  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  ----------------------------------------------------------
      APPROACH 2-> MEMOIZATION
  -----------------------------------------------------------
  class Solution {
public:

int f(int i,int j,vector<vector<int>>& triangle,int n, vector<vector<int>>&dp){
    //base case->reached last row? return value where reached
    if(i==n-1)
    return triangle[n-1][j];

    //applying memoization
    if(dp[i][j]!=-1)
    return dp[i][j];

    int down=triangle[i][j]+f(i+1,j,triangle,n,dp);
    int diagonal=triangle[i][j]+f(i+1,j+1,triangle,n,dp);

    return dp[i][j]=min(down,diagonal);

}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f( 0,0,triangle,n,dp);
    }
};


T.C=O(N*N)
S.C=O(N)


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-----------------------------------------
     APPROACH 3-> TABULATION
-----------------------------------------

  class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        //for last row base case
		for(int j=0; j<n;j++ ){
			//row will remain same -last, solumn will change
			dp[n-1][j]=triangle[n-1][j];

			//we have done n-1 so we will start from n-2 toward up till 0
			for(int i=n-2; i>=0; i--){
				for(int j=i;j>=0; j--){
					int down=triangle[i][j]+dp[i+1][j];
					int diagonal=triangle[i][j]+dp[i+1][j+1];

					dp[i][j]=min(down,diagonal);
				}

			}
	   }
	   return dp[0][0];
    }
};

T.C=O(N*N)
  S.C=0(N*N)
