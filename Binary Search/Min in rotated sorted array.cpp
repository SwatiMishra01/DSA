https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
LEETCODE-153
------------------------------------
          BRUTE FORCE
------------------------------------
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            mini=min(mini,nums[i]);
        }
        return mini;
    }
};
T.C=O(N)
S.C=O(1)

---------------------------------------------------------------------------------------------------------------------------------
----------------------------------------
          BINARY SEARCH
----------------------------------------
class Solution {
public:
    int findMin(vector<int>& nums) {
         int n=nums.size();
        int s=0; 
        int e=n-1;
        int mini=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            //if left part is sorted
            if(nums[s]<=nums[mid]){
                   if(nums[s]<mini)
                   mini=nums[s];
                   s=mid+1; //eliminate left half
            }
            //right part is sorted
            else{
                 if(nums[mid]<mini)
                 mini=nums[mid];
                   e=mid-1; //eliminate right half
            }
        }
        return mini;
    }
};
T.C=O(N LOG N)
S.C=O(1)
