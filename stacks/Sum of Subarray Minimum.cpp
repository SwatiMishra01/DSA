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
    APPROACH 2->
  ---------------------------------------------------
