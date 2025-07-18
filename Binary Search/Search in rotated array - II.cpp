https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
LEETCODE-81

--------------------------------
  BRUTE FORCE- LINEAR SEARCH
----------------------------------
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==target){
            return true;
            break;
            }
        }
        return false;
    }
};
T.C=O(N)
S.C=O(1)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------
         BINARY SEARCH
  ---------------------------------------
  class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0; 
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target) return true;

            //trim search part
            if(nums[s]==nums[mid]  && nums[mid]==nums[e]){
                s++;
                e--;
                continue;
            }



            //if left part is sorted
            if(nums[s]<=nums[mid]){
                   if(nums[s]<=target && target<=nums[mid])
                       e=mid-1; //eliminate right half
                   else s=mid+1; //eliminate left half
            }
            //right part is sorted
            else{
                 if(nums[mid]<=target && target<=nums[e])
                       s=mid+1; //eliminate left half
                   else 
                   e=mid-1; //eliminate right half
            }

            
        }
        return false;
    }
};
T.C=O(N LOG N)
S.C=O(1)
