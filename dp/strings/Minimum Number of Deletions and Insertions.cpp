https://leetcode.com/problems/delete-operation-for-two-strings/
leetcode-583
https://www.naukri.com/code360/problems/can-you-make_4244510

class Solution {
public:
    int lcs(string text1, string text2) {
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

    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * lcs(word1, word2);
    }
};
