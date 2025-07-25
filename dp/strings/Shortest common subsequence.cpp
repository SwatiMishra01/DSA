https://leetcode.com/problems/shortest-common-supersequence/
leetcode-1092


class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        //base cases
        for(int i=0; i<n; i++){
            dp[i][0]=0;
        }

        for(int j=0; j<m; j++){
            dp[0][j]=0;
        }

        //nested for loops
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1]==str2[j-1])
                dp[i][j]=1+dp[i-1][j-1];

                else
                dp[i][j]=0+max(dp[i-1][j], dp[i][j-1]);
            }
        }

        //printing
        int len=dp[n][m];
        int i=n;
        int j=m;
        int indx=len-1;
        string ans="";

        //jab tk i & j dono >0 ho

        while(i>0 &&  j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
                indx--;
            }


            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }


            else{
                ans+=str2[j-1];
                j--;
            }
        }


        //if only i>0 left
        while(i>0){
            ans+=str1[i-1];
                i--;
        }

        //if only j>0 left
        while(j>0){
            ans+=str2[j-1];
                j--;
        }
        reverse(ans.begin(),ans.end());

        return ans;

        
    }
};
