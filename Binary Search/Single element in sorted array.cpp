https://leetcode.com/problems/single-element-in-a-sorted-array/description/
LEETCODE- 540
---------------------------
    BRUTE FORCE
--------------------------
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        //base case
        if(n==1) return nums[0];

        for(int i=0; i<n; i++){
         //check for first index
         if(i==0){
            if(nums[i]!=nums[i+1]) return nums[i];
         }
         //check for last index
         else if(i==n-1){
         if(nums[i]!=nums[i-1])   return nums[i];
         }
         //check for middle elements

         else {
           if( nums[i]!=nums[i+1]  && nums[i]!=nums[i-1])
           return nums[i];
            }
        }
        return -1;
    }
};
T.C=O(N)
S.C=O(1)
-----------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------
           USING XOR
  --------------------------------------
  class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { 
        //USING XOR
       // a ^ a = 0, XOR of two same numbers results in 0.
       // a ^ 0 = a, XOR of a number with 0 always results in that number.
       int n=nums.size();
       int ans=0;
       for(int i=0; i<n; i++){
        ans=ans^nums[i];
       }
       return ans;
        
    }
};
T.C=O(N)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------
          BINARY SEARCH
  --------------------------------------
  class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        //3 edge cases
        if(n==1) return nums[0]; //if there is only 1 element in array
        if(nums[0]!=nums[1])  return nums[0]; // if first element is unique
        if(nums[n-1]!=nums[n-2]) return nums[n-1]; //if last element is unique

        int s=0; int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])   return nums[mid];
            if(   (mid%2==1 && nums[mid]==nums[mid-1]) || 
                  (mid%2==0 && nums[mid]==nums[mid+1] )  )
            //eliminate left half
            s=mid+1;
            else 
            //eliminate right half
            e=mid-1;
        }
        return -1;

        
    }
};
