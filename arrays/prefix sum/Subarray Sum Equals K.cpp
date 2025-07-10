https://leetcode.com/problems/subarray-sum-equals-k/description/
LEETCODE-560
  class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int start=0;
        int count=0;
        while(start<=nums.size()){
         int  totalSum=0;
        for(int i=start; i<nums.size(); i++){
         totalSum+=nums[i];
         if(totalSum==k){
            count++;
         }
        }
        start++;
        }
        return count;
    }
};
T.C=O(N^2)
S.C=O(1)
