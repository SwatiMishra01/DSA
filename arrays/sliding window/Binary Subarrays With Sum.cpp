https://leetcode.com/problems/binary-subarrays-with-sum/description/
LEETCODE-930

  -----------------
   OPTIMAL SOLUTION
  ------------------
  class Solution {
public:
 int f(vector<int>& nums, int goal){
    int l=0;
    int cnt=0;
    int sum=0;

    for(int r=0; r<nums.size(); ++r){
        sum+=nums[r];
        while(l<=r && sum>goal){
            sum-=nums[l];
            l++;
        }
        cnt+=(r-l+1);
    }
    return cnt;
 }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // edge case
        return f(nums, goal) - f(nums, goal - 1);
    }
};

T.C=O(N)
S.C=O(1)



  -----------------------------------------FOLLOW UP QUES----------------------------------------------------------
  COUNT NO. OF NICE SUBARRAYS
  ------------------------------------------------------------------------------------------------------------------
  Input: nums = [1,1,2,1,1], k = 3
  Output: 2
  Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
  --------------------------------------------------------------------------------------------------------------------

  
  https://leetcode.com/problems/count-number-of-nice-subarrays/description/
  LEETCODE-1248
  class Solution {
public:

int f(vector<int>& nums, int goal){
    int l=0;
    int sum=0;
    int cnt=0;
    for(int r=0; r<nums.size(); r++){
     sum+=(nums[r]%2);
     while(l<=r && sum>goal){
        sum-=(nums[l]%2);
        l++;
     }
     cnt+=(r-l+1);
    }
    return cnt;

}
    int numberOfSubarrays(vector<int>& nums, int k) {
        if (k==0)
        return 0;
        return f(nums,k)-f(nums,k-1);
    }
};
T.C=O(N)
S.C=O(1)
