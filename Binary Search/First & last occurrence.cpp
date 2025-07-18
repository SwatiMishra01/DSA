https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
LEETCODE-34

---------------------------------
          BRUTE FORCE
---------------------------------

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=-1;
        int last=-1;
     
     //first occurrence
     for(int i=0; i<n; i++){
        if(nums[i]==target){
        first=i;
        break;
        }
     }

     //last occurrence
     for(int i=n-1; i>=0; i--){
        if(nums[i]==target){
        last=i;
        break;
        }
     }
     return {first,last};
    }
};
T.C=O(2N)
S.C=O(1)

--------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------------
         BINARY SEARCH
  -------------------------------------------------
  class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();


        //first occurerence
        int s=0; int e=n-1; int first=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                first=mid;
                e=mid-1; //keep searching left
            }
            else if(nums[mid]<target)  s=mid+1;
            else  e=mid-1;
        }

        //last occurerence
         s=0;  e=n-1; int last=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                last=mid;
                s=mid+1; //keep searching right
            }
            else if(nums[mid]<target) s=mid+1;
            else  e=mid-1;
        }
    return {first,last};
    }

    
};
T.C=O(N LOG N)
S.C=O(1)
