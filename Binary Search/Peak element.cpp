https://leetcode.com/problems/find-peak-element/description/
LEETCODE-162

  -------------------------------------
         BRUTE FROCE
  --------------------------------------
  class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        //base cases
        if(n==1)  return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2])  return n-1;


        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
            return i;
        }
        return -1;
    }
};
T.C=O(N)
S.C=O(1)


---------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------------------
      BINARY SEARCH
  -----------------------------------------
  class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        //base cases
        if(n==1)  return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2])  return n-1;


        int s=1;
        int e=n-2;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])  return mid;

            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1])  s=mid+1;

            else e=mid-1;
        }
        return -1;
    }
};
T.C=O(NLOGN)
S.C=O(1)
