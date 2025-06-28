# https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
# https://leetcode.com/problems/fibonacci-number/description/
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -

    F(n) = F(n - 1) + F(n - 2), 
    Where, F(1) = 1, F(2) = 1


Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 'n' = 2 by using conditionals like if else and return what's expected.

"Indexing is start from 1"


Example :
Input: 6

Output: 8
  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
#include<vector>
using namespace std;

int fib(int n, vector<int>&dp){
        //base case
        if(n<=1)
        return n;

        //step 3
        if(dp[n]!=-1)
        return dp[n];

      //step 2
       dp[n]=fib(n-1,dp)+fib(n-2,dp);
        return dp[n];

}
int main()
{
        int n;
        cin>>n;
        //step 1
        vector<int>dp(n+1,-1);
                cout<<fib(n,dp)<<endl;
        return 0;
        
        }
