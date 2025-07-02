https://leetcode.com/problems/wildcard-matching/submissions/1683412422/
leetcode-44
  ------------------------
        MEMOIZATON
  --------------------
class Solution {
public:
    // Helper function: Check if pattern[0..i] consists of only '*'
    bool isAllStars(string &pattern, int i) {
        for (int j = 0; j <= i; j++) {
            if (pattern[j] != '*')
                return false;
        }
        return true;
    }

    //  memoization
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base Case 1: Both string and pattern are fully matched
        if (i < 0 && j < 0) return true;

        // Base Case 2: String is exhausted but pattern is not
        // Pattern can match only if remaining pattern is all '*'
        if (i < 0 && j >= 0) return isAllStars(p, j);

        // Base Case 3: Pattern is exhausted but string is not
        // Cannot match, so return false
        if (j < 0 && i >= 0) return false;

        // If already computed, return stored value
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match or pattern has '?', move both indices back
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        }

        // If pattern has '*'
        if (p[j] == '*') {
            // '*' can match:
            // 1. Zero characters: move pattern index back
            // 2. One or more characters: move string index back
            return dp[i][j] = f(i - 1, j, s, p, dp) || f(i, j - 1, s, p, dp);
        }

        // If characters don't match and pattern has no wildcard, return false
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // DP table: dp[i][j] stores result for s[0..i] and p[0..j]
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start recursion from last indices
        return f(n - 1, m - 1, s, p, dp);
    }
};
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------
    TABULATION
  -----------------------
  class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base Case: Empty string matches empty pattern
        dp[0][0] = true;

        // Base Case: Empty string vs pattern (pattern must be all '*')
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
            else
                dp[0][j] = false;
        }

        // Base Case: string not empty, pattern empty => false (dp[i][0] = false)

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' matches empty (dp[i][j-1]) OR one/more chars (dp[i-1][j])
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
TC: O(n*m)
 SC: O(n*m)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------
    SPACE OPTMIZATION
  ---------------------------------
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<bool> prev(m + 1, false), curr(m + 1, false);

        // Base Case: empty string & pattern
        prev[0] = true;

        // Base Case: empty string vs pattern
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1];
            else
                prev[j] = false;
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = false; // pattern empty, string not empty => false
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr; // move to next row
        }

        return prev[m];
    }
};
TC: O(n*m)
 SC: O(m)
  
