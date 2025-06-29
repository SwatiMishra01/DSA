https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628
-------------------------------
 APPROACH 1-> RECURSION (TLE)
--------------------------------
#include <bits/stdc++.h> 
int f(int indx, int target, vector<int>& arr) {
    int mod = 1e9 + 7;

   if (indx == 0) {
      // If target == 0 and arr[0] == 0:
    // There are 2 valid ways:
    //   1) Take nothing ? {} sums to 0
    //   2) Take arr[0] (=0) ? {0} sums to 0
        if (target == 0 && arr[0] == 0) return 2;
       // If target == 0 but arr[0] is not zero:
    // Only the empty subset {} sums to 0
        if (target == 0) return 1;
      // If target == arr[0] (and target != 0):
    // Only one valid way ? pick arr[0]
        if (arr[0] == target) return 1;
        return 0;
    }

    int Not_Take = f(indx - 1, target, arr);
    int Take = 0;
    if (arr[indx] <= target)
        Take = f(indx - 1, target - arr[indx], arr);

    return  (Take + Not_Take) % mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum=0;
    for(int i=0; i<n; i++){
    totalSum+=arr[i];
    }
    if(totalSum-d<0 || (totalSum-d) %2)
    return false;
    int target=(totalSum-d)/2;
   return f(n-1,target,arr);
}

TC	O(2^N)
SC	O(N) (recursion stack)
--------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------
 APPROCH 2-> MEMOIZATION
---------------------------------------------
#include <bits/stdc++.h> 
int f(int indx, int target, vector<int>& arr,vector<vector<int>>&dp) {
    int mod = 1e9 + 7;

   if (indx == 0) {
      // If target == 0 and arr[0] == 0:
    // There are 2 valid ways:
    //   1) Take nothing ? {} sums to 0
    //   2) Take arr[0] (=0) ? {0} sums to 0
        if (target == 0 && arr[0] == 0) return 2;
       // If target == 0 but arr[0] is not zero:
    // Only the empty subset {} sums to 0
        if (target == 0) return 1;
      // If target == arr[0] (and target != 0):
    // Only one valid way ? pick arr[0]
        if (arr[0] == target) return 1;
        return 0;
    }

    //memoization
    if(dp[indx][target]!=-1)
    return dp[indx][target];


    int Not_Take = f(indx - 1, target, arr,dp);
    int Take = 0;
    if (arr[indx] <= target)
        Take = f(indx - 1, target - arr[indx], arr,dp);

    return  dp[indx][target]=(Take + Not_Take) % mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum=0;
    for(int i=0; i<n; i++){
    totalSum+=arr[i];
    }
    if(totalSum-d<0 || (totalSum-d) %2)
    return 0;
    int target=(totalSum-d)/2;

    vector<vector<int>>dp(n,vector<int>(target+1,-1));
   return f(n-1,target,arr,dp);
}

TC	O(N*K)
SC	O(N*K) + O(N)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------
APPROACH 3-> TABULATION
-------------------------------
#include <bits/stdc++.h>
using namespace std;

int countPartitions(int n, int d, vector<int>& arr) {
    int mod = 1e9 + 7;

    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    // ? Check for valid target
    if (totalSum < d || (totalSum - d) % 2 != 0)
        return 0;

    int target = (totalSum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // ? Base Cases
    // sum = 0 is always possible with empty subset
    if (arr[0] == 0)
        dp[0][0] = 2; // {} and {0}
    else
        dp[0][0] = 1; // only {}

    // single element equal to target
    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;

    // ? Build DP
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {
            int notTake = dp[i - 1][t];
            int take = 0;
            if (arr[i] <= t)
                take = dp[i - 1][t - arr[i]];

            dp[i][t] = (take + notTake) % mod;
        }
    }

    return dp[n - 1][target];
}
TC	O(N*K)
SC	O(N*K)

-------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------
 APPROACH 4-> SPACE OPTIMIZATION
---------------------------------
#include <bits/stdc++.h>
using namespace std;

int countPartitions(int n, int d, vector<int>& arr) {
    int mod = 1e9 + 7;

    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if (totalSum < d || (totalSum - d) % 2 != 0)
        return 0;

    int target = (totalSum - d) / 2;

    vector<int> prev(target + 1, 0);

    // ? Base cases
    if (arr[0] == 0)
        prev[0] = 2;  // {} and {0}
    else
        prev[0] = 1;  // only {}

    if (arr[0] != 0 && arr[0] <= target)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        vector<int> cur(target + 1, 0);
        for (int t = 0; t <= target; t++) {
            int notTake = prev[t];
            int take = 0;
            if (arr[i] <= t)
                take = prev[t - arr[i]];

            cur[t] = (take + notTake) % mod;
        }
        prev = cur;  // shift window
    }

    return prev[target];
}

TC	O(N*K)
SC	O(K)


