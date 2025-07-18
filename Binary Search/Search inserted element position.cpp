https://leetcode.com/problems/search-insert-position/description/
LEETCODE-35
  --------------------------
    BRUTE FORCE
  --------------------------

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        //if target is already present in array return that index
        for(int i=0; i<n; i++){
            if(nums[i]>=target)   return i;
        }
        return n; //if all elements are greater it would be inserted at last position
              
    }
};
T.C=O(N)
S.C=O(1)

---------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------
   BINARY SEARCH
  -----------------------------
  class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target) // if element found
            return mid;
            else if(nums[mid]>target)  e=mid-1;
            else s=mid+1;
        }
    return s;
    }
};
T.C=O(N LOG N)
S.C=O(1)
