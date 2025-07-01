https://leetcode.com/problems/longest-palindromic-subsequence/
leetcode-516

class Solution {
public:
int f(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    //base cases
    for(int i=0; i<n; i++)
        dp[i][0]=0;

    for(int j=0; j<m; j++)
        dp[0][j]=0;

    //nested for loops
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1])
            dp[i][j]=1+dp[i-1][j-1];

            else
            dp[i][j]=0+max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];


}
    int longestPalindromeSubseq(string s) {
       string t=s;
       reverse(s.begin(),s.end());
        return f(s,t);
    }
};
