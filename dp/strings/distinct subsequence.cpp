

-----------------------------------------
  MEMOIZATION
  class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // If t is fully matched
        if (j < 0) return 1;
        // If s is exhausted but t is not
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            // Take the match + skip the match
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        } else {
            // Skip the current s character
            return dp[i][j] = f(i - 1, j, s, t, dp);
        }
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};
-----------------------------------------------------------------------------------------------------
  ----------------------
   TABULATION
  -----------------------
  class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        // Base case: matching empty t with any prefix of s
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
-------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------
    SPACE OPTIMIZATION
  ------------------------------
  class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<double> prev(m + 1, 0);
        
        // Base case: empty t matches any prefix of s in exactly 1 way
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            // Go right to left to prevent overwriting needed values
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    prev[j] = prev[j - 1] + prev[j];
                } 
                // else: prev[j] stays same because it's from prev row
                // No need for else branch because prev[j] is reused
            }
            // prev[0] always stays 1
        }

        return (int)prev[m];
    }
};
