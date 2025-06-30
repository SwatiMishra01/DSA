https://leetcode.com/problems/longest-common-subsequence
https://www.naukri.com/code360/problems/longest-common-subsequence_624879
LLETCODE-1143
--------------------------------
  APPROACH 1-> RECURSION (TLE)
-------------------------------
 class Solution {
public:

int f(int indx1, int indx2, string &text1, string &text2){
    //base case
    if(indx1<0 || indx2<0)
    return 0;

    //exploring all possibilites
    if(text1[indx1]==text2[indx2])
    return  1+f(indx1-1,indx2-1,text1,text2);
    else
    return 0+max(f(indx1-1,indx2,text1,text2),f(indx1,indx2-1,text1,text2));
}

    int longestCommonSubsequence(string text1, string text2) {
        int t1=text1.size();
        int t2=text2.size();
        return f(t1-1,t2-1,text1,text2);
    }
};


---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------------
   APPROACH 2-> MEMOIZATION
  ------------------------------------------
  class Solution {
public:

int f(int indx1, int indx2, string &text1, string &text2,vector<vector<int>>&dp){
    //base case
    if(indx1<0 || indx2<0)
    return 0;

    if(dp[indx1][indx2]!=-1)
    return dp[indx1][indx2];

    //exploring all possibilites
    if(text1[indx1]==text2[indx2])
    return  dp[indx1][indx2]=1+f(indx1-1,indx2-1,text1,text2,dp);
    else
    return dp[indx1][indx2]=0+max(   f(indx1-1,indx2,text1,text2,dp),
                                     f(indx1,indx2-1,text1,text2,dp)   );
}

    int longestCommonSubsequence(string text1, string text2) {
        int t1=text1.size();
        int t2=text2.size();

        vector<vector<int>>dp(t1,vector<int>(t2+1,-1));
        return f(t1-1,t2-1,text1,text2,dp);
    }
};

--------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------
   APPROACH 3-> TABULATION
  -----------------------------------
  class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();

        vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, 0));

        for (int indx1 = 1; indx1 <= t1; indx1++) {
            for (int indx2 = 1; indx2 <= t2; indx2++) {

                if (text1[indx1 - 1] == text2[indx2 - 1]) {
                    dp[indx1][indx2] = 1 + dp[indx1 - 1][indx2 - 1];
                } else {
                    dp[indx1][indx2] = max(dp[indx1 - 1][indx2], dp[indx1][indx2 - 1]);
                }

            }
        }
        return dp[t1][t2];
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------
    APPROACH 4-> SPACE OPTIMIZATION
  ------------------------------------
  class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();

        vector<int> prev(t2 + 1, 0), curr(t2 + 1, 0);

        for (int indx1 = 1; indx1 <= t1; indx1++) {
            for (int indx2 = 1; indx2 <= t2; indx2++) {
                if (text1[indx1 - 1] == text2[indx2 - 1]) {
                    curr[indx2] = 1 + prev[indx2 - 1];
                } else {
                    curr[indx2] = max(prev[indx2], curr[indx2 - 1]);
                }
            }
            prev = curr; // Move to next row
        }

        return prev[t2];
    }
};

  
