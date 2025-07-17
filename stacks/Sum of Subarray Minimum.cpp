https://leetcode.com/problems/sum-of-subarray-minimums/description/
LEETCODE-907

  --------------------------------
   APPROACH 1-> BRUTE FORCE
  --------------------------------

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        int MOD=1e9+7;
        //generating all subarrays
        for(int i=0; i<arr.size(); i++){
            int mini=arr[i];
            for(int j=i; j<arr.size(); j++){
                //updating mini
                mini=min(mini,arr[j]);
                //adding to the sum
                sum=(sum+mini)% MOD;
            }
        }
        return sum;
        
    }
};
T.C=O(N^2)
S.C=O(1)
----------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------------------
    APPROACH 2-> MONOTONIC STACK
  ---------------------------------------------------
  int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size(), MOD = 1e9 + 7;
    vector<int> left(n), right(n);
    stack<int> st;

    // Previous Less Element (strictly greater to left)
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (!st.empty() && arr[i] < arr[st.top()]) {
            count += left[st.top()];
            st.pop();
        }
        left[i] = count;
        st.push(i);
    }

    st = stack<int>(); // reset stack

    // Next Less Element (greater or equal to right)
    for (int i = n - 1; i >= 0; --i) {
        int count = 1;
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            count += right[st.top()];
            st.pop();
        }
        right[i] = count;
        st.push(i);
    }

    // Final sum
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum = (sum + (long long)arr[i] * left[i] * right[i]) % MOD;

    return sum;
}
T.C=O(N)
S.C=O(N)
