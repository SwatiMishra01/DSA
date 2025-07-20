https://leetcode.com/problems/subarray-product-less-than-k/description/
LEETCODE-713

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0; //base case
        int totalCount=0;
        int product=1;
        int left=0;
        for(int right=0; right<nums.size(); right++){
            product*=nums[right];

           //shrink window
            while(product>=k){
              product/=nums[left];
              left++;
            }
            totalCount+=right-left+1; //window size
        }
        return totalCount;
    }
};
