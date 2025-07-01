https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        
        //base cases
        for(int i=0; i<n; i++)
        dp[i][0]=0;
        
        
        for(int j=0; j<m; j++)
        dp[0][j]=0;
        
        //nested for loops 
        for(int i=1;i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(dp[i][j],ans);
                }
                
                else
                dp[i][j]=0;  //only this changed rest is exactly same
            }
        }
        return ans;
        
        
    }
};
