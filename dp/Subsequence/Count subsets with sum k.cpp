-----------------------------------
  APPROACH 1-> RECURSION (TLE)
-------------------------------------

int f(int indx, int target, vector<int>& arr) {
    int mod = 1e9 + 7;

   if (indx == 0) {
      // If target == 0 and arr[0] == 0:
    // There are 2 valid ways:
    //   1) Take nothing → {} sums to 0
    //   2) Take arr[0] (=0) → {0} sums to 0
        if (target == 0 && arr[0] == 0) return 2;
       // If target == 0 but arr[0] is not zero:
    // Only the empty subset {} sums to 0
        if (target == 0) return 1;
      // If target == arr[0] (and target != 0):
    // Only one valid way → pick arr[0]
        if (arr[0] == target) return 1;
        return 0;
    }

    int Not_Take = f(indx - 1, target, arr);
    int Take = 0;
    if (arr[indx] <= target)
        Take = f(indx - 1, target - arr[indx], arr);

    return  (Take + Not_Take) % mod;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    return f(n - 1, k, arr);
}


TC = O(2^N)
SC = O(N)
--------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------------
    APPROACH 2-> MEMOIZATION
  -----------------------------------------------
  int f(int indx, int target, vector<int>& arr, vector<vector<int>>& dp) {
    int mod = 1e9 + 7;

    if (indx == 0) {
      // If target == 0 and arr[0] == 0:
    // There are 2 valid ways:
    //   1) Take nothing → {} sums to 0
    //   2) Take arr[0] (=0) → {0} sums to 0
        if (target == 0 && arr[0] == 0) return 2;
       // If target == 0 but arr[0] is not zero:
    // Only the empty subset {} sums to 0
        if (target == 0) return 1;
      // If target == arr[0] (and target != 0):
    // Only one valid way → pick arr[0]
        if (arr[0] == target) return 1;
        return 0;
    }

    if (dp[indx][target] != -1) return dp[indx][target];

    int Not_Take = f(indx - 1, target, arr, dp);
    int Take = 0;
    if (arr[indx] <= target)
        Take = f(indx - 1, target - arr[indx], arr, dp);

    return dp[indx][target] = (Take + Not_Take) % mod;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

TC = O(N*K)
SC = O(N*K) + O(N)
  ---------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------------------------
      APPROACH 3-> TABULATION
    -------------------------------------------
int findWays(vector<int>& arr, int target) {
    int n = arr.size();
    int mod = 1e9 + 7;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // ? Base Case 1: Always 1 way to make sum 0 ? empty subset
    if (arr[0] == 0)
        dp[0][0] = 2; // {} and {0}
    else
        dp[0][0] = 1; // only {}

    // ? Base Case 2: Single element equal to target
    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;

    // ? Fill the table
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
TC = O(N*K)
SC = O(N*K)
  --------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------
   APPROACH 4->  SPACE OPTIMIZATION
  -----------------------------------
  
int findWays(vector<int>& arr, int target) {
    int n = arr.size();
    int mod = 1e9 + 7;

    vector<int> prev(target + 1, 0);

    // ? Base case for sum = 0: empty subset always works
    prev[0] = (arr[0] == 0) ? 2 : 1;

    // ? Base case: single element equal to target
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
        prev = cur;
    }

    return prev[target];
}

TC = O(N*K)
SC = O(K)
