https://leetcode.com/problems/interleaving-string/description/
LEETCODE-97

-------------------
    RECURSION
--------------------
  class Solution {
    private:
    bool solve(int i, int j, string&s1, string &s2, string&s3){
        int k=i+j;
        if(i==s1.size()&&j==s2.size()) return true;
        bool ans=false;

        if(i<s1.size( )&&s1[i]==s3[k]) ans=ans||solve(i+1,j,s1,s2,s3); // If next char in s1 matches with current char in s3, move in s1
        if(j<s2.size( )&&s2[j]==s3[k]) ans=ans||solve(i,j+1,s1,s2,s3);

        return ans;


    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        //base case
        if(s1.length()+s2.length()!=s3.length()) return false;
        return solve(0,0,s1,s2,s3);
    }
};
T.C=O(2^(n+m))
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------
     MEMOIZATION
-------------------------
  class Solution {
    private:
    bool solve(int i, int j, string&s1, string &s2, string&s3,vector<vector<int>> &dp){
        int k=i+j;
        if(i==s1.size()&&j==s2.size()) return true;
        bool ans=false;

        //memoization
        if(dp[i][j]!=-1) return dp[i][j];

        if(i<s1.size( )&&s1[i]==s3[k]) ans=ans||solve(i+1,j,s1,s2,s3,dp);
        if(j<s2.size( )&&s2[j]==s3[k]) ans=ans||solve(i,j+1,s1,s2,s3,dp);

        return dp[i][j]=ans;


    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        //base case
        if(s1.length()+s2.length()!=s3.length()) return false;

        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solve(0,0,s1,s2,s3,dp);
    }
};
T.C=O(n*m)
S.C=O(n*m)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------
        TABULATION
------------------------------
  class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //base case
        if(s1.length()+s2.length()!=s3.length()) return false;

        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        dp[0][0]=true;

        for(int i=0; i<=s1.size(); i++){
            for(int j=0; j<=s2.size(); j++){
                int k=i+j-1;

                // If taking from s1 is possible
            if (i > 0 && dp[i-1][j] && s1[i-1] == s3[k])
                dp[i][j] = true;

            // If taking from s2 is possible
            if (j > 0 && dp[i][j-1] && s2[j-1] == s3[k])
                dp[i][j] = true;


            }
        }
        return dp[s1.size()][s2.size()];
    }
};
  T.C=O(n*m)
S.C=O(n*m)
