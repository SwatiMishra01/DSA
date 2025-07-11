https://leetcode.com/problems/valid-parenthesis-string/description/
LEETCODE-678

  ----------------------------------------------
   APPROACH 1-> RECURSION    (TLE)
  -----------------------------------------------
  class Solution {
public:
bool f(string &s, int indx, int cnt){
    if(cnt<0)
    return false;

    if(indx==s.size())
    return (cnt==0);

   //if opening bracket cnt++
    if(s[indx]=='(')
    return f(s,indx+1,cnt+1);
    
    //if closing bracket cnt--
    if(s[indx]==')')
    return f(s,indx+1,cnt-1);
    
    //if asterik try out 3 possible ways and if any one is true return true
    return f(s,indx+1,cnt+1) || f(s,indx+1,cnt-1) || f(s,indx+1,cnt);
}
    bool checkValidString(string s) {

        return f(s,0,0);
    }
};
T.C=O(3^N)
S.C=O(N)

---------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------------------------
    APPROACH 2-> MEMOIZATION
  ----------------------------------------------------------
  class Solution {
public:
bool f(string &s, int indx, int cnt,vector<vector<int>> &dp,int n){
    if(cnt<0)
    return false;

    if(indx==s.size())
    return (cnt==0);

    //memoization
    if(dp[indx][cnt+n]!=-1)
    return dp[indx][cnt+n];


    bool ans = false;
   //if opening bracket cnt++
    if(s[indx]=='(')
     ans= f(s,indx+1,cnt+1,dp,n);
    
    //if closing bracket cnt--
    else if(s[indx]==')')
     ans= f(s,indx+1,cnt-1,dp,n);
    
    //if asterik try out 3 possible ways and if any one is true return true
  else 
   ans=f(s,indx+1,cnt+1,dp,n) || f(s,indx+1,cnt-1,dp,n) || f(s,indx+1,cnt,dp,n);


   return dp[indx][cnt+n]=ans;
}
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, -1));
        return f(s,0,0,dp,n);
    }
};
T.C=O(N^2)
S.C=O(N^2)

---------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------------
  APPPROACH 3-> TABULATION
  --------------------------------------------
  
