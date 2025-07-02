https://www.naukri.com/code360/problems/edit-distance_630420
https://leetcode.com/problems/edit-distance/submissions/1683347688/
leetcode-72

  -------------------------------
   APPROACH 1-> RECURSION-TLE
  ------------------------------
  class Solution {
public:
int f(int i, int j,string &word1, string &word2 ){
//base cases
if(i<0)
return j+1;


if(j<0)
return i+1;

//recursion
if(word1[i]==word2[j])
return 0+f(i-1,j-1,word1,word2);
else
//insert->f(i,j-1)
//delete->f(i-1,j)
//replace->f(i-1,j-1)
return 1+min(f(i,j-1,word1,word2),min(f(i-1,j,word1,word2),f(i-1,j-1,word1,word2)));
}


    int minDistance(string word1, string word2) {
      int n=word1.size();
      int m=word2.size();
        return f(n-1,m-1,word1,word2);
        
    }
};

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------
   APPROACH2-> MEMOIZATION
  --------------------------------------
  class Solution {
public:
int f(int i, int j,string &word1, string &word2,vector<vector<int>>&dp ){
//base cases
if(i<0)
return j+1;


if(j<0)
return i+1;

//memoization
if(dp[i][j]!=-1)
return dp[i][j];
//recursion
if(word1[i]==word2[j])
return dp[i][j]=0+f(i-1,j-1,word1,word2,dp);
else
//insert->f(i,j-1)
//delete->f(i-1,j)
//replace->f(i-1,j-1)
return dp[i][j]=1+min(f(i,j-1,word1,word2,dp),min(f(i-1,j,word1,word2,dp),f(i-1,j-1,word1,word2,dp)));
}


    int minDistance(string word1, string word2) {
      int n=word1.size();
      int m=word2.size();
      vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return f(n-1,m-1,word1,word2,dp);
        
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------------------
    APPROACH 3-> TABULATION
  --------------------------------------------------
  class Solution {
public:
    int minDistance(string word1, string word2) {
      int n=word1.size();
      int m=word2.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //base cases
        for(int i=0; i<=n; i++)
         dp[i][0]=i;

        for(int j=0; j<=m; j++)
         dp[0][j]=j;

        //nested for loops
        for(int i=1; i<=n;i++){
            for(int j=1; j<=m; j++){
                //recursion
if(word1[i-1]==word2[j-1])
 dp[i][j]=0+dp[i-1][j-1];
else
//insert->f(i,j-1)
//delete->f(i-1,j)
//replace->f(i-1,j-1)
 dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));

            }
        }
        return dp[n][m];
        
    }
};
-------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------
  APPROACH 4-> SPACE OPTIMIZATION
  ----------------------------------------
  class Solution {
public:
    int minDistance(string word1, string word2) {
      int n=word1.size();
      int m=word2.size();
    // Create two arrays to store previous and current row of edit distances
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);
        //base cases

        for(int j=0; j<=m; j++)
         prev[j]=j;

        //nested for loops
        for(int i=1; i<=n;i++){
            curr[0]=i;
            for(int j=1; j<=m; j++){
                //recursion
if(word1[i-1]==word2[j-1])
 curr[j]=0+prev[j-1];
else
//insert->f(i,j-1)
//delete->f(i-1,j)
//replace->f(i-1,j-1)
curr[j]=1+min(curr[j-1],min(prev[j],prev[j-1]));

            }
            prev=curr;
        }
        return prev[m];
        
    }
};
  
  
