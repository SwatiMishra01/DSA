https://leetcode.com/problems/move-zeroes/
283-leetcode

  class Solution {
public:
    void moveZeroes(vector<int>& nums) {
int j=0;
        int n=nums.size();
        for (int i=0; i<n;i++){
        //sare non-zero element ko shuru m daaldo bhai
        
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }

        }
        //for zeros 
        for(int i=j; i<n; i++){
            nums[i]=0;
        }
    }
};
