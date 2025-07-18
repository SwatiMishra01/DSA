https://leetcode.com/problems/binary-search/description/
LEETCODE-704

  -------------------------------
   ITERATIVE SOLUTION
  -------------------------------
  class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(target==nums[mid])  return mid;
           else if(nums[mid]<target)
            s=mid+1;
            else
            e=mid-1;


        }
        return -1;
    }
};

If a number n can be divided by 2 for x times:
	2^x = n
Therefore, x = logn (base is 2)
T.C=O(N LOG N)
S.C=O(1)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------------
          RECURSIVE SOLUTION
  ------------------------------------------
  class Solution {
public:
int binarySearch(int s, int e, vector<int>&nums, int target){
    //base case
    if(s>e)   return -1;
    int mid=(s+e)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target)  return binarySearch(mid+1,e,nums,target);
    else return binarySearch(s,mid-1,nums,target);
}
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binarySearch(0,n-1,nums,target);
    }
};
T.C=O(N LOG N)
S.C=O(1)
