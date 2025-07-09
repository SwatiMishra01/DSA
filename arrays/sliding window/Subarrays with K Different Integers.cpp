https://leetcode.com/problems/subarrays-with-k-different-integers/description/
LEETCODE- 992

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

  ---------------------------------------------
         APPROACH 1-> BRUTE FORCE
  ---------------------------------------------
  class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0; i<n; i++){
           map<int,int>mpp;
           for(int j=i; j<n; j++){
            mpp[nums[j]]++;
            if(mpp.size()==k)
            cnt+=1;
            else if(mpp.size()>k)
            break;
           }
        }
        return cnt;
    }
};
T.C=O(N^2)
S.C=O(N)



------------------------------------------------------
         APPROACH 2-> SLIDING WINDOW
  ---------------------------------------------------
  class Solution {
public:
int f(vector<int>& nums, int k){
    int l=0;
    int cnt=0;
   int r=0;
   map<int,int>mpp;
   while(r<nums.size()){
    mpp[nums[r]]++;
    while(mpp.size()>k){
        mpp[nums[l]]--;
        if(mpp[nums[l]]==0)
        mpp.erase(nums[l]);
        l++;
    }
    cnt+=r-l+1;
    r++;

   }
   return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //base case
        if(k==0)
        return 0;

        return f(nums,k)-f(nums,k-1);
    }
};

T.C=O(2N)
S.C=O(N)
