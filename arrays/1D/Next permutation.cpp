https://leetcode.com/problems/next-permutation/description/
leetcode-31
  class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        //Step 1: Find the break point:
        int indx=-1;
        for(int i=n-2; i>=0; i--){
           if( nums[i]<nums[i+1]){
           indx=i; // index i is the break point
           break;
           }
        }

        //base case If break point does not exist:
        if(indx==-1){
            reverse(nums.begin(),nums.end());
           return;
        }

        //swapping next greater element
        for(int i=n-1;i>indx; i-- ){
            if(nums[i]>nums[indx]){
            swap(nums[i],nums[indx]);
            break;
            }
        }

        //reverse remaining part of the array left
        reverse(nums.begin()+indx+1, nums.end());


    }
};
T.C=O(3N)
S.C=O(1)
