--------------------------------------------
    APPROACH 1-> RECURSION   (TLE)
  -------------------------------------------
  // Recursive function without memoization
bool f(int i, int target, vector<int>& arr) {
    // Base Cases
    if (target == 0) return true;
    if (i == 0) return arr[0] == target;

    bool notTake = f(i - 1, target, arr);
    bool take = false;
    if (arr[i] <= target) take = f(i - 1, target - arr[i], arr);

    return take || notTake;
}

int minSubsetSumDifference(vector<int>& arr, int n) {
    //for loop likh skte ho iski jagah
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int k = totalSum / 2;

    int mini = INT_MAX;
    for (int s1 = 0; s1 <= k; s1++) {
        if (f(n - 1, s1, arr)) {
            int s2 = totalSum - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }
    return mini;
}

T.C=O(2^n * k) → TLE for larger n
S.C=O(N)
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------
  APPROACH 2->MEMOIZATION
  -------------------------------------------
  int f(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Cases
    if (target == 0) return true;
    if (i == 0) return arr[0] == target;

//memoization
    if (dp[i][target] != -1) return dp[i][target];

    bool notTake = f(i - 1, target, arr, dp);
    bool take = false;
    if (arr[i] <= target) take = f(i - 1, target - arr[i], arr, dp);

    return dp[i][target] = take || notTake;
}


int minSubsetSumDifference(vector<int>& arr, int n)
{
    //for loop bhi likh skte ho
	 int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int k = totalSum / 2;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    int mini = INT_MAX;
    for (int s1 = 0; s1 <= k; s1++) {
        if (f(n - 1, s1, arr, dp)) {
            int s2 = totalSum - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}

T.C=O(n * totalSum)
S.C=O(n * totalSum) + O(n) (Recursion Stack)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

---------------------------
   APPROACH 3-> TABULATION
------------------------------
  int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }
    int k = totalSum / 2;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base Case: target 0 is always possible
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    if (arr[0] <= k) dp[0][arr[0]] = true;

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool not_take = dp[i - 1][target];
            bool take = false;
            if (target >= arr[i])
                take = dp[i - 1][target - arr[i]];

            dp[i][target] = take || not_take;
        }
    }

    // Find the minimum absolute difference
    int mini = INT_MAX;
    for (int s1 = 0; s1 <= k; s1++) {
        if (dp[n - 1][s1]) {
            int s2 = totalSum - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}

T.C=O(n * k)
S.C=O(n * k)
  
