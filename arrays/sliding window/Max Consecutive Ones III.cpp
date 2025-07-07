https://leetcode.com/problems/max-consecutive-ones-iii/description/
LEETCODE-1004

-----------------------------------
       BRUTE FORCE    (TLE)
-----------------------------------
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxLen=0;
        for(int i=0; i<n; i++){
            int zeros=0;
            for(int j=i; j<n; j++){
                if(nums[j]==0)
                zeros++;

                  if (zeros > k) break;

                int len = j - i + 1;
                maxLen = max(maxLen, len);
                }
               
            }
        return maxLen;
    }
};
T.C=O(N^2)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------
            SLIDING WINDOW
  ---------------------------------------
  class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0;
        int l=0;
        int r=0;
        int n=nums.size();
        int zeros=0;
        while(r<n){

            //zeros count
            if(nums[r]==0)
            zeros++;
         
         //shrink window if zeros exceed k
            while(zeros>k){
                if(nums[l]==0)
                zeros--;
                l++;
            }
  
         // update length
            if(zeros<=k){
                int len=r-l+1;
                maxLen=max(maxLen,len);
            }
            r++;

        }
        return maxLen;
    }
};
T.C=O(N)
S.C=O(1)
