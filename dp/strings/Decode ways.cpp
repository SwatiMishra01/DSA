https://leetcode.com/problems/decode-ways/description/
LEETCODE-91

  ------------------
     RECURSION
  -------------------
  class Solution {
    private: 
    int solve(int i, string&s){
        //base case-> 1.cant decode 0 2. one element
        if(s[i]=='0') return 0;
        if(i==s.size()) return 1;

        int ways=solve(i+1,s); //ek digit lo
        if(i + 1 < s.size()
           && (s[i]=='1'||s[i]=='2' && s[i+1]<='6')){ //can take 2 digit
          ways+=solve(i+2,s);
        }
        return ways;
    }
public:
    int numDecodings(string s) {
        return solve(0,s);
    }
};
T.C=O(2ⁿ)
S.C=O(N) stack space
------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------
      MEMOIZATION
  -------------------------
  class Solution {
    private: 
    int solve(int i, string&s,vector<int>&dp){
        //base case-> 1.cant decode 0 2. one element
        if(s[i]=='0') return 0;
        if(i==s.size()) return 1;

        //memoization
        if(dp[i]!=-1) return dp[i];

        int ways=solve(i+1,s,dp); //ek digit lo
        if(i + 1 < s.size()
           && (s[i]=='1'||s[i]=='2' && s[i+1]<='6')){ //can take 2 digit
          ways+=solve(i+2,s,dp);
        }
        return dp[i]=ways;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,dp);
    }
};
T.C=O(n)
S.C=O(N)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------
       TABULATION
  -----------------------
  class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=1;

        for(int i=n-1; i>=0; i--){
            if (s[i] == '0') {
            dp[i] = 0;
        } else {
            dp[i] = dp[i + 1];
            if (i + 1 < n) {
                int num = stoi(s.substr(i, 2));
                if (num >= 10 && num <= 26)
                    dp[i] += dp[i + 2];
            }
        }
    }
    return dp[0];
    }
};
  
  
