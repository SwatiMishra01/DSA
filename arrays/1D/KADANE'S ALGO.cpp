https://leetcode.com/problems/maximum-subarray/description/
LEETCODE-
----------------------
  BRUTE FORCE  (TLE)
---------------------
  class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
         int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
    }
};
T.C=O(N^3)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------
        2 FOR LOOPS (TLE)
  ---------------------------------
  class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
         int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
         int sum = 0;
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
                sum += nums[j];
                 maxi = max(maxi, sum);
            }
           
        }

    return maxi;
    }
};
T.C=O(N^2)
S.C=O(1)
-------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------
  KADANE'S ALGO
  --------------------------
  class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += nums[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
    }
};
T.C=O(N)
S.C=O(1)
